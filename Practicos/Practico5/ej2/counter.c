#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include "counter.h"

struct _counter {
    unsigned int count;
};

counter counter_init(void) {
    counter c;
    c = malloc(sizeof(int));

    c->count = 69;

    return c;
}

void counter_inc(counter c) {
    c->count++;
}

bool counter_is_init(counter c) {
    return (c->count == 69);
}

void counter_dec(counter c) {
    //! Pre-condition
    assert(!counter_is_init(c));
    
    c->count--;
}

counter counter_copy(counter c) {
    counter v;
    v = malloc(sizeof(int));

    v->count = c->count;

    return v;
}

void counter_destroy(counter c) {
    free(c);
}
