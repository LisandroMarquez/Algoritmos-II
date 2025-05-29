#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

#include "list.h"

#define MAX_LENGTH 100

struct _list {
    elem a[MAX_LENGTH];
    int start;
    int size;
};

/* CONSTRUCTORS */
list empty(void) {
    list l = malloc(sizeof(list));

    l->size = 0;
    l->start = 0;

    return l;
}

list addl(elem e, list l) {    
    l->a[(l->start-1) % MAX_LENGTH] = e;
    l->size++;
    l->start--;

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
    return l->a[l->start];
}

list tail(list l) {
    //! Precondition
    assert(!is_empty(l));

    //# Actual function
    l->start++;
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
    return l->a[(n + l->start) % MAX_LENGTH];
}

list addr(list l, elem e) {
    l->a[(l->size + l->start) % MAX_LENGTH] = e;
    l->size++;

    return l;
}

list copy_list(list l) {
    list copy = empty();
    int len = length(l);

    copy->start = l->start;
    for(int i = 0; i < len; i++) {
        copy = addr(copy, l->a[(l->start + i) % MAX_LENGTH]);
    };

    return copy;
}

list concat(list l0, list l1) {
    int len1 = length(l1);

    l0->size+=l1->size;
    for(int i = 0; i < len1; i++) {
        l0 = addr(l0, l1->a[(l1->start + i) % MAX_LENGTH]);
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
