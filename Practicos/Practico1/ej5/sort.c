#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"
#include "fixstring.h"


static unsigned int partition(fixstring a[], unsigned int izq, unsigned int der) {
    fixstring pivot; // Elegimos el primer elemento como pivote
    fstring_set(pivot, a[izq]);
    unsigned int i = izq + 1;
    unsigned int j = der;
    bool should_continue = true;

    while (should_continue && i <= j) {
        should_continue = false;

        // Avanzar i mientras a[i] <= pivot
        if (goes_before(a[i], pivot)) {
            i++;
            should_continue = true;
        }

        // Retroceder j mientras a[j] >= pivot
        if (goes_before(pivot, a[j])) {
            j--;
            should_continue = true;
        }

        // Intercambiar si i <= j y los elementos están en el lado incorrecto
        if (i <= j && !goes_before(a[i], pivot) && !goes_before(pivot, a[j])) {
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

static void quick_sort_rec(fixstring a[], unsigned int izq, unsigned int der) {
    unsigned int pivot;
    if (der > izq) {
        pivot = partition(a, izq, der);

        quick_sort_rec(a, izq, (pivot == 0) ? pivot : pivot - 1);
        quick_sort_rec(a, pivot + 1, der);
    }
}

void quick_sort(fixstring a[], unsigned int length) {
    if (length <= 1) return;
    quick_sort_rec(a, 0, length - 1);
}
