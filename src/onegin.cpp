
#include "include/onegin.h"

//-----------------------------------------------------------------------------

int start_onegin()
{
    FILE *input_file  = get_file ("data//input.txt", "r");
    FILE *output_file = get_file ("data//output.txt", "w");

    // return FILE_OPEN_ERROR;
    //

    // buffer
    char *main_str    = nullptr;
    int  symbols_read = 0;

    symbols_read = read_file (input_file, &main_str);

    // dynamically??
    Line lines_array[MAX_LINES] = {};

    // separate
    int line_amount = sepparate_lines (main_str, lines_array, symbols_read);

    trim_left (lines_array, line_amount);

    reverse_bubble_sort (lines_array, line_amount);

    print_lines (lines_array, line_amount);

    write_result_in_file (lines_array, line_amount, output_file);

    free   (main_str);
    fclose (input_file);
    fclose (output_file);

    return 1;
}


int sepparate_lines (char *main_str, Line lines_array[], int symbols_read)
{
    assert (main_str != NULL && lines_array != NULL && symbols_read > 0);

    int lines_indx = 0, cur_len = 0;

    char *cur_ptr = main_str;

    // char* end_ptr = curr_ptr + symbols_read;
    // for (; curr_ptr != end_ptr; curr_ptr++)

    for (int counter = 0; counter < symbols_read; counter++, cur_ptr++)
    {
        // curr_ptr++;
        cur_len++;
                                                                                             //01234
        if (*cur_ptr == '\n')                                                                //abcd\ndef\n
        {                                                                                    //12345
            if (cur_len > 0)
            {
                lines_array[lines_indx].begin_ptr = cur_ptr - cur_len + 1;
                lines_array[lines_indx].length    = cur_len;
                *cur_ptr = '\0';

                //??

                puts (lines_array[lines_indx].begin_ptr);

                lines_indx++;
                cur_len = 0;
            }
        }
    }


    return lines_indx; // + 1
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
            // printf ("Trimming left sym\n");
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


