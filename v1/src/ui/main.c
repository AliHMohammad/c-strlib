#include <stdio.h>
#include "strlib.h"


int main() {
    char val[255] = "HELLO WORLD";
    str_to_lower_case(val);
    printf("%s\n", val); 

    return 0;
}
