#include "strfuncs.h"
#include <stdlib.h>

size_t string_length(const char *str) {
    size_t count = 0;

    //& Counts all chars until the end
    while (str[count] != '\0') {
        count++;
    }
    
    //* Return the length
    return count;
}

char *string_filter(const char *str, char c) {
    size_t length = string_length(str);
    size_t new_length = 0;
    
    //& Getting the new size
    for (size_t i = 0; i < length; i++) {
        //+ Does not count the chars equal to the char c for the new size
        if (str[i] != c) {
            new_length++;
        }
    }
    
    //# Ask memory to alloc needed size
    char *filtered = malloc((new_length + 1) * sizeof(char));
    if (filtered == NULL) {
        return NULL; //! Memory failed to alloc
    }

    //& Copy all chars in order, except chars equal to 'c'
    size_t pos = 0;
    for (size_t i = 0; i < length; i++) {
        //+ Exclude chars equal to the char c
        if (str[i] != c) {
            filtered[pos] = str[i];
            pos++;
        }
    }
    
    //% Add the las character to end the string
    filtered[new_length] = '\0';

    //* Return the new string
    return filtered;
}

bool string_is_symmetric(const char *str) {
    bool flag = true;
    int count = 0, length = (int) string_length(str);

    //# Change flag if not symmetric, else continue checking
    while (flag && length / 2 + 1 > count) {
        //+ First elem equal to last, second equal to second to last, and so on
        if(str[count] != str[length - (count + 1)]) flag = false;
        else count++;
    }

    //* Return the flag value
    return flag;
}
