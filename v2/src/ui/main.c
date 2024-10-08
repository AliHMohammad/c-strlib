#include <stdio.h>
#include <stdlib.h>
#include "strlib.h"


int main() {
    char* test_str = "Hello, 世界!";
    
    // Test med nogle indekser
    printf("Kodepunkt ved indeks 7: %d\n", str_code_point_at(7, test_str));  // Forventer kodepunkt for '世'
    printf("Kodepunkt ved indeks 8: %d\n", str_code_point_at(8, test_str));  // Forventer kodepunkt for '界'
    printf("Kodepunkt ved indeks 1: %d\n", str_code_point_at(1, test_str));  // Forventer kodepunkt for 'e'
    printf("Kodepunkt ved indeks 20: %d\n", str_code_point_at(20, test_str));  // Udenfor rækkevidde

    // Test med forskellige kodepunkter
    char* utf8_char1 = str_from_code_point(0x61);       // 'a'
    char* utf8_char2 = str_from_code_point(0x00E5);     // 'å'
    char* utf8_char3 = str_from_code_point(0x4E16);     // '世'
    char* utf8_char4 = str_from_code_point(0x1F600);    // 😀 (emoji)
    
    if (utf8_char1) printf("UTF-8: %s\n", utf8_char1);
    if (utf8_char2) printf("UTF-8: %s\n", utf8_char2);
    if (utf8_char3) printf("UTF-8: %s\n", utf8_char3);
    if (utf8_char4) printf("UTF-8: %s\n", utf8_char4);

    // Frigør den allokerede hukommelse
    free(utf8_char1);
    free(utf8_char2);
    free(utf8_char3);
    free(utf8_char4);

    return 0;
}
