
#include "include/sort.h"

//-----------------------------------------------------------------------------

void bubble_sort (void *ptr, size_t count, int size, VoidComp comp)
{
    __TRACKBEGIN__

    char* cur_ptr = (char*) ptr;

    fprintf ( stderr, "Bubble sort\n");
    fprintf ( stderr, "Begin ptr %s, Line size %d\n", cur_ptr->begin_ptr, sizeof(Line));
    fprintf ( stderr, "Next ptr %p\n", cur_ptr + 1 * sizeof(Line));
    fprintf ( stderr, "Begin ptr %s, Line size %d\n", (cur_ptr + 1 * sizeof(Line))->begin_ptr, sizeof(Line));

    for (int i = 0; i < int(count); i++)
    {
        for (int lap = 0; lap < int(count) - i - 1; lap++)
        {
            if (comp (cur_ptr + lap * size, cur_ptr + (lap + 1) * size))
            {
                swap_elems (&(cur_ptr + lap * size), &(cur_ptr + (lap + 1) * size));
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

    printf ("Ah yes, quicksort\n");

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

        swap_elems(&(lines_array + i), &(lines_array + j));
    }

}


int forward_comparator(const void* ptr1, const void* ptr2)
{
    const Line* line_first  = (const Line*) ptr1;
    const Line* line_second = (const Line*) ptr2;

    printf("====\nFirst line: %s, Second line: %s\n====\n",
           line_first->begin_ptr, line_second->begin_ptr);

    return strcmp (line_first->begin_ptr, line_second->begin_ptr);

}


int reverse_comparator(const void* ptr1, const void* ptr2)
{
    assert(ptr1 != nullptr && ptr2 != nullptr);

    const Line* line_first  = (const Line*) ptr1;
    const Line* line_second = (const Line*) ptr2;

    //printf("Strlen %d\n", len_first);

    if (line_first->length == 0)  return -1;
    if (line_second->length == 0) return 1;
    if (strcmp (line_first->begin_ptr, line_second->begin_ptr) == 0) return 0;

    char *cur_ptr_1 = line_first->begin_ptr  + line_first->length  - 1;
    char *cur_ptr_2 = line_second->begin_ptr + line_second->length - 1;

    skip_not_letters (&cur_ptr_1);
    skip_not_letters (&cur_ptr_2);

    while (cur_ptr_1 != line_first->begin_ptr && cur_ptr_2 != line_second->begin_ptr)
    {
        if (*cur_ptr_1 > *cur_ptr_2) return 1;
        if (*cur_ptr_1 < *cur_ptr_2) return -1;

        cur_ptr_1--, cur_ptr_2--;
    }

    return 0;

}


//

int forward_strcmp(char *str_first, int /*len_first*/, char *str_second, int /*len_second*/)
{
    __TRACKBEGIN__

    assert(str_first != NULL && str_second != NULL);



    __TRACKEND__

    return 0;

}


void swap_elems(void **line_1, void **line_2)
{
    __TRACKBEGIN__

    void **tmp = line_1;

    *line_1 = *line_2;

    *line_2 = *tmp;

    __TRACKEND__
}


void skip_not_letters (char **str_ptr)
{
    while (true)
    {
        if (isalpha(**str_ptr)) return;

        (*str_ptr)--;
    }
}

