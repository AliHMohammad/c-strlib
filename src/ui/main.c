#include <stdio.h>
#include "strlib.h"


int main(int argc, char const *argv[])
{
    char str[] = "hello world";

    char result = str_at(7, str);
    printf("%c\n", result);
    
    return 0;
}
