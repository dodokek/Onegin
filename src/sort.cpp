
#include "include/sort.h"

//-----------------------------------------------------------------------------

void bubble_sort (Line lines_array[], int lines_amount,
                  int (*comparator)(char *str_first, int len_first, char *str_second, int len_second))
{
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
}
/*

void quick_sort (Line lines_array[], int lines_amount,
                 int (*comparator)(char *str_first, int len_first, char *str_second, int len_second))
{

}

void quick_sort_loop(Line lines_array[], int lines_amount,
                     int (*comparator)(char *str_first, int len_first, char *str_second, int len_second),
                     int low, int high)
{
    if (low < high)
    {
        // find the pivot element such that
        // elements smaller than pivot are on left of pivot
        // elements greater than pivot are on right of pivot
        int pi = part_it(lines_array, low, high);

        // recursive call on the left of pivot
        quick_sort(lines_array, low, pi - 1);

        // recursive call on the right of pivot
        quick_sort(lines_array, pi + 1, high);
    }
}


int part_it(Line lines_array[], int low, int high,
            int (*comparator)(char *str_first, int len_first, char *str_second, int len_second))
{
  // select the rightmost element as pivot
  Line pivot = lines_array[high];

  // pointer for greater element
  int i = (low - 1);

  // traverse each element of the array
  // compare them with the pivot
  for (int j = low; j < high; j++)
  {
      if (comparator (lines_array[lap].begin_ptr, lines_array[lap].length, pivot.begin_ptr, pivot.length) <= 0)

      {
          // if element smaller than pivot is found
          // swap it with the greater element pointed by i
          i++;

          // swap element at i with element at j
          swap_lines(&lines_array[i], &lines_array[j]);
      }
  }

  // swap the pivot element with the greater element at i
  swap(&lines_array[i+1], &lines_array[high]);

  // return the partition point
  return (i + 1);
}
*/


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

