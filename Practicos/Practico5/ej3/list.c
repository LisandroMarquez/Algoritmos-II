#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

/* CONSTRUCTORS */
list empty(void) {
    list l = NULL;

    return l;
}

list addl(list_elem e, list l) {
    Node *p;
    p = malloc(sizeof(Node));

    p->elem = e;
    p->next = l;

    return p;
}

/* DESTRUCTOR */
void list_destroy(list l) {
    while (!list_is_empty(l)) {
        l = tail(l);
    };
}


/* OPERATIONS */
bool list_is_empty(list l) {
    return (l == NULL);
}

list_elem head(list l) {
    //! Precondition
    assert(!list_is_empty(l));

    //# Actual function
    return l->elem;
}

list tail(list l) {
    //! Precondition
    assert(!list_is_empty(l));

    //# Actual function
    Node *p = l;
    l = l->next;

    free(p);

    return l;
}

int list_length(list l) {
    Node *p = l;
    int n = 0;

    while (p->next != NULL) {
        n++;
        p = p->next;
    };

    return n + 1;
}

list_elem index(list l, int n) {
    //! Precondition
    assert(list_length(l) > n);

    //# Actual function
    Node *p = l;
    int i = 0;

    while (i < n) {
        i++;
        p = p->next;
    };

    return p->elem;
}

list addr(list l, list_elem e) {
    Node *p, *q;

    q = malloc(sizeof(Node));

    q->elem = e;
    q->next = NULL;

    if (list_is_empty(l)) l = q;
    else {
        p = l;

        while (p->next != NULL) {
            p = p->next;
        };

        p->next = q;
    };

    return l;
}

list copy_list(list l) {
    Node *p = l;
    list l1 = empty();

    while (p != NULL) {
        addr(l1, p->elem);
        p = p->next;
    };

    return l1;
}

list concat(list l0, list l1) {
    Node *p = l1;
    
    while (p != NULL) {
        addr(l0, p->elem);
        p = p->next;
    };

    return l0;
}

list drop(list l, int n) {
    int i = 0;

    while (i < n && !list_is_empty(l)) {
        tail(l);
        i++;
    };

    return l;
}

list take(list l, int n) {
    Node *p = l, *q;
    int i = 0;

    while (i < n && !list_is_empty(l)) {
        p = p->next;
        i++;
    };

    while (p->next != NULL) {
        q = p;
        p = p->next;
        free(q);
    };

    free(p);

    return l;
}
