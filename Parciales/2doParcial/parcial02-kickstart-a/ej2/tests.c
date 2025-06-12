#include "list.h"
#include "remove.h"

#include <stdbool.h>
#include <stdio.h>

#define MAX_LENGTH 10
#define N_TESTCASES_REMOVE 8

// construye una lista a partir de un arreglo
// (usa los constructores de lista empty y addl)
list array_to_list(int array[], int length) {
    list result;
    result = empty();

    // agregamos al revés ya que usamos addl
    for (int i = length; i > 0; i--) {
        result = addl(array[i-1], result);
    }

    return result;
}

// chequea si dos listas son iguales
// (usa las funciones de listas length e index)
bool is_equal_to(list l1, list l2) {
    int len1 = length(l1);
    int len2 = length(l2);
    int i = 0;
    while (i < len1 && i < len2 && index(l1, i) == index(l2, i)) {
        i++;
    }
    return i == len1 && len1 == len2;
}

// Testeo de la función remove_elem()
void test_remove_elem() {
    // representación de un solo caso de test
    struct remove_elem_testcase {
        int l[MAX_LENGTH];       // elementos de la lista de entrada
        int length;              // largo de la lista de entrada
        elem e;                  // elemento a eliminar
        int result[MAX_LENGTH];  // elementos esperados de la lista resultado
        int result_length;       // largo esperado de la lista resultado
    };

    // casos de test (uno por línea)
    struct remove_elem_testcase tests[N_TESTCASES_REMOVE] = {
      { {}, 0, 42, {}, 0 },
      { {7}, 1, 42, {7}, 1 },
      { {42}, 1, 42, {}, 0 },
      { {7, 7}, 2, 42, {7, 7}, 2 },
      { {7, 42}, 2, 42, {7}, 1 },
      { {42, 7}, 2, 42, {7}, 1 },
      { {42, 42}, 2, 42, {}, 0 },
      { {7, 42, 9}, 3, 42, {7, 9}, 2 },
    };

    list l, l_copy, result, expected_result;

    printf("TESTING remove_elem\n");

    for (int i=0; i < N_TESTCASES_REMOVE; i++) {
        printf("Test case %i: ", i+1);

        // creamos la lista de entrada y el resultado esperado
        l = array_to_list(tests[i].l, tests[i].length);
        expected_result = array_to_list(tests[i].result, tests[i].result_length);

        // TEST! llamamos la función a testear
        result = remove_elem(l, tests[i].e);

        // chequeamos:
        // 1. el resultado obtenido es el resultado esperado
        bool result_ok = is_equal_to(result, expected_result);
        destroy_list(expected_result);
        destroy_list(result);

        // 2. la lista original sigue intacta
        l_copy = array_to_list(tests[i].l, tests[i].length);
        bool input_ok = is_equal_to(l, l_copy);
        destroy_list(l);
        destroy_list(l_copy);

        if (result_ok && input_ok) {
            printf("OK\n");
        } else if (!result_ok) {
            printf("FAILED: incorrect result\n");
        } else {
            printf("FAILED: input modified\n");
        }
    }
}

int main() {
    test_remove_elem();

    return 0;
}
