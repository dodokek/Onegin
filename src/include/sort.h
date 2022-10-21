
#ifndef SORT_H
#define SORT_H

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#include "log.h"

<<<<<<< HEAD
typedef int (*ComparatorLink)(char *str_first, int len_first, char *str_second, int len_second);
typedef int (*VoidComp)(const void *, const void *);
=======
>>>>>>> normalversion

//-----------------------------------------------------------------------------

struct Line
{
    char* begin_ptr;
    int   length;
};

//-----------------------------------------------------------------------------

<<<<<<< HEAD
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

=======
typedef int (*ComparatorPtr)(const void *prt1, const void *ptr2);

//-----------------------------------------------------------------------------

void bubble_sort (void *ptr, int counter, int size_, ComparatorPtr comparator);

void quick_sort (Line lines_array[], int low, int high, ComparatorPtr comparator);

int part_it (Line lines_array[], int low, int high, ComparatorPtr comparator);

int reverse_strcmp (const void *ptr1, const void *ptr2);

void skip_none_letters (char **str_ptr);

int forward_strcmp (const void *ptr1, const void *ptr2);

void swap_elems (void *ptr1, void *ptr2, size_t len);

//-----------------------------------------------------------------------------

>>>>>>> normalversion
#endif
