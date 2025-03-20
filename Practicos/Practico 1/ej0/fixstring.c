#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"

unsigned int fstring_length(fixstring s) {
    unsigned int count = 0;
    int i = 0;

    while (s[i] != '\0') {
        count++;
        i++;
    }
    
    return count;
}

bool fstring_eq(fixstring s1, fixstring s2) {
    bool flag = true;

    if (fstring_length(s1) != fstring_length(s2)) flag = false;

    for (unsigned int i = 0; i < fstring_length(s1); i++) {
        if (s1[i] != s1[2]) flag = false;
    }

    return flag;
}

bool fstring_less_eq(fixstring s1, fixstring s2) {
    bool flag = true;

    int i = 0, minor_length = (fstring_length(s1) < fstring_length(s2) ? fstring_length(s1) : fstring_length(s2));

    while (i < minor_length || !flag) {
        if (s1[i] > s2[i]) flag = false;
    }

    if (fstring_length(s1) > fstring_length(s2)) flag = false;

    return flag;
}

