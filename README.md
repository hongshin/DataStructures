# Programming Assignment 3. Heap

### Attributes
* Type: Individual work (you cannot collaborate with other students)
* Due date: 5:00 PM, Tue 23 May 2023 KST
* Rules: Only the C programming language reference, the earlier lab results, and the main textbook are allowed for your reference in doinig this homework. You are not allowed to see existing source code and to use other programming assistant tools; You must write down all source code by yourself.

### Description

You are asked to add the following three API functions to the given C implementation of heap:

1. ``void heap_print (heap_t * h, char * (* elem_print)(void * e))`` 

Function ``heap_print`` draws the structure of heap ``h`` by travesing the tree in the inorder manner.
A given function ``elem_print`` is to return a string for representing an element. For example, the following function, ``print_person`` may be given for the example of ``main.c``:
```
char * print_person (void * e) 
{
	person_t * p = (person_t *) e ;
	return p->name ;
}
```

For a heap with ``Tim``, ``Ken``, ``Ali``, ``Chen`` and ``John``, ``heap_print`` must print a text like the following:
```
             John
     Ken          Ali
Chen     Tim
```

2. ``int heap_delete (heap_t * h, void * e)``

This function deletes an element of the heap if its data is the exactly the same as that of ``e``. Note that this element may not be placed in the root, but it may exist in any node of the heap. Return 1 if an element is deleted. Otherwise, return 0.

### Submission instruction

You must record a video that explain your code and show the demo of the program execution. The video must not exceed 4 minutes. Upload your video to a streaming service such as YouTube, and then submit the link.

Submit your result to HDLMS by the submission deadline. No late submission will be accepted.
Your results will be evaluated by test cases, and also you may take in-person interview if needed. 
