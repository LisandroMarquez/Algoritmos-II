#include "remove.h"
#include "list.h"

/**
 * @brief Devuelve en UNA NUEVA lista el resultado de eliminar todas las
 * ocurrencias de `e` en `l`
 *
 */
list remove_elem(list l, elem e) {
    int len = length(l);
    elem element;

    list l1;
    l1 = empty();

    for(int i = 0; i < len; i++) {
        element = index(l, i);
        if (element != e) {
            l1 = addr(l1, element);
        }
    }

    return l1;
}
