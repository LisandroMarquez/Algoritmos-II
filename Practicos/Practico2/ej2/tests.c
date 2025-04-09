#include <stdbool.h>
#include <stdio.h>
#include "cima.h"

#define MAX_LENGTH 10
#define N_TESTCASES_TIENE_CIMA 10
#define N_TESTCASES_CIMA 10

void test_tiene_cima(void);
void test_cima(void);

int main() {
    test_tiene_cima();
    test_cima();

    return 0;
}

void test_tiene_cima(void) {
    struct testcase {
        int a[MAX_LENGTH];
        int length;
        bool result;
    };

    struct testcase tests[N_TESTCASES_TIENE_CIMA] = {
        {{8}, 1, true},
        {{1, 2, 3}, 3, false},
        {{1, 2, 0}, 3, true},
        {{2, 4, 0, 1, -5}, 5, false},
        {{2, 4, 0, -3, -5}, 5, true},
        {{2, 4, 5, 17, -5}, 5, true},
        {{0, 1, 2, 3, 1, 5}, 6, false},
        {{0, 1, 7, 3, 2, -5}, 6, true},
        {{0, 8, 2, 3, 1, 5}, 6, false},
        {{3, 2, 1}, 3, false}
    };
    bool result;

    printf("TESTING tiene_cima\n");

    for (int i=0; i < N_TESTCASES_TIENE_CIMA; i++) {
        printf("Test case %i: ", i+1);

        result = tiene_cima(tests[i].a, tests[i].length);

        if (result != tests[i].result) {
            printf("FAILED\n");
        } else {
            printf("OK\n");
        }
    }
}

void test_cima(void) {
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

    printf("\nTESTING cima\n");

    for (int i=0; i < N_TESTCASES_CIMA; i++) {
        printf("Test case %i: ", i+1);

        result = cima(tests[i].a, tests[i].length);

        if (result == tests[i].result) {
            printf("OK\n");
        } else {
            printf("FAILED. got %d expected %d\n", result, tests[i].result);
        }
    }
}
