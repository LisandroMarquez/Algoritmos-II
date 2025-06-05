#include <limits.h>
#include <stdio.h>
#include "change.h"

#define MIN(a, b) ((a) < (b) ? (a) : (b))

void print_table(int n, int k, int table[n][k]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            if (table[i][j] == INT_MAX) {
                printf("INF\t");
            } else {
                printf("%d\t", table[i][j]);
            }
        }
        printf("\n");
    }
}

/**
 * @brief Resuelve el problema de la moneda
 *
 * @param d denominaciones
 * @param n cantidad de denominaciones
 * @param k monto a pagar
 */
int change(int d[], int n, int k) {
    int cam[n+1][k+1];
    
    for (int i = 0; i <= n; i++) { cam[i][0] = 0; }

    for (int j = 1; j <= k; j++) { cam[0][j] = INT_MAX; }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (d[i-1] > j) {
                cam[i][j] = cam[i-1][j];
            } else {
                cam[i][j] = MIN(cam[i-1][j], 1 + cam[i][j - d[i-1]]);
            }
        }
    }

    //print_table(n, k, minimos); //debugger
    
    return cam[n][k];
}
