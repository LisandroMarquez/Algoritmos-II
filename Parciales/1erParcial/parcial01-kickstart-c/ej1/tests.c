#include <stdbool.h>
#include <stdio.h>
#include "binary_search.h"

#define MAX_LENGTH 10
#define N_TESTCASES 10

int main(void) {
    struct testcase {
        int a[MAX_LENGTH];
        int length;
        int x;
        int result;
    };

    struct testcase tests[N_TESTCASES] = {
        // arreglo ordenado, largo, x, resultado
        { {8}, 1, 8, 0 },    // el 8 se encuentra en la posición 0
        { {8}, 1, 1, -1 },   // el 1 no se encuentra en el arreglo
        { {8}, 1, 21, -1 },  // el 21 no se encuentra en el arreglo
        { {-21, -7, -1, 4, 8, 11}, 6, -21, 0 },
        { {-21, -7, -1, 4, 8, 11}, 6, -7, 1 },
        { {-21, -7, -1, 4, 8, 11}, 6, -1, 2 },
        { {-21, -7, -1, 4, 8, 11}, 6, 4, 3 },
        { {-21, -7, -1, 4, 8, 11}, 6, 8, 4 },
        { {-21, -7, -1, 4, 8, 11}, 6, -100, -1 },
        { {-21, -7, -1, 4, 8, 11}, 6, 100, -1 },
    };
    int result;

    printf("TESTING binary_search\n");

    for (int i=0; i < N_TESTCASES; i++) {
        printf("Test case %i: ", i+1);

        result = binary_search(tests[i].a, tests[i].length, tests[i].x);

        if (result == tests[i].result) {
            printf("OK\n");
        } else {
            printf("FAILED. got %d expected %d\n", result, tests[i].result);
        }
    }

    return 0;
}
