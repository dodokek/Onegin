
#include "include/onegin.h"


int start_onegin(GeneralVariables *MainVariables)
{
    FILE *input_file  = get_file (MainVariables->input_file_name, "r");
    FILE *output_file = get_file (MainVariables->output_file_name, "w");

    assert(input_file != nullptr && output_file != nullptr);

    Text MainText = {};

    read_file (input_file, &MainText);

    calloc_lines_array (&MainText);

    separate_lines (&MainText);

    trim_left (&MainText);

    write_result_in_file   (&MainText, output_file);

    sort_and_write_in_file (&MainText, forward_strcmp, output_file, MainVariables->sort_mode);

    sort_and_write_in_file (&MainText, reverse_strcmp, output_file, MainVariables->sort_mode);

    MainTextDestr (&MainText);

    fclose (input_file);
    fclose (output_file);

    return 1;
}


void calloc_lines_array (Text *MainText)

{
    assert (MainText->buffer != nullptr);

    __TRACKBEGIN__

    MainText->lines_array = (Line*) calloc (sizeof(Line), count_lines (MainText->buffer, MainText->symbols_amount));

    __TRACKEND__
    return;
}


int count_lines (char *buffer, int symbols_read)
{
    char *cur_ptr = buffer;
    char *end_ptr = cur_ptr + symbols_read;

    int line_counter = 0;

    for (; cur_ptr != end_ptr; cur_ptr++)
    {
        if (*cur_ptr == '\n') line_counter++;
        printf("%c", *cur_ptr);
    }

    return line_counter;
}


void sort_and_write_in_file (Text *MainText, ComparatorPtr comparator, FILE* output_file, int sort_mode)
{
    __TRACKBEGIN__

    switch (sort_mode)
    {
        case BUBBLE_SORT:
            bubble_sort (MainText->lines_array, MainText->lines_amount, sizeof(Line), comparator);
            break;

        case QUICK_SORT:
            //quick_sort  (lines_array, 0, line_amount - 1, comparator);
            qsort (MainText->lines_array, MainText->lines_amount, sizeof(Line), comparator);
            break;

        default:
            break;
    }

    print_lines (MainText->lines_array, MainText->lines_amount);

    write_result_in_file (MainText, output_file);

    __TRACKEND__
}


void write_result_in_file (Text *MainText, FILE* output_file)
{
    for (int i = 0; i < MainText->lines_amount; i++)
    {
        fputs (MainText->lines_array[i].begin_ptr, output_file);
        fputc ('\n', output_file);
    }

    fputs ("================================================================================\n", output_file);
}


int separate_lines (Text *MainText)

{
    assert (MainText->buffer != nullptr);
    assert (MainText->lines_array != NULL);
    assert (MainText->symbols_amount > 0);

    int lines_indx = 0, cur_len = 0;

    char *cur_ptr = MainText->buffer;

    char *end_ptr = cur_ptr + MainText->symbols_amount;

    for (; cur_ptr != end_ptr; cur_ptr++)
    {
        cur_len++;
                                                                                             //01234
        if (*cur_ptr == '\n')                                                                //abcd\ndef\n
        {                                                                                    //\n
            if (cur_len > 1) // ignore "\n"
            {
                MainText->lines_array[lines_indx].begin_ptr = cur_ptr - cur_len + 1;
                MainText->lines_array[lines_indx].length    = cur_len;
                *cur_ptr = '\0';
                lines_indx++;
            }

            cur_len = 0;
        }
    }

    MainText->lines_amount = lines_indx;

    return 1;
}


void print_lines (Line lines_array[], int lines_amount)
{
    assert (lines_array != NULL && lines_amount > 0);

    for (int i = 0; i < lines_amount; i++)
    {
        //printf("%.*s", lines_array[i].length, lines_array[i].begin_ptr);
        //printf ("Line length %d\n", lines_array[i].length);
        puts (lines_array[i].begin_ptr);

    }
}


void trim_left (Text *MainText)

{
    printf ("Lines amount: %d\n", MainText->lines_amount);

    for (int i = 0; i < (MainText->lines_amount); i++)
    {
        while (!isalpha (*(MainText->lines_array[i].begin_ptr)))
        {
            MainText->lines_array[i].begin_ptr++;
        }
    }
}


void MainTextDestr (Text *self)
{
    free (self->buffer);
    free (self->lines_array);
}






