#include <stdio.h>
#include "strlib.h"


int main(int argc, char const *argv[])
{
    char str[] = "hello sir, how are your doing?";
    char indexOf[] = "your";

    int result = str_index_of(str, indexOf);

    printf("%d\n", result);
    
    return 0;
}
