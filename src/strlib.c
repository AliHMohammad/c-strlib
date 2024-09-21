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

int str_includes(char* str, char* includesStr) {
    int matchCount = 0;
    int includesStrLength = 0;
    char* startP = includesStr;

    while (*includesStr)
    {
        includesStrLength++;
        includesStr++;
    }

    includesStr -= includesStrLength;

    while (*str)
    {
        if (*str == *includesStr) {
            matchCount++;
            includesStr++;
            str++;

            if (matchCount == includesStrLength) {
                return 1;
            }

            continue;
        }

        includesStr = startP;
        matchCount = 0;
        str++;
    }
    
    return 0;
}

int str_index_of(char* str, char* indexOfStr) {
    int matchCount = 0;
    int indexOfStrLength = 0;
    char* indexOftrStartP = indexOfStr;
    char* strStartP = str;

    while (*indexOfStr)
    {
        indexOfStrLength++;
        indexOfStr++;
    }

    indexOfStr -= indexOfStrLength;

    while (*str)
    {
        if (*str == *indexOfStr) {
            matchCount++;

            if (matchCount == indexOfStrLength) {
                return (str - strStartP) - indexOfStrLength + 1;
            }

            indexOfStr++;
            str++;
            continue;
        }

        indexOfStr = indexOftrStartP;
        matchCount = 0;
        str++;
    }
    
    return -1;
}

int str_last_index_of(char* str, char* lastIndexOfStr) {
    int matchCount = 0;
    int lastIndexofStrLength = 0;
    char* lastIndexOfStrP = lastIndexOfStr;
    char* strStartP = str;

    while (*lastIndexOfStr)
    {
        lastIndexofStrLength++;
        lastIndexOfStr++;
    }

    while (*str)
    {
        str++;
    }

    while (str >= strStartP)
    {
        if (*str == *lastIndexOfStr) {
            matchCount++;

            if (matchCount == lastIndexofStrLength) {
                return (str - strStartP);
            }

            lastIndexOfStr--;
            str--;
            continue;
        }

        lastIndexOfStr = (lastIndexOfStrP + lastIndexofStrLength) - 1;
        matchCount = 0;
        str--;
    }
    
    return -1;
}
