#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "data.h"

void print_data(data_t d) {
    printf("NOMBRE: %s\n"
           "EDAD  : %d años\n"
           "ALTURA: %d cm\n\n",
           d.name, d.age, d.height);
}

int main(void) {

    data_t messi = {"Leo Messi", 36, 169};
    print_data(messi);

    printf("name-size  : %lu bytes, name-dir  : %p\n"
        "age-size   : %lu bytes, age-dir   : %p\n"
        "height-size: %lu bytes, height-dir: %p\n"
        "data_t-size: %lu bytes, data_t-dir: %p\n\n",
        sizeof(messi.name), (void *) &messi.name,
        sizeof(messi.age), (void *) &messi.age, 
        sizeof(messi.height), (void *) &messi.height, 
        sizeof(messi), (void *) &messi);
    
    data_t *p = NULL;
    p = malloc(sizeof(data_t));
    *p = messi;

    print_data(*p);
    printf("name-size  : %lu bytes, name-dir  : %p\n"
        "age-size   : %lu bytes, age-dir   : %p\n"
        "height-size: %lu bytes, height-dir: %p\n"
        "data_t-size: %lu bytes, data_t-dir: %p\n\n",
        sizeof(p->name), (void *) &p->name,
        sizeof(p->age), (void *) &p->age, 
        sizeof(p->height), (void *) &p->height, 
        sizeof(p), (void *) p);
    
    free(p);

    return EXIT_SUCCESS;
}
