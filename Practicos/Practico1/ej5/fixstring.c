#include <stdbool.h>
#include <assert.h>

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
    bool flag = true, still_comparing = true;

    unsigned int i = 0;

    while (still_comparing && s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] > s2[i]) {
            flag = false;
            still_comparing = false;
        }
        if (s1[i] < s2[i]) {
            still_comparing = false;
        }

        i++;
    }

    if (still_comparing) {
        flag = (s1[i] == '\0');
    }

    return flag;
}

void fstring_set(fixstring s1, const fixstring s2) {
    int i=0;
    while (i<FIXSTRING_MAX && s2[i]!='\0') {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
}

void fstring_swap(fixstring s1,  fixstring s2) {
    fixstring aux;
    
    fstring_set(aux, s1);   //* A "aux" le asigno "s1"
    fstring_set(s1, s2);           //* A "s1" le asigno "s2"
    fstring_set(s2, aux);   //* A "s2" le asigno "aux (s1)"
}

