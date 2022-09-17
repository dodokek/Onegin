
#ifndef SORT_H
#define SORT_H

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#include "log.h"

typedef int (*ComparatorLink)(char *str_first, int len_first, char *str_second, int len_second);
typedef int (*VoidComp)(const void *, const void *);

//-----------------------------------------------------------------------------

struct Line
{
    char* begin_ptr;
    int   length;
};

//-----------------------------------------------------------------------------

void bubble_sort (void *ptr, size_t count, int size, VoidComp comp);

void quick_sort (Line lines_array[], int low, int high, VoidComp comparator);

int part_it (Line lines_array[], int low, int high, VoidComp comparator);

int reverse_strcmp(char *str_first, int len_first, char *str_second, int len_second);

void skip_not_letters(char **str_ptr);

int forward_strcmp(char *str_first, int len_first, char *str_second, int len_second);

void swap_elems(void **line_1, void **line_2);

int forward_comparator(const void* ptr1, const void* ptr2);

int reverse_comparator(const void* ptr1, const void* ptr2);

//-----------------------------------------------------------------------------

#endif
