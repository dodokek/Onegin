
#include "include/onegin.h"
#include "include/argument_proccessing.h"
#include "include/log.h"

// Command line arguments

#define ADD_OPT(option_name, func_name) {option_name, func_name},
// main_opt.mac

// ADD_OPT("--log", open_log)
// ADD_OPT("l", open_log)

const OptionDef Options[] =
{
    // #include "main_opt.mac"
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
    {"/s",         choose_sort}/*,

    {"-help",      print_help},
    {"-h",         print_help},
    {"/h",         print_help}*/
};

// Command line arguments


int main(int argc, const char *argv[])
{
    process_arguments (argc, argv, Options, sizeof(Options) / sizeof(Options[0]));

    start_onegin();
}


