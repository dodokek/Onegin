
#include "include/onegin.h"

//-----------------------------------------------------------------------------

int start_onegin()
{
    FILE *input_file  = get_file ("data//input.txt", "r");
    FILE *output_file = get_file ("data//output.txt", "w");

    char *main_str = nullptr;

    main_str = read_file (input_file);

    Line lines_array[MAX_LINES] = {};

    int line_amount = sepparate_lines (main_str, lines_array);

    clear_spaces (lines_array, line_amount);

    bubble_sort  (lines_array, line_amount);

    print_lines  (lines_array, line_amount);

    write_result_in_file (lines_array, line_amount, output_file);

    free   (main_str);
    fclose (input_file);
    fclose (output_file);

    return 1;
}


int sepparate_lines (char *main_str, Line lines_array[])
{
    int current_length = 0;
    int lines_indx     = 0;
    int line_counter   = 1;

    lines_array[lines_indx].begin_ptr = main_str;

    for(char *ptr = main_str; *ptr != EOF; ptr++)
    {
        current_length++;

        if (*ptr == '\n' || (*ptr == '\r' && *(ptr+1) == EOF))
        {
            *ptr = '\0';

            lines_indx++;
            line_counter++;

            ptr++;

            lines_array[lines_indx].length    = current_length;
            lines_array[lines_indx].begin_ptr = ptr;

            current_length = 0;
        }
    }

    return line_counter;
}


void print_lines (Line lines_array[], int lines_amount)
{
    printf ("%d\n", lines_amount);

    for (int i = 0; i < lines_amount; i++)
    {
        puts (lines_array[i].begin_ptr);
    }
}


void clear_spaces (Line lines_array[], int lines_amount)
{
    printf ("Lines amount: %d\n", lines_amount);

    for (int i = 0; i < lines_amount; i++)
    {
        while(*lines_array[i].begin_ptr == ' ') lines_array[i].begin_ptr++, printf ("Deleting space\n");
    }
}


void bubble_sort (Line lines_array[], int lines_amount)
{
    for (int i = 0; i < lines_amount; i++)
    {
        for (int lap = 0; lap < lines_amount - i - 1; lap++)
        {
            if (strcmp (lines_array[lap].begin_ptr, lines_array[lap+1].begin_ptr) > 0)
            {
                Line tmp = lines_array[lap];

                lines_array[lap] = lines_array[lap + 1];

                lines_array[lap + 1] = tmp;
            }
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

