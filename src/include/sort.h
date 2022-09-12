
#ifndef SORT_H
#define SORT_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "log.h"

#define __COMPARATOR__ int (*comparator)(char *str_first, int len_first, char *str_second, int len_second)

//-----------------------------------------------------------------------------

struct Line
{
    char* begin_ptr;
    int   length;
};

//-----------------------------------------------------------------------------

void bubble_sort (Line lines_array[], int lines_amount, __COMPARATOR__);

void quick_sort(Line lines_array[], int low, int high, __COMPARATOR__);

int part_it(Line lines_array[], int low, int high, __COMPARATOR__);

int reverse_strcmp (char *str_first, int len_first, char *str_second, int len_second);

void skip_none_letters (char **str_ptr);

int forward_strcmp(char *str_first, int len_first, char *str_second, int len_second);

void swap_lines(Line *line_1, Line *line_2);

//-----------------------------------------------------------------------------

const char SKIP_SYMBOLS[] = {'.', ',', '!', '?', ';', ':', ' '};

#endif
