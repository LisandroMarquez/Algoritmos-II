#include "binary_search.h"

int binary_search_rec(int a[], int x, int lft, int rgt) {
    int mid, i; 
 
    if (lft > rgt) i = -1; 
    else if (lft <= rgt) {
        mid = (lft + rgt) / 2;
        if (x < a[mid]) {
            // buscar hacia la izquierda 
            i = binary_search_rec(a, x, lft, mid-1);
        }
        else if (x == a[mid]) {
            // lo encontramos! 
            i = mid;
        }
        else if (x > a[mid]) {
            // buscar hacia la derecha 
            i = binary_search_rec(a, x, mid+1, rgt);
        } 
    }

    return i;
}

/**
 * @brief Posición de un valor en un arreglo ordenado.
 * 
 * Dado un arreglo ordenado de menor a mayor y un número entero x, devuelve la
 * posición del número dentro del arreglo. Si el valor no se encuentra, 
 * devuelve -1.
 * La búsqueda se realiza usando una estrategia divide y vencerás de
 * complejidad O(log n).
 *
 * @param a Arreglo ordenado.
 * @param length Largo del arreglo.
 * @param x Valor a buscar.
 */
int binary_search(int a[], int length, int x) {
    int i = binary_search_rec(a, x, 0, length - 1);

    return i;
}