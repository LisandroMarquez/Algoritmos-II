#include "flag_sort.h"

void swap(color_t a[], int i, int j);

/**
 * @brief Ordenar un arreglo de tres colores RED, WHITE y BLUE.
 *
 * Dado un arreglo cuyos elementos son tres colores posibles RED, WHITE y BLUE,
 * ordenarlos de manera que queden todos los RED primero, después todos los 
 * WHITE y al final todos los BLUE, formando la bandera de Córdoba.
 * 
 * @param a Arreglo de colores.
 * @param length Largo del arreglo.
 */
void flag_sort(color_t a[], int length) {
    int i, j, k;
    i = 0, j = 0, k = length - 1;

    while (j <= k) {
        if (a[j] == red) {
            // poner el RED al �ltimo de los RED 
            swap(a, i, j);
            i++;
            j++;
        } 
        else if (a[j] == blue) {
            // poner el BLUE al principio de los BLUE 
            swap(a, j, k);
            k--;
        }
        else if (a[j] == white) {
            // dejar el WHITE al final de los WHITE 
            j++;
        }  
    }
}

void swap(color_t a[], int i, int j) {
    color_t tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}
