
#include "include/argument_proccessing.h"


void process_arguments (int                    argc,      const char* argv[],
                        const struct OptionDef Options[], int         options_range,
                        GeneralVariables       *GeneralV)
{
    assert (argc > 0 && argv != NULL && Options != NULL);

    for (int arg_indx = 0; arg_indx < argc; arg_indx++)
    {
        for (int i = 0; i < options_range; i++)
        {
            if (strcmp (argv[arg_indx], Options[i].name) == 0)
            {
                int skip_argv = Options[i].opt_handle (argc, argv, arg_indx, GeneralV);

                arg_indx += skip_argv;
            }
        }
    }
}


int print_help(int /* argc */, const char* /* argv[] */, int /* pos */, void* /*GeneralV*/)
{
    printf ("Guess you need some help, try to find an answer in our documentation!\n");

    char help_src[] = "html\\index.html";

    system (help_src); 

    return 0;
}


int change_input_name (int argc, const char* argv[], int pos, void* VariableStruct)
{
    assert(argc > 0 && argv != NULL && pos >= 0);

    GeneralVariables *CurGeneralV = (GeneralVariables*) VariableStruct;

    __TRACKBEGIN__

    int skip_args = 0;

    for (int arg_indx = pos + 1; arg_indx < argc; arg_indx++, skip_args++)
    {
        if (argv[arg_indx][0] != '-')
        {   
            switch (skip_args)
            {
                case 0:
                    puts(argv[arg_indx]);
                    CurGeneralV->input_file_name = (char*) argv[arg_indx];
                    break;

                default:
                    printf ("Too much additional arguments\n");
            }
        }
        else
        {
            break;
        }
    }

    __TRACKEND__

    return skip_args;
}


int change_output_name (int argc, const char* argv[], int pos, void* VariableStruct)
{
    assert(argc > 0 && argv != NULL && pos >= 0);

    __TRACKBEGIN__

    GeneralVariables *CurGeneralV = (GeneralVariables*) VariableStruct;

    int skip_args = 0;

    for (int arg_indx = pos + 1; arg_indx < argc; arg_indx++, skip_args++)
    {
        if (argv[arg_indx][0] != '-')
        {
            switch (skip_args)
            {
                case 0:
                    puts(argv[arg_indx]);
                    CurGeneralV->output_file_name = (char*) argv[arg_indx];
                    break;

                // Here i would add cases for different types of input

                default:
                    printf ("Too much additional arguments\n");
            }
        }

        else
        {
            break;
        }
    }

    __TRACKEND__

    return skip_args;
}


int choose_sort (int argc, const char* argv[], int pos, void* VariableStruct)
{
    assert(argc > 0 && argv != NULL && pos >= 0);

    GeneralVariables *CurGeneralV = (GeneralVariables*) VariableStruct;

    __TRACKBEGIN__

    int skip_args = 0;

    for (int arg_indx = pos + 1; arg_indx < argc; arg_indx++, skip_args++)
    {
        if (argv[arg_indx][0] != '-')
        {
            switch (skip_args)
            {
                case 0:
                    if (strcmp ("2", argv[arg_indx])) CurGeneralV->sort_mode = BUBBLE_SORT;
                    if (strcmp ("1", argv[arg_indx])) CurGeneralV->sort_mode = QUICK_SORT;
                    break;

                default:
                    printf ("Too much additional arguments\n");
            }
        }
        else
        {
            break;
        }
    }

    __TRACKEND__

    return skip_args;
}

