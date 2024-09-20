#include "strlib.h"
#include <stdio.h>

char str_at(int index, char* str) {
    return *(str += index);
}

char str_char_at(int index, char* str){
    return *(str += index);
}

void str_concat(char* firstStr, char* concatValue, char* secondStr){
    while (*firstStr) {
        firstStr++;
    }

    while (*concatValue)
    {
        *firstStr = *concatValue;
        firstStr++;
        concatValue++;
    }

    while (*secondStr)
    {
        *firstStr = *secondStr;
        firstStr++;
        secondStr++;
    }
}

int str_ends_with(char* str, char* endsWith) {
    int matchCount = 0;
    int endsWithLength = 0;

    while (*endsWith)
    {
        endsWithLength++;
        endsWith++;
    }

    endsWith -= endsWithLength;
    
    while (*str)
    {
        str++;
    }

    str -= endsWithLength;

    printf("Length of endswith: %d\n", endsWithLength);

    while (*str)
    {
        printf("Letter of str: %c\n", *str);
        printf("Letter of endsWith: %c\n", *endsWith);
        if (*str == *endsWith) {
            matchCount++;
        }
        str++;
        endsWith++;
    }

    printf("Match count: %d\n", matchCount);

    return matchCount == endsWithLength ? 1 : 0;
}
