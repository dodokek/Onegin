
#include "include/file_work.h"

//-----------------------------------------------------------------------------

FILE* get_file(const char file_name[], const char* mode)
{
    //printf("File name is %s\n", file_name);

    FILE* tmp_file = fopen(file_name, mode);

    if (tmp_file)
    {
        return tmp_file;
    }
    printf("Failed to open the file.\n");

    return nullptr;
}

int read_file(FILE* file, char **main_str)
{
    fseek (file, 0L, SEEK_END);
    int file_len = ftell (file);

    fseek (file, 0L, SEEK_SET);
    *main_str = (char*) calloc(sizeof(char), file_len);
    int symbols_read = fread (*main_str, sizeof(char), file_len, file);

    fclose(file);

    return symbols_read;
}

