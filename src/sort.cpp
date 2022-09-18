
#include "include/sort.h"

//-----------------------------------------------------------------------------

void bubble_sort (void *ptr, int counter, int size_, ComparatorLink comparator)
{
    __TRACKBEGIN__

    printf ("Using bubble sort\n");

    char *arr = (char*) ptr;


    for (int i = 0; i < counter; i++)
    {
        for (int lap = 0; lap < counter - i - 1; lap++)
        {
            void *elem1 = arr + size_ * lap;
            void *elem2 = arr + size_ * (lap + 1);

            if (comparator (elem1, elem2) > 0)
            {
                swap_elems(elem1, elem2);
            }
        }
    }

    __TRACKEND__
}

// I don't fucking know how the hell does this algorithm works, man.

void quick_sort(Line lines_array[], int low, int high, ComparatorLink comparator)
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


int part_it(Line lines_array[], int low, int high, ComparatorLink comparator)
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


int reverse_strcmp (const void *ptr1, const void *ptr2)
{
    Line *Line_first = (Line*) ptr1;
    Line *Line_second = (Line*) ptr2;

    char *str_first  = Line_first->begin_ptr;
    char *str_second = Line_second->begin_ptr;
    int  len_first   = Line_first->length;
    int  len_second   = Line_second->length;

    if (len_first == 0)  return -1;
    if (len_second == 0) return 1;

    char *cur_ptr_1 = str_first  + len_first  - 1;
    char *cur_ptr_2 = str_second + len_second - 1;

    skip_none_letters (&cur_ptr_1);
    skip_none_letters (&cur_ptr_2);

    while (cur_ptr_1 != str_first && cur_ptr_2 != str_second)
    {
        if (*cur_ptr_1 > *cur_ptr_2) return 1;
        if (*cur_ptr_1 < *cur_ptr_2) return -1;

        cur_ptr_1--, cur_ptr_2--;

        continue;
    }

    return 0;
}

void skip_none_letters (char **str_ptr)
{
    while (true)
    {
        if (!isalpha(**str_ptr))
        {
            //printf("Trimming char %c\n", **str_ptr);
            (*str_ptr)--;
            continue;
        }
        return;
    }
}


int forward_strcmp (const void *ptr1, const void *ptr2)

{
    Line *Line_first  = (Line*) ptr1;
    Line *Line_second = (Line*) ptr2;

    return strcmp(Line_first->begin_ptr, Line_second->begin_ptr);
}


void swap_elems(void *ptr1, void *ptr2)
{
    Line *Line1 = (Line*) ptr1;
    Line *Line2 = (Line*) ptr2;

    Line *tmp = Line1;

    *Line1 = *Line2;

    *Line2 = *tmp;
}

