
#ifndef FILE_WORK_H
#define FILE_WORK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "onegin.h"

//-----------------------------------------------------------------------------

<<<<<<< HEAD
FILE* get_file  (const char* file_name, const char* mode);
=======
static const char default_input_name[]  = "data//input.txt";
static const char default_output_name[] = "data//output.txt";
>>>>>>> normalversion

//-----------------------------------------------------------------------------

FILE* get_file (const char file_name[], const char* mode);

int read_file (FILE* file, struct Text *MainText);

#endif
