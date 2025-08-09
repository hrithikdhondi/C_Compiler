#include<stdio.h>
#include "helpers/vector.h"
#include "compiler.h"
int main(){
    int res = compile_file("./test.c","./test",0);

    if(res == COMPILER_FILE_COMPILED_OK)
    {
        printf("File compiled successfully\n");
    }
    else if(res == COMPILER_FAILED_WITH_ERRORS)
    {
        printf("Compile Failed\n");
    }
    else
    {
        printf("Unknow Errors has been Occured\n");
    }
    return 0;
}