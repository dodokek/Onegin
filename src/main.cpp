
#include "include/onegin.h"
#include "include/argument_proccessing.h"
#include "include/log.h"

#define ADD_OPT(option_name, func_name) {option_name, func_name},


const OptionDef Options[] =
{
    //#include "include/main_opt.h"

    {"--log",      open_log},
    {"-l",         open_log},
    {"/l",         open_log},

    {"--input",    change_input_name},
    {"-in",        change_input_name},
    {"/in",        change_input_name},

    {"--output",   change_output_name},
    {"-ot",        change_output_name},
    {"/ot",        change_output_name},

    {"-sort",      choose_sort},
    {"-s",         choose_sort},
    {"/s",         choose_sort},
};

// Command line arguments


int main(int argc, const char *argv[])
{
    GeneralVariables MainVariables = {"data/hamlet.txt", "data/default_output.txt", BUBBLE_SORT};

    process_arguments (argc, argv, Options, sizeof(Options) / sizeof(Options[0]), &MainVariables);

    start_onegin(&MainVariables);
}


