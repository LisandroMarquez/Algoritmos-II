/*
  @file main.c
  @brief Main program function implementation
*/
#include <stdio.h>
#include <stdlib.h>

/** @brief structure which represent a person */
typedef struct _person {
    int age;
    char name_initial;
} person_t;

/**
 * @brief Main program function
 *
 * @return EXIT_SUCCESS when programs executes correctly, EXIT_FAILURE otherwise
 */
int main(void) {

    int x = 1;
    person_t m = {90, 'M'};
    int a[] = {0, 1, 2, 3};

    /* Completar aquí:
       Al finalizar la ejecución las variables deben tener los siguientes valores
       x = 9
       m = (100, F)
       a[1] = 42

       Las restricciones son:
       - No usar las variables 'x', 'm' y 'a' en la parte izquierda de alguna asignación.
       - Se pueden agregar líneas de código, pero no modificar las que ya existen.
       - Se pueden declarar hasta 2 punteros.
       AYUDA: podes usar GDB para consultares valores de variables y la dirección de memoria donde estan alojadas.
    */

    int *p = NULL; //! Crear puntero
    person_t *q = NULL;

    p = &x; //# Seleccionar a que dato apunta
    *p = 9; //% Cambiar valor en el lugar de referenciaci�n

    q = &m; //# Seleccionar a que dato apunta
    q->age = 100; //% Cambiar valor en el lugar de referenciaci�n
    q->name_initial = 'F'; //% Cambiar valor en el lugar de referenciaci�n

    p = &a[1]; //# Seleccionar a que dato apunta
    *p = 42; //% Cambiar valor en el lugar de referenciaci�n


    printf("x = %d\n", x);
    printf("m = (%d, %c)\n", m.age, m.name_initial);
    printf("a[1] = %d\n", a[1]);

    return EXIT_SUCCESS;
}

