#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static unsigned int partition(int a[], unsigned int izq, unsigned int der) {
    int pivot = a[izq]; // Elegimos el primer elemento como pivote
    unsigned int i = izq + 1;
    unsigned int j = der;
    bool should_continue = true;

    while (should_continue && i <= j) {
        should_continue = false;

        // Avanzar i mientras a[i] <= pivot
        if (a[i] <= pivot) {
            i++;
            should_continue = true;
        }

        // Retroceder j mientras a[j] >= pivot
        if (a[j] >= pivot) {
            j--;
            should_continue = true;
        }

        // Intercambiar si i <= j y los elementos están en el lado incorrecto
        if (i <= j && a[i] > pivot && a[j] < pivot) {
            swap(a, i, j);
            i++;
            j--;
            should_continue = true;
        }
    }

    // Intercambiar el pivote con a[j] (posición final del pivote)
    swap(a, izq, j);

    // Retornar la posición del pivote
    return j;
}

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der, unsigned int length) {
    unsigned int pivot = 1;
    if (der > izq) {
        printf("\n\nBEFORE PARTITION\nIzq: %u\nDer: %u\n Piv: %u\n", izq, der, pivot);
        array_dump(a, length);
        pivot = partition(a, izq, der);
        printf("\n\nAFTER PARTITION\nIzq: %u\nDer: %u\n Piv: %u\n", izq, der, pivot);
        array_dump(a, length);

        quick_sort_rec(a, izq, pivot, length);
        quick_sort_rec(a, pivot + 1, der, length);
    }
}

void quick_sort(int a[], unsigned int length) {
    if (length == 0) return;
    quick_sort_rec(a, 0, length - 1, length);
}

