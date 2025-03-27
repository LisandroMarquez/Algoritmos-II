#include <stdbool.h>
#include <assert.h>
#include <stdio.h>

#include "fixstring.h"

unsigned int fstring_length(fixstring s) {
    unsigned int count = 0;

    while (s[count] != '\0') {
        count++;
    }
    
    return count;
}

bool fstring_eq(fixstring s1, fixstring s2) {
    bool flag = true;

    if (fstring_length(s1) != fstring_length(s2)) flag = false;

    for (unsigned int i = 0; i < fstring_length(s1); i++) {
        if (s1[i] != s2[i]) flag = false;
    }

    return flag;
}

bool fstring_less_eq(fixstring s1, fixstring s2) {
    bool flag = true, aux_flag = false;

    unsigned int i = 0, minor_length, s1_length = fstring_length(s1), s2_length = fstring_length(s2);

    if (s1_length <= s2_length) {
        minor_length = s1_length;
    } else {
        minor_length = s2_length;
        flag = false;
    }
    while (i < minor_length && flag && !aux_flag) {
        if (s1[i] > s2[i]) flag = false;
        if (s1[i] < s2[i]) aux_flag = true;

        i++;
    }

    return flag;
}

