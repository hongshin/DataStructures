# Lab 2. Linked List

Each team is asked to implement missing operations of `strlist.c` in the `lab2` repository.
You must submit the result by 6:50 PM Mar 14 to the `lab2' entry in HDLMS.
The TA will arrange the review meeting, and you must pass the review by the end of this week.

### Tasks

1. Function `int strlist_add_last (strlist * l, char * s)`
    The expected behavior of `int strlist_add_last (strlist * l, char * s)` is as follows:
    > Insert a string to the end of list `l`. Return `1` if the insertion succeed. Otherwise, return `0`.

    Write a test case, and then a function definition of `int strlist_add_last (strlist * l, char * s)`.

1. Function `int strlist_search (strlist * l, char * s, int i)`
    The expected behavior of `int strlist_search (char * s, int i)` is as follows:
    > Return the index of (`i`+1)-th appearance of `s` in list `l`. Return the index, or `-1` if there is no corresponding element in the list.

    Write a test case, and then a function definition of `int strlist_search (strlist * l, char * s, int i)`.

1. Function `int strlist_remove (strlist * l, int i, char **s)`
    The expected behavior of `int strlist_remove (strlist * l, int i, char **s)` is as follows:
    > Remove the element at index `i` from `l` while assinging the stored value to the location pointed by `s`.
    
    Write a test case, and then a function definition of `int strlist_remove (strlist * l, int i, char **s)`.
