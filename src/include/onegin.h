#ifndef ONEGIN_H
#define ONEGIN_H

#include "file_work.h"
#include "sort.h"

int start_onegin();

int sepparate_lines (char *main_str, Line lines_array[], int symbols_read);

void print_single_line (Line *cur_line);

void print_lines          (Line lines_array[], int line_amount);

void clear_spaces         (Line lines_array[], int lines_amount);

void write_result_in_file (Line lines_array[], int lines_amount, FILE* output_file);

//-----------------------------------------------------------------------------

const int MAX_LINES = 1000;

//-----------------------------------------------------------------------------


#endif


