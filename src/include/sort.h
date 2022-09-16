
#ifndef SORT_H
#define SORT_H

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#include "log.h"

typedef int (*ComparatorLink)(char *str_first, int len_first, char *str_second, int len_second);

//-----------------------------------------------------------------------------

struct Line
{
    char* begin_ptr;
    int   length;
};

//-----------------------------------------------------------------------------

void bubble_sort (Line lines_array[], int lines_amount, ComparatorLink comparator);

void quick_sort(Line lines_array[], int low, int high, ComparatorLink comparator);

int part_it(Line lines_array[], int low, int high, ComparatorLink comparator);

int reverse_strcmp (char *str_first, int len_first, char *str_second, int len_second);

void skip_none_letters (char **str_ptr);

int forward_strcmp(char *str_first, int len_first, char *str_second, int len_second);

void swap_lines(Line *line_1, Line *line_2);

//-----------------------------------------------------------------------------

const char SKIP_SYMBOLS[] = {'.', ',', '!', '?', ';', ':', ' '};

#endif
