
// a: the pointer to the array of elements to sort
// len: the number of elements in the array
// unit: the size of an element
// comparator: returns a negative integer if the value at e1 precedes the value at e2,
//		return a positive integer if the value at e2 precedes the value at e1,
//		returns 0 if the two values are equivalent,  

void generic_merge_sort (void * a, int n_a, int unit, int (* cmp)(void * e1, void * e2)) ;

