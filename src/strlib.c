#include "strlib.h"

char str_at(int index, char* str) {
    return *(str += index);
}
