# Lab 3. Generic Linked List

Lab 3 is to extend `glist.c` to proivde three operations in addition.
Each team must submit the result by 6:50 PM Mar 21 to the `lab3' entry in HDLMS.

### Tasks

1. Function `int glist_add_last (glist * l, void * s)`
    The expected behavior of this function is as follows:
    > Insert a given object `s` to the end of list `l`. Return `1` if the insertion succeed. Otherwise, return `0`.

    Write a test case, and then a function definition of `int glist_add_last (glist * l, void * s)`.

1. Function `int glist_search (glist * l, void * s, int (* elem_cond)(void *s))`
    The expected behavior of this function is as follows:
    > Function `elem_cond` should be a function that returns 1 if and only if the element at `s` satisfies a search condition.
	> Return the index of the first occurance of an element that satisfies the search condition in list `l`. 
	> Return the index, or `-1` if there is no corresponding element in the list.

    Write a test case, and then a function definition of `int glist_search (glist * l, int (* elem_cond)(void *s))`.

1. Function `int glist_remove (glist * l, int i, void * s)`
    The expected behavior of this function is as follows:
    > Remove the element at index `i` from `l` while assinging the stored value to the location pointed by `s`.
    
    Write a test case, and then a function definition of `int glist_remove (strlist * l, int i, int (* elem_cond)(void * s))`.
