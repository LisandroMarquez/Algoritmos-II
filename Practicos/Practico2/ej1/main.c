#include <stdio.h>
#include <stdlib.h>
#include "k_esimo.h"

int main(void) {
    int a[] = {2, 5, 1, 3, 0, 6, 4};
    int length = 7;
    int k = 2;
    int result;

    result = k_esimo(a, length, k);

    printf("Resultado: %i\n", result);

    return EXIT_SUCCESS;
}
