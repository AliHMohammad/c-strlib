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

    while (*str)
    {
        if (*str == *endsWith) {
            matchCount++;
        }
        str++;
        endsWith++;
    }

    return matchCount == endsWithLength ? 1 : 0;
}

int str_starts_with(char* str, char* startsWith) {
    int startsWithLength = 0;
    int matchCount = 0;

    while (*startsWith)
    {
        startsWithLength++;
        startsWith++;
    }

    startsWith -= startsWithLength;

    while (*startsWith)
    {
        if (*str == *startsWith) {
            matchCount++;
        }
        str++;
        startsWith++;
    }
    
    return matchCount == startsWithLength ? 1 : 0;
}


