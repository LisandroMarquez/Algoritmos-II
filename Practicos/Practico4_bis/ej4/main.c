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
 * @brief Elimina el primer elemento de la lista
 *
 * Precondicion: la lista xs no debe ser vacía
 */
List tail_example(List xs) {
    Node *nodo;

    //& Node points to list
    nodo = xs;

    //! List now points from second element
    xs = nodo->next;

    //% Free node with first element
    free(nodo);

    return xs;
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

    printf("Lista antes del tail: ");

    show_list(my_list);

    my_list = tail_example(my_list);

    printf("Lista después del tail: ");

    show_list(my_list);

    return 0;
}
