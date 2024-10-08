#include "strlib.h"
#include <stdio.h>

// Tjekker om en byte er en ASCII-værdi (0-127)
int is_ascii(unsigned char byte) {
    return byte <= 0x7F;  // ASCII-værdier er mellem 0x00 og 0x7F
}

// Tjekker om en byte er en continuation byte (0x80-0xBF)
int is_continuation_byte(unsigned char byte) {
    return (byte >= 0x80 && byte <= 0xBF);
}

// Tjekker om en byte er den første byte i en UTF-8-sekvens
// Returnerer længden af sekvensen, eller 0 hvis ikke første byte
int first_byte_sequence_length(unsigned char byte) {
    if (byte <= 0x7F) {
        return 1;  // 1-byte UTF-8 sekvens (ASCII)
    } else if ((byte & 0xE0) == 0xC0) {
        return 2;  // 2-byte UTF-8 sekvens
    } else if ((byte & 0xF0) == 0xE0) {
        return 3;  // 3-byte UTF-8 sekvens
    } else if ((byte & 0xF8) == 0xF0) {
        return 4;  // 4-byte UTF-8 sekvens
    } else {
        return 0;  // Ikke en gyldig første byte
    }
}

int str_length(char* str) {
    int length = 0;

    while (*str) {
        char current_byte = *str;
        int seq_length = first_byte_sequence_length(current_byte);

        // Hvis det er en gyldig første byte i en sekvens
        if (seq_length > 0) {
            length++;           // Tæl sekvensen
            str += seq_length;  // Spring over hele sekvensen
        } else {
            // Hvis det er en ugyldig byte, spring over den
            str++;
        }
    }
    
    return length;
}

char str_at(int index, char* str) {
    int indexCounter = 0;

    while (index != indexCounter)
    {
        char current_byte = *str;
        int seq_length = first_byte_sequence_length(current_byte);

        // Hvis det er en gyldig første byte i en sekvens
        if (seq_length > 0) {
            indexCounter++;     // Tæl sekvensen
            str += seq_length;  // Spring over hele sekvensen
        } else {
            // Hvis det er en ugyldig byte, spring over den
            str++;
        }
    }
    
    return *str;
}

char str_char_at(int index, char* str){
    int indexCounter = 0;

    while (index != indexCounter)
    {
        char current_byte = *str;
        int seq_length = first_byte_sequence_length(current_byte);

        // Hvis det er en gyldig første byte i en sekvens
        if (seq_length > 0) {
            indexCounter++;     // Tæl sekvensen
            str += seq_length;  // Spring over hele sekvensen
        } else {
            // Hvis det er en ugyldig byte, spring over den
            str++;
        }
    }
    
    return *str;
}

/*

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

int str_localeCompare(char* firstStr, char* secondStr) {
    int firstStrLength = 0;
    int secondStrLength = 0;

    while (*firstStr)
    {
        firstStrLength++;
        firstStr++;
    }

    while (*secondStr)
    {
        secondStrLength++;
        secondStr++;
    }
    
    if (firstStrLength != secondStrLength) {
        return 0;
    }

    firstStr -= firstStrLength;
    secondStr -= secondStrLength;

    while (*firstStr)
    {
        if (*firstStr != *secondStr) {
            return 0;
        }
        firstStr++;
        secondStr++;
    }

    return 1;
}

void str_substring(char* str, int firstIndex, int lastIndex) {
    int strLength = 0;
    char *strCpy = str;

    while (*str)
    {
        strLength++;
        str++;
    }

    str = strCpy;

    if (firstIndex < 0 || lastIndex > strLength || lastIndex <= firstIndex) {
        printf("Invalid indexes\n");
        return;
    }

    for (int i = firstIndex; i < lastIndex; i++) {
        *str++ = *(strCpy + i);
    }
    
    *str = '\0';
}

void str_trim(char* str) {
    char* start = str;

    while (*start == ' ') {
        start++;
    }

    if (*start == '\0') {
        *str = '\0';
        return;
    }

    char* end = start;

    while (*end) {
        end++;
    }

    end--; // Tilbage til sidste karakter


    while (end > start && *end == ' ') {
        end--;
    }

    *(end + 1) = '\0';

    while (*start) {
        *str = *start;
        str++;
        start++;
    }

    *str = '\0'; 
}

void str_trim_start(char* str) {
    char* start = str;

    while (*start == ' ') {
        start++;
    }

    if (*start == '\0') {
        *str = '\0';
        return;
    }

    while (*start) {
        *str = *start;
        str++;
        start++;
    }

    *str = '\0';
}

void str_trim_end(char* str) {
    char* end = str;

    while (*end) {
        end++;
    }

    while (end >= str && *end == ' ') {
        end--;
    }

    *(end + 1) = '\0';
}

void str_pad_end(char* str, int count, char symbol) {
    while (*str)
    {
        str++;
    }

    while (count)
    {
        *str = symbol;
        str++;
        count--;
    }

    *str = '\0';
}

void str_pad_start(char* str, int count, char symbol) {
    int strLength = 0;
    char* cpy = str;

    while (*cpy)
    {
        strLength++;
        cpy++;
    }

    char* end = str + strLength;

    for (int i = strLength; i >= 0; i--) {
        *(end + count) = *(str + i); 
    }

    while (count)
    {
        *str = symbol;
        str++;
        count--;
    }
}

void str_repeat(char* str, int count) {
    char* initial = str;

    while (*str)
    {
        str++;
    }

    while (count)
    {
        char* start = initial;

        while (*start)
        {
            *str = *start;
            str++;
            start++;
        }

        count--;
    }

    *str = '\0';
}

void str_to_upper_case(char* str){
    while (*str)
    {
        char c = *str;

        if (c == ' ') {
            *str = c - 32;
        }

        str++;
    }
}

void str_to_lower_case(char* str){
    while (*str)
    {
        char c = *str;

        if (c != ' ') {
            *str = c + 32;
        }

        str++;
    }
}

*/
