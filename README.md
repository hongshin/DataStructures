# Lab 1. Array List

In this lab, each team is asked to complete an array list implementation in the `lab1` repository. 

Submit your results by 7:00 PM Mar 7 to the `lab1` entry in the HLMS homework submission site.

### Tasks

1. Write down a function definition of `int gelist_remove(gelist * l, int i, gentry *e)`
    The expected behavior of `int gelist_remove(gelist * l, int i, gentry *e)` is specified as follows:
    > Remove an element at index `i`. The value of the removed element is assigned to the memory pointed by `e`. Return `1` if an element is removed and returned. Otherwise, return `0`.
     
    Update `main.c` to demonstrate that your implementation works correctly.

2. Write down a function definition of `int gelist_search_by_name(gelist * l, char * name)`
    The expected behavior of `int gelist_search_by_name(gelist * l, char * name)` is specified as follows:
    > Return the first index of an element whose name is equal to name. Return `-1` if no element with name exists.
     
    Update `main.c` to demonstrate that your implementation works correctly.

3. Write down a function definition of `int gelist_remove_by_name(gelist * l, char * name, gentry * e)`
    The expected behavior of `int gelist_remove_by_name(gelist * l, char * name, gentry * e)` is specified as follows:
    > Remove the first element whose name is equal to name from list `l`. The value of the removed element is assigned to the memory pointed by `e`. Return `1` if an element is removed and returned. Otherwise, return `0`.
     
    Update `main.c` to demonstrate that your implementation works correctly.

4. Create a new function `gelist * gelist_merge(gelist *l1, gelist *l2)`
    Add a function `gelist * gelist_merge(gelist *l1, gelist *l2)` to the array list implementation. The expected behavior of this function is as follows:
    > Return a new `gelist` object that contains all elements in `l1` and `l2`.
     
    Update `gelist.h` and `main.c` to demonstrate that your implementation works correctly.