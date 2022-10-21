#ifndef ONEGIN_H
#define ONEGIN_H

#include <TXlib.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <sys/stat.h>


#include "file_work.h"
#include "sort.h"
#include "log.h"
#include "argument_proccessing.h"

//-----------------------------------------------------------------------------

struct Text
{
    char *buffer;
    int  symbols_amount;
    int  lines_amount;
    Line *lines_array;
};


int start_onegin (GeneralVariables *MainVariables);

int separate_lines (Text *MainText);

void print_single_line (Line *cur_line);

void print_lines (Line lines_array[], int line_amount);

void trim_left (Text *MainText);

void trim_right (Line lines_array[], int lines_amount);

void write_result_in_file (Text *MainText, FILE* output_file);

void calloc_lines_array (Text *MainText);

void sort_and_write_in_file (Text *MainText, ComparatorPtr comparator, FILE* output_file, int sort_mode);

int count_lines (char *buffer, int symbols_read);

void MainTextDestr(Text *self);

void sort_and_write_in_file(Line lines_array[], int line_amount, VoidComp comparator, FILE* output_file);

void get_stat_parse_file (char *buffer, Line **lines_array, int symbols_read, int *line_amount, struct stat *InputStat, FILE *analysed_file);

//-----------------------------------------------------------------------------




#endif


