#include "pair.h"    /* TAD Par         */


pair_t pair_new(int x, int y) {
    pair_t pair;
    pair.fst = x;
    pair.snd = y;

    return pair;
}

int pair_first(pair_t p) {
    return p.fst;
}

int pair_second(pair_t p) {
    return p.snd;
}

pair_t pair_swapped(pair_t p) {
    pair_t q;
    q.snd = pair_first(p);
    q.fst = pair_second(p);

    return q;
}

pair_t pair_destroy(pair_t p) {
    return p;
}