#include <compiler.h>

struct lex_process_functions compiler_lex_function = {
    .next_char=compile_process_next_char,
    .peek_char=compile_process_peek_char,
    .push_char=compile_process_push_char
};

int compile_file(const char *filename, const char *out_filename, int flag)
{
    struct compile_process *process = compile_process_create(filename, out_filename, flag);
    if (!process)
    {
        return COMPILER_FAILED_WITH_ERRORS;
    }

    //Perform lexical analysis
    struct lex_process* lex_process = lex_process_create(process, &compiler_lex_function, NULL);
    if(!lex_process)
    {
        return COMPILER_FAILED_WITH_ERRORS;
    }

    if(lex(lex_process) != LEXICIAL_ANALYSIS_ALL_OK)
    {
        return COMPILER_FAILED_WITH_ERRORS;
    }
    // Perform parsing

    // perform code generation
    return 0;
}