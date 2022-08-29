
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

void bubble_sort (Line lines_array[], int lines_amount, int (*comparator)(char *str_first, int len_first, char *str_second, int len_second));

int reverse_strcmp (char *str_first, int len_first, char *str_second, int len_second);

void skip_none_letters (char **str_ptr);

int forward_strcmp(char *str_first, int len_first, char *str_second, int len_second);

//-----------------------------------------------------------------------------

const char SKIP_SYMBOLS[] = {'.', ',', '!', '?', ';', ':', ' '};

#endif
