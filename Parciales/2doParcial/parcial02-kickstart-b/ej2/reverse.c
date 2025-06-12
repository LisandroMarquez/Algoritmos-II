#include "reverse.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Devuelve en UNA NUEVA lista el resultado de invertir
 * el orden de los elementos de `l`
 *
 */
list reverse(list l) {
    // Inicializar variables a usar
    int len = length(l);
    elem e;

    // Crear lista a devolver
    list l1;
    l1 = empty();

    // Append todos los elementos a la inversa
    for(int i = 0; i < len; i++) {
        e = index(l, i);
        l1 = addl(e, l1);
    }

    // Devolver la lista
    return l1;
}
