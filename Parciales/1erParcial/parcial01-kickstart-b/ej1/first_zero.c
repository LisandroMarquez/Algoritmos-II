#include <assert.h>
#include <stdbool.h>
#include "first_zero.h"

int first_zero_rec(int a[], int lft, int rgt) {
    int mid, result; 
 
    if (lft == rgt) {
        // casos base
        if (a[lft] == 0) {
            result = lft;
        } else if (a[lft] == 1) {
            result = -1;
        } 
    } else if (lft < rgt) {
        mid = (lft + rgt) / 2; 
        if (a[mid] == 0) {
            // buscar hacia la izquierda incluyendo mid 
            result = first_zero_rec(a, lft, mid);
        } else if (a[mid] == 1) {
             // buscar hacia la derecha (sin mid) 
            result = first_zero_rec(a, mid+1, rgt);
        }
    }

    return result;
}

/**
 * @brief Posición del primero cero en un arreglo de la forma [1, 1, ... , 1, 0, 0, ..., 0].
 * 
 * Dado un arreglo de la forma [1, 1, ... , 1, 0, 0, ..., 0], devolver la
 * posición del primer elemento que es un cero (0). Si no hay ningún cero,
 * devolver -1. La búsqueda se realiza usando una estrategia divide y vencerás
 * de complejidad O(log n).
 *
 * @param a Arreglo de forma [1, 1, ... , 1, 0, 0, ..., 0].
 * @param length Largo del arreglo.
 */
int first_zero(int a[], int length) {
    int result = first_zero_rec(a, 0, length - 1);

    return result;
}