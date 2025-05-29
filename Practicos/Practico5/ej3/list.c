#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

/* CONSTRUCTORS */
list empty(void) {
    list l = NULL;

    return l;
}

list addl(elem e, list l) {
    Node *p;
    p = malloc(sizeof(Node));

    p->elem = e;
    p->next = l;

    return p;
}

/* DESTRUCTOR */
void list_destroy(list l) {
    while (!is_empty(l)) {
        l = tail(l);
    };
}


/* OPERATIONS */
bool is_empty(list l) {
    return (l == NULL);
}

elem head(list l) {
    //! Precondition
    assert(!is_empty(l));

    //# Actual function
    return l->elem;
}

list tail(list l) {
    //! Precondition
    assert(!is_empty(l));

    //# Actual function
    Node *p = l;
    l = l->next;

    free(p);

    return l;
}

int length(list l) {
    Node *p = l;
    int n = 0;

    while (p != NULL) {
        n++;
        p = p->next;
    };

    return n;
}

elem index(list l, int n) {
    //! Precondition
    assert(length(l) > n);

    //# Actual function
    Node *p = l;
    int i = 0;

    while (i < n) {
        i++;
        p = p->next;
    };

    return p->elem;
}

list addr(list l, elem e) {
    Node *p, *q;

    q = malloc(sizeof(Node));

    q->elem = e;
    q->next = NULL;

    if (is_empty(l)) l = q;
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
        l = addr(l1, p->elem);
        p = p->next;
    };

    return l1;
}

list concat(list l0, list l1) {
    Node *p = l1;
    
    while (p != NULL) {
        l0 = addr(l0, p->elem);
        p = p->next;
    };

    return l0;
}

list drop(list l, int n) {
    int i = 0;

    while (i < n && !is_empty(l)) {
        l = tail(l);
        i++;
    };

    return l;
}

list take(list l, int n) {
    Node *p = l, *q, *r;
    int i = 1;

    if (n <= 0 || l == NULL) {
        list_destroy(l);
        l = empty();
    }
    else {
        while (i < n && p->next != NULL) {
            p = p->next;
            i++;
        };

        q = p->next;
        p->next = NULL;

        while (q != NULL) {
            r = q;
            q = q->next;
            free(r);
        };
    }

    return l;
}
