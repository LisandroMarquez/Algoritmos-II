#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

#include "list.h"

#define MAX_LENGTH 100 
 
struct _list { 
    elem elems[MAX_LENGTH]; 
    int size; 
};

/* CONSTRUCTORS */
list empty(void) {
    list l = malloc(sizeof(list));

    l->size = 0;

    return l;
}

list addl(elem e, list l) {
    for(int i = l->size; i > 0; i--) {
        l->elems[i] = l->elems[i-1];
    };
    
    l->elems[0] = e;
    l->size++;

    return l;
}

/* DESTRUCTOR */
void list_destroy(list l) {
    while (!is_empty(l)) {
        l = tail(l);
    };
}


/* OPERATIONS */
bool is_empty(list l) {
    return (l->size == 0);
}

elem head(list l) {
    //! Precondition
    assert(!is_empty(l));

    //# Actual function
    return l->elems[0];
}

list tail(list l) {
    //! Precondition
    assert(!is_empty(l));

    //# Actual function
    int len = length(l);

    for(int i = 1; i < len; i++) {
        l->elems[i-1] = l->elems[i];
    };

    l->size--;

    return l;
}

int length(list l) {
    return l->size;
}

elem index(list l, int n) {
    //! Precondition
    assert(length(l) > n);

    //# Actual function
    return l->elems[n];
}

list addr(list l, elem e) {
    l->elems[l->size] = e;
    l->size++;

    return l;
}

list copy_list(list l) {
    list copy = empty();
    int len = length(l);

    copy->size = l->size;
    for(int i = 0; i < len; i++) {
        copy->elems[i] = l->elems[i];
    };

    return copy;
}

list concat(list l0, list l1) {
    int len0 = length(l0), len1 = length(l1);

    l0->size+=l1->size;
    for(int i = 0; i < len1; i++) {
        l0->elems[len0+i] = l1->elems[len0+i];
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
    if (l->size > n) l->size = n;

    return l;
}
