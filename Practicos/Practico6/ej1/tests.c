#include <stdbool.h>
#include <stdio.h>
#include "change.h"

#define MAX_COINS 10
#define N_TESTCASES 5

int main() {
    // representación de un solo caso de test
    struct testcase {
        int d[MAX_COINS];  // denominaciones
        int n;             // cantidad de denominaciones
        int k;             // monto a pagar
        int result;        // resultado esperado: cantidad mínima de monedas
    };

    // casos de test (uno por línea): { d, n, k, result }
    struct testcase tests[N_TESTCASES] = {
      { {3, 4, 1}, 3, 2, 2 },  // testea: change({4,2,7}, 3, 16) == 10
      { {2, 4, 7}, 3, 16, 3 },  // testea: change({4,2,7}, 3, 16) == 10
      { {14, 9, 4, 1}, 4, 50, 5 },
      { {6, 5, 2}, 3, 19, 4 },
      { {6, 1, 3}, 3, 19, 4 },
    };

    int result;

    printf("TESTING change\n");

    for (int i=0; i < N_TESTCASES; i++) {
        printf("Test case %i: \n", i+1);

        // TEST! llamamos la función a change
        result = change(tests[i].d, tests[i].n, tests[i].k);

        // comparamos resultado obtenido con resultado esperado
        if (result == tests[i].result) {
            printf("OK\n");
        } else {
            printf("FAILED: got %d expected %d\n", result, tests[i].result);
        }
    }

    return 0;
}
