
#include "include/argument_proccessing.h"
  

int print_help(int /* argc */, const char* /* argv[] */, int /* pos */)
{
    printf ("Guess you need some help, try to find an answer in our documentation!\n");

    char help_src[] = "html\\index.html";

    system (help_src);

    return 0;
}


void process_arguments (int                    argc,      const char* argv[],
                        const struct OptionDef Options[], int         options_range)
{
    assert (argc > 0 && argv != NULL && Options != NULL);

    for (int arg_indx = 0; arg_indx < argc; arg_indx++)
    {
        for (int i = 0; i < options_range; i++)
        {
            if (strcmp (argv[arg_indx], Options[i].name) == 0)
            {
                int skip_argv = Options[i].opt_handle (argc, argv, arg_indx);

                arg_indx += skip_argv;
            }
        }
    }
}
