#include <stdbool.h>
#include <stdio.h>
#include "cima_log.h"

#define MAX_LENGTH 10
#define N_TESTCASES_CIMA 10

int main() {
    struct testcase {
        int a[MAX_LENGTH];
        int length;
        int result;
    };

    struct testcase tests[N_TESTCASES_CIMA] = {
        {{8}, 1, 8},
        {{1, 2, 0}, 3, 2},
        {{1, 2, 1}, 3, 2},
        {{2, 4, 1, 0, -5}, 5, 4},
        {{2, 4, 0, -3, -5}, 5, 4},
        {{2, 4, 5, 17, -5}, 5, 17},
        {{0, 1, 2, 3, 1, -5}, 6, 3},
        {{0, 1, 7, 3, 2, -5}, 6, 7},
        {{0, 8, 7, 3, 1, -5}, 6, 8},
        {{1, 3, 1}, 3, 3}
    };
    int result;

    printf("TESTING cima\n");

    for (int i=0; i < N_TESTCASES_CIMA; i++) {
        printf("Test case %i: ", i+1);

        result = cima_log(tests[i].a, tests[i].length);

        if (result == tests[i].result) {
            printf("OK\n");
        } else {
            printf("FAILED. got %d expected %d\n", result, tests[i].result);
        }
    }

    return 0;
}
