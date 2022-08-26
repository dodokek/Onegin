
#include "include/file_work.h"

//-----------------------------------------------------------------------------

FILE* get_file(const char file_name[], char* mode)
{
    printf("File name is %s\n", file_name);

    FILE* tmp_file = fopen(file_name, mode);

    if (tmp_file)
    {
        return tmp_file;
    }
    printf("Failed to open the file.\n");

    return nullptr;
}

char* read_file(FILE* file)
{
    fseek (file, 0L, SEEK_END);
    int file_len = ftell (file);

    fseek (file, 0L, SEEK_SET);
    char *main_str = (char*) calloc(sizeof(char), file_len);
    fread (main_str, sizeof(char), file_len, file);

    fclose(file);

    return main_str;
}

