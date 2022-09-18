
#ifndef SORT_H
#define SORT_H

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#include "log.h"


//-----------------------------------------------------------------------------

struct Line
{
    char* begin_ptr;
    int   length;
};

//-----------------------------------------------------------------------------

typedef int (*ComparatorLink)(const void *prt1, const void *ptr2);

//-----------------------------------------------------------------------------

void bubble_sort (void *ptr, int counter, int size_, ComparatorLink comparator);

void quick_sort (Line lines_array[], int low, int high, ComparatorLink comparator);

int part_it (Line lines_array[], int low, int high, ComparatorLink comparator);

int reverse_strcmp (const void *ptr1, const void *ptr2);

void skip_none_letters (char **str_ptr);

int forward_strcmp (const void *ptr1, const void *ptr2);

void swap_elems (void *ptr1, void *ptr2);

//-----------------------------------------------------------------------------

#endif
