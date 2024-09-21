#ifndef STRLIB_H
#define STRLIB_H

char str_at(int index, char* str);
char str_char_at(int index, char* str);
void str_concat(char* firstStr, char* concatValue, char* secondStr);
int str_ends_with(char* str, char* endsWith);
int str_starts_with(char* str, char* endsWith);
int str_includes(char* str, char* includesStr);
int str_index_of(char* str, char* indexOfStr);
int str_last_index_of(char* str, char* lastIndexOfStr);
int str_localeCompare(char* firstStr, char* secondStr);
void str_substring(char* str, int firstIndex, int lastIndex);
void str_trim(char* str);
void str_trim_start(char* str);
void str_trim_end(char* str);
void str_pad_end(char* str, int count, char symbol);
void str_to_lower_case(char* str);
void str_to_upper_case(char* str);

void str_pad_start(char* str, int count, char symbol); // Virker ikke helt rigtigt.
void str_repeat(char* str, int count); // VIrker ikke


#endif // STRLIB_H
