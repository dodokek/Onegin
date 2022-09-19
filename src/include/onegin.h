#ifndef ONEGIN_H
#define ONEGIN_H


#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <TXlib.h>

#include "file_work.h"
#include "sort.h"
#include "log.h"
#include "argument_proccessing.h"

enum sorting_modes
{
    BUBBLE_SORT = 1,
    QUICK_SORT  = 2,
    MERGE_SORT
};

//-----------------------------------------------------------------------------



struct Text
{
    char *buffer;
    int  symbols_amount;
    int  lines_amount;
    Line *lines_array;
};


int start_onegin();

int separate_lines (Text *MainText);

void print_single_line (Line *cur_line);

void print_lines (Line lines_array[], int line_amount);

void trim_left (Text *MainText);

void trim_right (Line lines_array[], int lines_amount);

void write_result_in_file (Text *MainText, FILE* output_file);

void calloc_lines_array (Text *MainText);

int change_input_name (int argc, const char* argv[], int pos);

int change_output_name (int argc, const char* argv[], int pos);

int choose_sort (int argc, const char* argv[], int pos);

void sort_and_write_in_file (Text *MainText, ComparatorPtr comparator, FILE* output_file);

int count_lines (char *buffer, int symbols_read);

void MainTextDestr(Text *self);

//-----------------------------------------------------------------------------




#endif


