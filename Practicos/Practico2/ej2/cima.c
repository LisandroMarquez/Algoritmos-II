#include <stdio.h>
#include <stdbool.h>
#include "cima.h"

/**
 * @brief Indica si el arreglo tiene cima.
 *
 * Un arreglo tiene cima si existe una posición k tal que el arreglo es
 * estrictamente creciente hasta la posición k y estrictamente decreciente
 * desde la posición k.
 *
 * @param a Arreglo.
 * @param length Largo del arreglo.
 */
bool tiene_cima(int a[], int length) {
    bool flag = false;
    if (length < 3) flag = false;
    if (length == 1) flag = true;
    
    for (int i = 1; i < length - 1; i++) {
        if (a[i-1] < a[i] && a[i] > a[i+1]) {
            // Verificar parte creciente
            bool valido = true;
            for (int j = 1; j < i && valido; j++) {
                if (a[j-1] >= a[j]) valido = false;
            }
            // Verificar parte decreciente
            for (int j = i + 1; j < length && valido; j++) {
                if (a[j-1] <= a[j]) valido = false;
            }
            if (valido) flag = true;
        }
    }
    
    return flag;
}

/**
 * @brief Dado un arreglo que tiene cima, devuelve la posición de la cima.
 *
 * Un arreglo tiene cima si existe una posición k tal que el arreglo es
 * estrictamente creciente hasta la posición k y estrictamente decreciente
 * desde la posición k.
 * La cima es el elemento que se encuentra en la posición k.
 * PRECONDICION: tiene_cima(a, length)
 *
 * @param a Arreglo.
 * @param length Largo del arreglo.
 */
int cima(int a[], int length) {
    int num;
    
    if (length == 1 || length == 2) num = 0;
    else if (length > 2) {
        for (int i = 1; i < length - 1; i++) {
            if (a[i-1] < a[i] && a[i] > a[i+1]) {
                // Verificar parte creciente
                bool valido = true;
                for (int j = 1; j < i && valido; j++) {
                    if (a[j-1] >= a[j]) valido = false;
                }
                // Verificar parte decreciente
                for (int j = i + 1; j < length && valido; j++) {
                    if (a[j-1] <= a[j]) valido = false;
                }
                if (valido) num = i;
            }
        }
    }

    return a[num];
}