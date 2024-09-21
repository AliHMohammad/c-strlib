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
// int str_localeCompare();
// void str_padEnd();
// void str_padStart();
// void str_repeat();
// void str_slice();
// void str_substring();
// void str_to_locale_lower_case();
// void str_to_locale_upper_case();
// void str_to_lower_case();
// void str_to_string(int num);
// void str_to_upper_case();
// void str_trim();
// void str_trim_end();
// void str_trim_start();
// void str_value_of();

#endif // STRLIB_H
