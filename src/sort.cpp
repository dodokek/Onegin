
#include "include/sort.h"

//-----------------------------------------------------------------------------

void bubble_sort (void *ptr, size_t count, int size, VoidComp comp)
{
    __TRACKBEGIN__

    char* cur_ptr = (char*) ptr;

    printf ("Using bubble sort\n");

    for (int i = 0; i < int(count); i++)
    {
        for (int lap = 0; lap < int(count) - i - 1; lap++)
        {
            if (comp (cur_ptr + lap * size, cur_ptr + lap * size + 1))
            {
                swap_elems(cur_ptr + lap * size, cur_ptr + lap * size + 1);
            }
        }
    }

    __TRACKEND__
}

// I don't fucking know how the hell does this algorithm works, man.

void quick_sort(Line lines_array[], int low, int high, VoidComp comparator)
{
    __TRACKBEGIN__

    assert (lines_array != NULL && low >= 0);

    //printf ("Ah yes, quicksort\n");

    if (low < high)
    {
        int pi = part_it(lines_array, low, high, comparator);

        quick_sort(lines_array, low, pi - 1, comparator);

        quick_sort(lines_array, pi + 1, high, comparator);
    }

    __TRACKEND__
}


int part_it(Line lines_array[], int low, int high, VoidComp comparator)
{
    __TRACKBEGIN__
    __TRACKEND__

    Line pivot = lines_array[low];
    int i = low - 1;
    int j = high + 1;

    while (true)
    {
        do {
            i++;
        } while (comparator (lines_array + i, &pivot) < 0);

        do {
            j--;
        } while (comparator (lines_array + j, &pivot) > 0);

        if (i >= j)
            return j;

        swap_elems(&lines_array[i], &lines_array[j]);
    }

}


int forward_comparator(const void* ptr1, const void* ptr2)
{
    const Line* line_first  = (const Line*) ptr1;
    const Line* line_second = (const Line*) ptr2;

    return forward_strcmp (line_first->begin_ptr, 0, line_second->begin_ptr, 0);

}


int reverse_comparator(const void* ptr1, const void* ptr2)
{
    const Line* line_first  = (const Line*) ptr1;
    const Line* line_second = (const Line*) ptr2;

    return reverse_strcmp (line_first->begin_ptr, 0, line_second->begin_ptr, 0);

}


int reverse_strcmp (char *str_first, int len_first, char *str_second, int len_second)
{
    //printf("Strlen %d\n", len_first);

    if (len_first == 0)  return -1;
    if (len_second == 0) return 1;
    if (strcmp (str_first, str_second) == 0) return 0;

    char *cur_ptr_1 = str_first  + len_first  - 1;
    char *cur_ptr_2 = str_second + len_second - 1;

    skip_none_letters (&cur_ptr_1);
    skip_none_letters (&cur_ptr_2);

    while (cur_ptr_1 != str_first && cur_ptr_2 != str_second)
    {
        //printf("Comparing lines %s AND %s ", str_first, str_second);
        //printf("Comparing %c with %c \n", *cur_ptr_1, *cur_ptr_2);
        if (*cur_ptr_1 > *cur_ptr_2) return 1;
        if (*cur_ptr_1 < *cur_ptr_2) return -1;

        cur_ptr_1--, cur_ptr_2--;
    }

    return 0;

}


int forward_strcmp(char *str_first, int /*len_first*/, char *str_second, int /*len_second*/)
{

    for (int i = 0;;i++)
    {
        if (str_first[i] < str_second[i]) return -1;

        if (str_first[i] > str_second[i]) return 1;

        if (str_first[i] == '\0' && str_second[i] == '\0') break;
    }

    return 0;

}


void swap_elems(void *line_1, void *line_2)
{
    void *tmp = line_1;

    line_1 = line_2;

    line_2 = tmp;
}


void skip_none_letters (char **str_ptr)
{
    while (true)
    {
        if (isalpha(**str_ptr)) return;

        //printf("Trimming char %c\n", **str_ptr);
        (*str_ptr)--;
    }
}

