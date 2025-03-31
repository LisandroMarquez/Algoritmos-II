#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

static unsigned int min_pos_from(int a[], unsigned int i, unsigned int length) {
    unsigned int min_pos = i;
    for (unsigned int j = i + 1; j < length; ++j) {
        if (!goes_before(a[min_pos],a[j])) {
            min_pos = j;
        }
    }
    return (min_pos);
}

void selection_sort(int a[], unsigned int length) {
    for (unsigned int i = 0; i < length; ++i) {
        unsigned int min_pos = min_pos_from(a, i, length);
        swap(a, i, min_pos);
    }
}


static void insert(int a[], unsigned int i) {
    while (i > 0 && goes_before(a[i], a[i-1])) {
        swap(a, i, i-1);
        i--;
    }
}

void insertion_sort(int a[], unsigned int length) {
    for (unsigned int i = 0; i < length; ++i) {
        insert(a, i);
    }
}


static unsigned int partition(int a[], unsigned int izq, unsigned int der) {
    int pivot = a[izq]; // Elegimos el primer elemento como pivote
    unsigned int i = izq + 1;
    unsigned int j = der;
    bool should_continue = true;

    while (should_continue && goes_before(i, j)) {
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
        if (goes_before(i, j) && !goes_before(a[i], pivot) && !goes_before(pivot, a[j])) {
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

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
    unsigned int pivot = 1;
    if (der > izq) {
        pivot = partition(a, izq, der);
        quick_sort_rec(a, izq, pivot);
        quick_sort_rec(a, pivot + 1, der);
    }
}

void quick_sort(int a[], unsigned int length) {
    if (length == 0) return;
    quick_sort_rec(a, 0, length - 1);
}
