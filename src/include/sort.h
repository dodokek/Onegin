
#ifndef SORT_H
#define SORT_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//-----------------------------------------------------------------------------

struct Line
{
    char* begin_ptr;
    int   length;
};

//-----------------------------------------------------------------------------

void bubble_sort (Line lines_array[], int lines_amount);

void reverse_bubble_sort (Line lines_array[], int lines_amount);

int reverse_strcmp (char *str_first, int length_first, char *str_second, int length_second);

void skip_none_letters (char **str_ptr);

//-----------------------------------------------------------------------------

const char SKIP_SYMBOLS[] = {'.', ',', '!', '?', ';', ':', ' ', 39, 22};

#endif
