
#include "include/onegin.h"

//-----------------------------------------------------------------------------

char INPUT_NAME[50]   = "data//input.txt";

char OUTPUT_NAME[50]  = "data//output.txt";

int  SORT_MODE        = QUICK_SORT;

//-----------------------------------------------------------------------------

int start_onegin()
{
    FILE *input_file  = get_file (INPUT_NAME, "r");
    FILE *output_file = get_file (OUTPUT_NAME, "w");

    assert(input_file != nullptr && output_file != nullptr);

    char *buffer = nullptr;
    int  symbols_read = 0;
    int line_amount = 0;               // Amount of lines, excluding "\n" lines.

    symbols_read = read_file (input_file, &buffer);

    Line *lines_array = nullptr;

    calloc_lines_array(buffer, &lines_array, symbols_read);

    line_amount = separate_lines (buffer, lines_array, symbols_read);

    trim_left (lines_array, line_amount);

    write_result_in_file   (lines_array, line_amount, output_file);

    sort_and_write_in_file (lines_array, line_amount, forward_strcmp, output_file);

    sort_and_write_in_file (lines_array, line_amount, reverse_strcmp, output_file);

    print_lines (lines_array, line_amount);

    write_result_in_file (lines_array, line_amount, output_file);

    free   (buffer);
    free   (lines_array);
    fclose (input_file);
    fclose (output_file);

    return 1;
}


void calloc_lines_array(char *buffer, Line **lines_array, int symbols_read)
{
    assert (buffer != nullptr);

    __TRACKBEGIN__

    *lines_array = (Line*) calloc(sizeof(Line), count_lines (buffer, symbols_read));

    __TRACKEND__
    return;
}


int count_lines (char *buffer, int symbols_read)
{
    char *cur_ptr = buffer;
    char *end_ptr = cur_ptr + symbols_read;

    int line_counter = 0;

    for (;cur_ptr != end_ptr; cur_ptr++)
    {
        if (*cur_ptr == '\n') line_counter++;
        printf("%c", *cur_ptr);
    }

    return line_counter;
}


void sort_and_write_in_file(Line lines_array[], int line_amount, ComparatorLink comparator, FILE* output_file)
{
    __TRACKBEGIN__

    switch (SORT_MODE)
    {
        case BUBBLE_SORT:
            bubble_sort (lines_array, line_amount /*, sizeof(Line)*/, comparator);
            break;

        case QUICK_SORT:
            quick_sort  (lines_array, 0, line_amount - 1, comparator);
            //qsort (lines_array, line_amount, sizeof(Line), comparator);
            break;

        default:
            break;
    }

    print_lines (lines_array, line_amount);

    write_result_in_file (lines_array, line_amount, output_file);

    __TRACKEND__
}


void write_result_in_file (Line lines_array[], int lines_amount, FILE* output_file)
{
    for (int i = 0; i < lines_amount; i++)
    {
        fputs (lines_array[i].begin_ptr, output_file);
        fputc ('\n', output_file);
    }

    fputs ("================================================================================", output_file);
}


int separate_lines (char *buffer, Line lines_array[], int symbols_read)
{
    assert (buffer != nullptr);
    assert (lines_array != NULL);
    assert (symbols_read > 0);

    int lines_indx = 0, cur_len = 0;

    char *cur_ptr = buffer;

    char* end_ptr = cur_ptr + symbols_read;

    for (;cur_ptr != end_ptr; cur_ptr++)
    {
        cur_len++;
                                                                                             //01234
        if (*cur_ptr == '\n')                                                                //abcd\ndef\n
        {                                                                                    //\n
            if (cur_len > 1)                                                                 //abacaba
            {
                lines_array[lines_indx].begin_ptr = cur_ptr - cur_len + 1;
                lines_array[lines_indx].length    = cur_len;
                *cur_ptr = '\0';
                lines_indx++;
            }
            cur_len = 0;
        }
    }


    return lines_indx;
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


void trim_left (Line lines_array[], int lines_amount)
{
    printf ("Lines amount: %d\n", lines_amount);

    for (int i = 0; i < lines_amount; i++)
    {
        while (!isalpha(*lines_array[i].begin_ptr))
        {
            lines_array[i].begin_ptr++;
            //printf ("Trimming left sym\n");
        }
    }
}





int change_input_name (int argc, const char* argv[], int pos)
{
    assert(argc > 0 && argv != NULL && pos >= 0);

    __TRACKBEGIN__

    int skip_args = 0;

    for (int arg_indx = pos + 1; arg_indx < argc; arg_indx++, skip_args++)
    {
        if (argv[arg_indx][0] != '-')
        {
            switch (skip_args)
            {
                case 0:
                    puts(argv[arg_indx]);
                    strcpy(INPUT_NAME, argv[arg_indx]);
                    break;

                default:
                    printf ("Too much additional arguments\n");
            }
        }
        else
        {
            break;
        }
    }

    __TRACKEND__

    return skip_args;
}


int change_output_name (int argc, const char* argv[], int pos)
{
    assert(argc > 0 && argv != NULL && pos >= 0);

    __TRACKBEGIN__

    int skip_args = 0;

    for (int arg_indx = pos + 1; arg_indx < argc; arg_indx++, skip_args++)
    {
        if (argv[arg_indx][0] != '-')
        {
            switch (skip_args)
            {
                case 0:
                    strcpy(OUTPUT_NAME, argv[arg_indx]);
                    break;

                // Here i would add cases for different types of input

                default:
                    printf ("Too much additional arguments\n");
            }
        }
        else
        {
            break;
        }
    }

    __TRACKEND__

    return skip_args;
}


int choose_sort (int argc, const char* argv[], int pos)
{
    assert(argc > 0 && argv != NULL && pos >= 0);

    __TRACKBEGIN__

    int skip_args = 0;

    for (int arg_indx = pos + 1; arg_indx < argc; arg_indx++, skip_args++)
    {
        if (argv[arg_indx][0] != '-')
        {
            switch (skip_args)
            {
                case 0:
                    if (strcmp ("2", argv[arg_indx])) SORT_MODE = BUBBLE_SORT;
                    if (strcmp ("1", argv[arg_indx])) SORT_MODE = QUICK_SORT;
                    break;

                default:
                    printf ("Too much additional arguments\n");
            }
        }
        else
        {
            break;
        }
    }

    __TRACKEND__

    return skip_args;
}



