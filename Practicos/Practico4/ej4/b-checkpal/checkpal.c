#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "strfuncs.h"

#define MAX_LENGTH 100

#define SIZEOF_ARRAY(s) (sizeof(s) / sizeof(*s))

int main(void) {
    char user_input[MAX_LENGTH];
    char ignore_chars[] = {' ', '?', '!', ',', '-', '.', '\n'};
    char *filtered=NULL, *aux; //+ Added aux

    printf("Ingrese un texto (no más de %d sí­mbolos) para verificar palí­ndromo: ", MAX_LENGTH);
    fgets(user_input, sizeof(user_input), stdin);

    filtered = string_filter(user_input, ignore_chars[0]);
    for (unsigned int i=1; i < SIZEOF_ARRAY(ignore_chars); i++) { //& i arranca ahora desde 1 en lugar de recorrer nuevamente en 0
        //# Asignamos a aux el resultado filtrado, liberamos lo que había en filtered y rehacemos
        aux = string_filter(filtered, ignore_chars[i]);
        free(filtered);
        filtered = aux;
    }

    printf("El texto:\n\n  %s\n%s un palí­ndromo.\n\n", user_input, string_is_symmetric(filtered) ? "Es": "NO es");
    
    //% Added to free memory
    free(filtered);

    return EXIT_SUCCESS;
}

