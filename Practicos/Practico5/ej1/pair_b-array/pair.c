#include "pair.h"    /* TAD Par         */

pair_t pair_new(int x, int y) {
    pair_t p;
    p.values[0] = x;
    p.values[1] = y;

    return p;
}

int pair_first(pair_t p) {
    return p.values[0];
}

int pair_second(pair_t p) {
    return p.values[1];
}

pair_t pair_swapped(pair_t p) {
    pair_t q;
    q.values[0] = p.values[1];
    q.values[1] = p.values[0];

    return q;
}

pair_t pair_destroy(pair_t p) {
    return p;
}