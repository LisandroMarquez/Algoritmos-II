#ifndef _FIRST_ZERO_H
#define _FIRST_ZERO_H

/**
 * @brief Posición del primero cero en un arreglo de la forma [1, 1, ... , 1, 0, 0, ..., 0].
 * 
 * Dado un arreglo de la forma [1, 1, ... , 1, 0, 0, ..., 0], devolver la
 * posición del primer elemento que es un cero (0). Si no hay ningún cero,
 * devolver -1. La búsqueda se realiza usando una estrategia divide y vencerás
 * de complejidad O(log n).
 *
 * @param a Arreglo de forma [1, 1, ... , 1, 0, 0, ..., 0].
 * @param length Largo del arreglo.
 */
int first_zero(int a[], int length);

#endif // _FIRST_ZERO_H
