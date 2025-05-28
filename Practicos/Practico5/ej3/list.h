#ifndef _LIST_H
#define _LIST_H

#include <stdbool.h>


/* Specification */
 typedef int list_elem;

typedef struct _Node
{
    list_elem elem;
    struct _Node* next;

} Node;

typedef Node * list;


/* CONSTRUCTORS */
list empty(void);
/*
    Create a new empty list.
    Being c the returned list, list_is_empty(c) should be true.
*/

list addl(list_elem e, list l);
/*
    Adds an element e at the start the List l
*/


/* DESTRUCTOR */
void list_destroy(list l);
/*
   Frees memory.
*/


/* OPERATIONS */
bool list_is_empty(list l);
/*
    Return whether the list c has no elem.
*/

list_elem head(list l);
/*
    Returns the first element of the list l
    PRE: not list_is_empty(l)
*/

list tail(list l);
/*
    Delete the first element of the list l
    PRE: not list_is_empty(l)
*/

int list_length(list l);
/*
    Returns the length of the list l
*/

list_elem index(list l, int n);
/*
    Returns the element in the index n of the list l
    PRE: length(l) > n
*/

void addr(list l, list_elem e);
/*
    Adds an element e at the end the List l
*/

list copy_list(list l);
/*
    Copy the list l into a new list l0
*/

void concat(list l0, list l1);
/*
    Adds all elements in list l1 to the end of list l0
*/

void drop(list l, int n);
/*
    Drops first n elements
*/

void take(list l, int n);
/*
    Drops all elements in position < n
*/

#endif