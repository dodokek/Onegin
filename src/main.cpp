
#include "include/onegin.h"
#include "include/argument_proccessing.h"
#include "include/log.h"
#include <TXLib.h>

// Command line arguments

const OptionDef Options[] =
{
    {"--log",      open_log},
    {"-l",         open_log},
    {"/l",         open_log}
};

// Command line arguments


int main(int argc, const char *argv[])
{
    process_arguments (argc, argv, Options, sizeof(Options) / sizeof(Options[0]));

    start_onegin();
}


