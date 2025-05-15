#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef Node *List;

/**
 * @brief Construye y devuelve una lista de ejemplo de 3 elementos
 */
List setup_example() {
    int length = 2;
    List lista;
    Node *nodo;

    //% Alloc needed memory for the list
    lista = malloc((length + 1) * sizeof(Node));
    nodo = lista;

    //& Fill the list with data
    while (length > 0) {
        nodo->data = length * 10;

        //% Alloc memory for the next node
        nodo->next = malloc(sizeof(Node));
        nodo = nodo->next;
        length--;
    }

    //& Add last element
    nodo->data = 0;
    nodo->next = NULL;
    nodo = NULL;

    //% Free memory
    free(nodo);

    return lista;
}

/**
 * @brief Agrega un elemento de ejemplo al final de la lista
 *
 * Precondicion: la lista xs no debe ser vacía
 */
void append_example(List xs) {
    Node *nodo = xs;

    //& Go to the last node
    while (nodo->next != NULL) nodo = nodo->next;

    //% Alloc needed memory
    nodo->next = malloc(sizeof(Node));
    
    //& Fill with data
    nodo->next->data = 88;
    nodo->next->next = NULL;
}

void show_list(List xs) {
    printf("[ ");
    while (xs != NULL) {
        printf("%i, ", xs->data);
        xs = xs->next;
    }
    printf("]\n");
}

int main(void) {
    List my_list;

    my_list = setup_example();

    printf("Lista antes del append: ");

    show_list(my_list);

    append_example(my_list);

    printf("Lista después del append: ");

    show_list(my_list);

    return 0;
}
