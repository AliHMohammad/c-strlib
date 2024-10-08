#include <stdio.h>
#include "strlib.h"


int main() {
    char val[255] = "åle";
    char c = str_char_at(0, val);
    printf("%c\n", c);
    printf("%c\n", 'å');

    return 0;
}
