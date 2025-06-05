#include <stdbool.h>
#include <stdio.h>
#include "first_zero.h"

#define MAX_LENGTH 10
#define N_TESTCASES 9

int main(void) {
    struct testcase {
        int a[MAX_LENGTH];
        int length;
        int result;
    };

    struct testcase tests[N_TESTCASES] = {
        // arreglo, largo, resultado
        { {0}, 1, 0 },
        { {1}, 1, -1 },
        { {0, 0}, 2, 0 },
        { {1, 0}, 2, 1 },
        { {1, 1}, 2, -1 },
        { {0, 0, 0}, 3, 0 },
        { {1, 0, 0}, 3, 1 },
        { {1, 1, 0}, 3, 2 },
        { {1, 1, 1}, 3, -1 },
    };
    int result;

    printf("TESTING first_zero\n");

    for (int i=0; i < N_TESTCASES; i++) {
        printf("Test case %i: ", i+1);

        result = first_zero(tests[i].a, tests[i].length);

        if (result == tests[i].result) {
            printf("OK\n");
        } else {
            printf("FAILED. got %d expected %d\n", result, tests[i].result);
        }
    }

    return 0;
}
