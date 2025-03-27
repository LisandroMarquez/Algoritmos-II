#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static void insert(int a[], unsigned int i, unsigned int length) {
    while (i > 0) {
        if (goes_before(a[i], a[i-1])) {
            array_dump(a, length);
            swap(a, i, i-1);
        }

        if (!array_is_sorted(a, i - 1)) {
            printf("Somethings wrong...\n");
        }

        i--;
    }
}

void insertion_sort(int a[], unsigned int length) {
    for (unsigned int i = 0; i < length; ++i) {
        insert(a, i, length);
    }
}
