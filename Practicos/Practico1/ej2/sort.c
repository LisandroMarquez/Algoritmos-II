#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
    int pivot;
    if (der > izq) {
        pivot = partition(a, izq, der);
        quick_sort_rec(a, izq, (pivot == 0) ? pivot : pivot - 1);
        quick_sort_rec(a, (pivot == 0) ? pivot : pivot + 1, der);
    }
}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}

