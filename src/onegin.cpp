
#include "include/onegin.h"

//-----------------------------------------------------------------------------

char INPUT_NAME[50]   = "data//input.txt";

char OUTPUT_NAME[50]  = "data//output.txt";

char SORTING_MODE[50] = "qsort";

//-----------------------------------------------------------------------------

int start_onegin()
{
    FILE *input_file  = get_file (INPUT_NAME, "r");
    FILE *output_file = get_file (OUTPUT_NAME, "w");

    assert(input_file != nullptr && output_file != nullptr);

    // return FILE_OPEN_ERROR;

    char *buffer = nullptr;
    int  symbols_read = 0;

    symbols_read = read_file (input_file, &buffer);

    Line *lines_array = nullptr;

    calloc_lines_array(buffer, &lines_array, symbols_read);

    int line_amount = separate_lines (buffer, lines_array, symbols_read);

    trim_left (lines_array, line_amount);

    //bubble_sort (lines_array, line_amount, forward_strcmp);

    quick_sort (lines_array, 0, line_amount - 1, forward_strcmp);

    print_lines (lines_array, line_amount);

    write_result_in_file (lines_array, line_amount, output_file);

    free   (buffer);
    free   (lines_array);
    fclose (input_file);
    fclose (output_file);

    return 1;
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
        while (strchr(SKIP_SYMBOLS, *lines_array[i].begin_ptr))
        {
            lines_array[i].begin_ptr++;
            //printf ("Trimming left sym\n");
        }
    }
}



void write_result_in_file (Line lines_array[], int lines_amount, FILE* output_file)
{
    for (int i = 0; i < lines_amount; i++)
    {
        fputs (lines_array[i].begin_ptr, output_file);
        fputc ('\n', output_file);
    }
}


void calloc_lines_array(char *buffer, Line **lines_array, int symbols_read)
{
    assert (buffer != nullptr);

    __TRACKBEGIN__
    int line_counter = 0;

    char *cur_ptr = buffer;
    char *end_ptr = cur_ptr + symbols_read;

    for (;cur_ptr != end_ptr; cur_ptr++)
    {
        if (*cur_ptr == '\n') line_counter++;
        printf("%c", *cur_ptr);
    }

    *lines_array = (Line*) calloc(sizeof(Line), line_counter);
    __TRACKEND__
    return;
}


int change_input_name (int argc, const char* argv[], int pos)
{
    assert(argc > 0 && argv != NULL && pos >= 0);

    __TRACKBEGIN__

    int argument_indx = 0;

    for (int argc_pos = pos + 1; argc_pos < argc; argc_pos++, argument_indx++)
    {
        if (argv[argc_pos][0] != '-')
        {
            switch (argument_indx)
            {
                case 0:
                    puts(argv[argc_pos]);
                    strcpy(INPUT_NAME, argv[argc_pos]);
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

    return argument_indx;
}


int change_output_name (int argc, const char* argv[], int pos)
{
    assert(argc > 0 && argv != NULL && pos >= 0);

    __TRACKBEGIN__

    int argument_indx = 0;

    for (int argc_pos = pos + 1; argc_pos < argc; argc_pos++, argument_indx++)
    {
        if (argv[argc_pos][0] != '-')
        {
            switch (argument_indx)
            {
                case 0:
                    strcpy(OUTPUT_NAME, argv[argc_pos]);
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

    return argument_indx;
}



