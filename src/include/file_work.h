
#ifndef FILE_WORK_H
#define FILE_WORK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//-----------------------------------------------------------------------------

const char default_input_name[]  = "data//input.txt";
const char default_output_name[] = "data//output.txt";

//-----------------------------------------------------------------------------

FILE* get_file  (const char file_name[], const char* mode);

char* read_file (FILE* file);

#endif