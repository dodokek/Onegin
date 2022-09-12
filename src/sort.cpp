
#include "include/sort.h"

//-----------------------------------------------------------------------------

void bubble_sort (Line lines_array[], int lines_amount, __COMPARATOR__)
{
    __TRACKBEGIN__
    printf ("Using bubble sort\n");
    for (int i = 0; i < lines_amount; i++)
    {
        for (int lap = 0; lap < lines_amount - i - 1; lap++)
        {
            if (comparator (lines_array[lap].begin_ptr,   lines_array[lap].length,
                            lines_array[lap+1].begin_ptr, lines_array[lap+1].length) > 0)
            {
                swap_lines(&lines_array[lap], &lines_array[lap+1]);
            }
        }
    }
    __TRACKEND__
}

// I don't fucking know how the hell does this algorithm works man.
void quick_sort(Line lines_array[], int low, int high, __COMPARATOR__)
{
    __TRACKBEGIN__
    assert (lines_array != NULL && low >= 0);

    printf ("Ah yes, quicksort\n");

    if (low < high)
    {
        int pi = part_it(lines_array, low, high, comparator);

        quick_sort(lines_array, low, pi - 1, comparator);

        quick_sort(lines_array, pi + 1, high, comparator);
    }
    __TRACKEND__
}


int part_it(Line lines_array[], int low, int high, __COMPARATOR__)
{
    __TRACKBEGIN__
    assert (lines_array != NULL && low >= 0);

    Line pivot = lines_array[high];

    int i = (low - 1);

    for (int j = low; j < high; j++)
    {
        if (comparator (lines_array[j].begin_ptr, lines_array[j].length, pivot.begin_ptr, pivot.length) <= 0)

        {
            i++;

            swap_lines(&lines_array[i], &lines_array[j]);
        }
    }

    swap_lines(&lines_array[i+1], &lines_array[high]);

    __TRACKEND__

    return (i + 1);
}



int reverse_strcmp (char *str_first, int len_first, char *str_second, int len_second)
{
    //printf("Strlen %d\n", length_first);

    if (len_first == 0)  return -1;
    if (len_second == 0) return 1;

    char *cur_ptr_1 = str_first  + len_first  - 1;
    char *cur_ptr_2 = str_second + len_second - 1;

    skip_none_letters (&cur_ptr_1);
    skip_none_letters (&cur_ptr_2);

    while (cur_ptr_1 != str_first)
    {
        if (cur_ptr_1 > cur_ptr_2) return 1;
        if (cur_ptr_1 < cur_ptr_2) return -1;

        cur_ptr_1--, cur_ptr_2--;

        continue;
    }
    return 0;
}

void skip_none_letters (char **str_ptr)
{
    while (true)
    {
        if (strchr (SKIP_SYMBOLS, **str_ptr))
        {
            printf("Trimming char %c\n", **str_ptr);
            (*str_ptr)--;
            continue;
        }
        return;
    }
}


int forward_strcmp(char *str_first, int len_first, char *str_second, int len_second)
{

    for (int i = 0;;i++)
    {
        if (str_first[i] < str_second[i]) return -1;

        if (str_first[i] > str_second[i]) return 1;

        if (str_first[i] == '\0' && str_second[i] == '\0') break;
    }

    return 0;
}


void swap_lines(Line *line_1, Line *line_2)
{
    Line tmp = *line_1;

    *line_1 = *line_2;

    *line_2 = tmp;
}

