#include <stdio.h>
#include "strlib.h"


int main(int argc, char const *argv[])
{
    char str[] = "hello";
    char str2[] = "o";

    int result = str_ends_with(str, str2);

    printf("%d\n", result);
    
    return 0;
}
