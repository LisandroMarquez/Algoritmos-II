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

    show_list(my_list);

    return 0;
}
