#include "strfuncs.h"
#include <stdlib.h>

size_t string_length(const char *str) {
    size_t count = 0;

    while (*(str + (int) count) != '\0') {
        count++;
    }
    
    return count;
}

char *string_filter(const char *str, char c) {
    // Primero contamos cuántos caracteres necesitamos
    size_t length = string_length(str);
    size_t new_length = 0;
    
    // Contamos los caracteres que no son 'c'
    for (size_t i = 0; i < length; i++) {
        if (*(str + (int) i) != c) {
            new_length++;
        }
    }
    
    // Reservamos memoria (incluyendo espacio para el '\0')
    char *filtered = malloc((new_length + 1) * sizeof(char));
    if (filtered == NULL) {
        return NULL; // Fallo en la asignación de memoria
    }

    // Copiamos los caracteres que no son 'c'
    size_t pos = 0;
    for (size_t i = 0; i < length; i++) {
        if (*(str + (int) i) != c) {
            filtered[pos++] = *(str + (int) i);
        }
    }
    
    // Añadimos el terminador nulo
    filtered[new_length] = '\0';

    return filtered;
}

bool string_is_symmetric(const char *str) {
    bool flag = true;
    int count = 0, length = (int) string_length(str);

    while (flag && length / 2 + 1 > count) {
        if(str[count] != str[length - (count + 1)]) flag = false;
        else count++;
    }
    return flag;
}
