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
    MERGE_SORT       // Ha-ha, sometimes
};

//-----------------------------------------------------------------------------


int start_onegin();

int separate_lines (char *buffer, Line lines_array[], int symbols_read);

void print_single_line (Line *cur_line);

void print_lines (Line lines_array[], int line_amount);

void trim_left (Line lines_array[], int lines_amount);

void trim_right (Line lines_array[], int lines_amount);

void write_result_in_file (Line lines_array[], int lines_amount, FILE* output_file);

void calloc_lines_array(char *buffer, Line **lines_array, int symbols_read);

int change_input_name (int argc, const char* argv[], int pos);

int change_output_name (int argc, const char* argv[], int pos);

int choose_sort (int argc, const char* argv[], int pos);

void sort_and_write_in_file(Line lines_array[], int line_amount, ComparatorLink comparator, FILE* output_file);

int count_lines (char *buffer, int symbols_read);

//-----------------------------------------------------------------------------





#endif


