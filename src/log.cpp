
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Global/Const-----------------------------------------------------------------
// static

FILE* LOG_FILE = nullptr;

int LOG_LEVEL = 9;

const char DEFAULT_LOG_NAME[] = "data//log.txt";

char ACTIVE_LOGFILE_NAME[] = "log.txt";

int SPACING = 0;

//Global/Const-----------------------------------------------------------------

#include "include/log.h"

//-----------------------------------------------------------------------------

void add_tree_level (const char* func_name)
{
    const int tab_size = 4;

    fprintf    (LOG_FILE, "%25s:%03d ", __FILE__, __LINE__);
    fputc      ('|', LOG_FILE);
    put_spaces (SPACING++ * tab_size);

    LOG_FUNC   ("%s >>>\n", func_name);
}


void substract_tree_level (const char* func_name)
{
    const int tab_size = 4;

    fprintf    (LOG_FILE, "%25s:%03d ", __FILE__, __LINE__);
    fputc      ('|', LOG_FILE);
    put_spaces (--SPACING * tab_size);

    LOG_FUNC   ("%s <<<\n", func_name);
}


bool get_log_file (char file_name[])
{
    atexit (&finish_log);

    if (file_name[0] != '\0')
    {
        printf ("File name %s\n", file_name);

        LOG_FILE = fopen (file_name, "w");
        // if (LOG_FILE == NULL) { return FILE_OPEN_ERROR; }

        strcpy (ACTIVE_LOGFILE_NAME, file_name);

        return true;
    }

    printf ("File name %s\n", DEFAULT_LOG_NAME);

    LOG_FILE = fopen (DEFAULT_LOG_NAME, "w");

    return true;

}


int open_log (int argc, const char* argv[], int pos, void* VariableStruct)
{
    char file_name[] = "";
    int skip_args = 0;

    for (int arg_indx = pos + 1; arg_indx < argc; arg_indx++, skip_args++)
    {
        // if () break;
        //
        if (argv[arg_indx][0] != '-')
        {
            switch (skip_args)
            {
                case 0:
                    strcpy (file_name, argv[arg_indx]);
                    break;

                case 1:
                    LOG_LEVEL = atoi (argv[arg_indx]);
                    break;

                default:
                    printf ("Too much additional arguments\n");
            }

            continue;
        }

        break;
    }

    printf ("Started to write logs...\n");

    get_log_file (file_name);

    if (!LOG_FILE)
    {
        printf ("Failed to open the file %s\n", file_name);

        return skip_args;
    }

    fprintf (LOG_FILE, "Started logging...\n");

    return skip_args;

}


void finish_log()
{
    fprintf (LOG_FILE, "Finishing logging... Goodluck in debugging :)\n");
    fputc   ('\n', LOG_FILE);

    fclose  (LOG_FILE);
}


void put_spaces (int spaces_amount)
{
    fprintf (LOG_FILE, "%*s", spaces_amount, " ");
}
