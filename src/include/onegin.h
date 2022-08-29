#ifndef ONEGIN_H
#define ONEGIN_H

#include <assert.h>
//#include <TXlib.h>

#include "file_work.h"
#include "sort.h"

int start_onegin();

int separate_lines (char *buffer, Line lines_array[], int symbols_read);

void print_single_line (Line *cur_line);

void print_lines (Line lines_array[], int line_amount);

void trim_left (Line lines_array[], int lines_amount);

void trim_right (Line lines_array[], int lines_amount);

void write_result_in_file (Line lines_array[], int lines_amount, FILE* output_file);

void calloc_lines_array(char *buffer, Line **lines_array);

//-----------------------------------------------------------------------------

const int MAX_LINES = 1000;

//-----------------------------------------------------------------------------


#endif


