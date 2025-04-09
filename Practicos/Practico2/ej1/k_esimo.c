#include <stdbool.h>
#include <stdio.h>
#include "k_esimo.h"

// FUNCIONES INTERNAS DEL MÓDULO:
int partition(int a[], int izq, int der);
bool goes_before(int x, int y);
void swap(int a[], int i, int j);


// Funciones adicionadas
void array_dump(int a[], unsigned int length) {
    fprintf(stdout, "%u\n", length);
    for (unsigned int i = 0u; i < length; ++i) {
        fprintf(stdout, "%i", a[i]);
        if (i < length - 1) {
            fprintf(stdout, " ");
        } else {
            fprintf(stdout, "\n");
        }
    }
}

static unsigned int min_pos_from(int a[], unsigned int i, unsigned int length) {
    unsigned int min_pos = i;
    for (unsigned int j = i + 1; j < length; ++j) {
        if (!goes_before(a[min_pos],a[j])) {
            min_pos = j;
        }
    }
    return (min_pos);
}

void selection_sort(int a[], unsigned int length, int k) {
    int i = 0;
    while (i < k + 1) {
        unsigned int min_pos = min_pos_from(a, i, length);
        //!printf("Intercambio de %i <-> %i\n", a[i], a[min_pos]);
        swap(a, i, min_pos);
        i++;
    }
}

/**
 * @brief K-esimo elemento mas chico del arreglo a.
 *
 * Devuelve el elemento del arreglo `a` que quedarí­a en la celda `a[k]` si el
 * arreglo estuviera ordenado. La función puede modificar el arreglo.
 * Dicho de otra forma, devuelve el k-esimo elemento mas chico del arreglo a.
 *
 * @param a Arreglo.
 * @param length Largo del arreglo.
 * @param k Posicion dentro del arreglo si estuviera ordenado.
 */
int k_esimo(int a[], int length, int k) {
    //!array_dump(a, length);
    //!printf("El elemento desordenado en la posicion k = %i, es %i\n",k, a[k]);
    selection_sort(a, length, k);
    //!array_dump(a, length);
    //!printf("\nEl elemento ordenado en la posicion k = %i, es %i\n",k, a[k]);
    return a[k];
}

int partition(int a[], int izq, int der) {
    int i, j, ppiv;
    ppiv = izq;
    i = izq + 1;
    j = der;
    while (i <= j) {
        if (goes_before(a[i], a[ppiv])) {
            i = i + 1;
        } else if (goes_before(a[ppiv], a[j])) {
            j = j - 1;
        } else {
            swap(a, i, j);
        }
    }

    swap(a, ppiv, j);
    ppiv = j;

    return ppiv;
}

bool goes_before(int x, int y) {
    return x <= y;
}

void swap(int a[], int i, int j) {
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}
