
#include "include/sort.h"

//-----------------------------------------------------------------------------

void bubble_sort (Line lines_array[], int lines_amount)
{
    for (int i = 0; i < lines_amount; i++)
    {
        for (int lap = 0; lap < lines_amount - i - 1; lap++)
        {
            //printf("%s %s %d\n", lines_array[lap].begin_ptr, lines_array[lap+1].begin_ptr,  reverse_strcmp (lines_array[lap].begin_ptr,   lines_array[lap].length,
            //                                    lines_array[lap+1].begin_ptr, lines_array[lap+1].length));

            if (reverse_strcmp (lines_array[lap].begin_ptr,   lines_array[lap].length,
                                lines_array[lap+1].begin_ptr, lines_array[lap+1].length) > 0)
            {
                Line tmp = lines_array[lap];

                lines_array[lap] = lines_array[lap + 1];

                lines_array[lap + 1] = tmp;
            }
        }
    }
}


int reverse_strcmp (char *str_first, int length_first, char *str_second, int length_second)
{
    //printf("Strlen %d\n", length_first);

    if (length_first == 0)  return -1;
    if (length_second == 0) return 1;

    char *cur_ptr_1 = str_first  + length_first  - 1;
    char *cur_ptr_2 = str_second + length_second - 1;

    skip_none_letters (cur_ptr_1);
    skip_none_letters (cur_ptr_2);

    while (cur_ptr_1 != str_first)
    {
        if (cur_ptr_1 > cur_ptr_2) return 1;
        if (cur_ptr_1 < cur_ptr_2) return -1;

        cur_ptr_1--, cur_ptr_2--;

        continue;
    }
    return 0;
}

void skip_none_letters(char *str_ptr)
{
    for (int i = 0; i < strlen(SKIP_SYMBOLS); i++)
    {
        if (*str_ptr == SKIP_SYMBOLS[i]) str_ptr--;
    }
}

