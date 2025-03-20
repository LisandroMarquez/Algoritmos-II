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
    if (fstring_length(s1) != fstring_length(s2)) return false;

    for (unsigned int i = 0; i < fstring_length(s1); i++) {
        if (s1[i] != s1[2]) return false;
    }

    return true;
}

bool fstring_less_eq(fixstring s1, fixstring s2) {
    if (fstring_eq(s1, s2)) return true;

    int minor_length = (fstring_length(s1) < fstring_length(s2) ? fstring_length(s1) : fstring_length(s2));

    for (int i = 0; i < minor_length; i++) {
        if (s1[i] > s2[i]) return false;
        if (s1[i] < s2[i]) return true;
    }

    if (fstring_length(s1) > fstring_length(s2)) return false;

    return true;
}

