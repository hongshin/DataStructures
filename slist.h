typedef struct _slist_node {
	void * elem ;
	struct _slist_node * prev ;
	struct _slist_node * next ;
} slist_node ; 

typedef struct {
	slist_node head ;
	slist_node tail ;
	size_t elem_size ;
        int (* elem_compare)(void * p1, void * p2) ;
} slist ;


/** @brief Create a new slist object
 *
 *  Allocate a new slist object and initialize it with the given argument.
 *  Return the pointer of the newly allocated slist object.
 *
 *  @param elem_size the number of bytes of an element
 *  @param compare a pointer of the function that compares two elements.
           return 0 if e1 and e2 are equal, a negative integer if e1 precedes e2, 
		   a positive integer if e2 precedes e1.
 */
slist * slist_alloc (size_t elem_size, int (* compare)(void *e1, void *e2)) ;



/** @brief Deallocate the given slist object
 * 
 *  Deallocate the memory of the slist object along with all slist_node 
 *  objects contained in the list.
 *
 *  @param l a slist object to free
 */
void slist_free (slist * l) ;



/** @brief Count the number of the elements in the list
 * 
 *  Count the number of the slist elements in the given list.
 *
 *  @param l a slist object 
 *  @return The number of the slist elements in the list, thus
            it is zero or a positive integer.
 */
int slist_length (slist * l) ;


/** @brief Get the first index of an element that satifies the given condition
 * 
 *  Search for an element that satisfies the condition specifieid as elem_cond 
 *  from the head to tail, and return the first index.
 *
 *  @param l a slist object 
 *  @param elem_cond the pointer of a function that returns 1 if element e 
           satifies the search condition. Return 1 if satisfied, otherwise 0.
 *  @return the index of the first element that satifies the search condition.
 */
int slist_search (slist * l, int (* elem_cond)(void * e)) ;


/** @brief Insert a given element to the list
 * 
 *  Find the location to place the given element using elem_compare,
 *  and add a new slist_node entry to the location.
 *
 *  @param l a slist object 
 *  @param e the pointer of the newly given element.
 *  @return 1 if succeed, 0 otherwise.
 */
int slist_add (slist * l, void * e) ;


/** @brief Retrieve the element at a given index, and remove it from the list
 * 
 *  If the given index is valid, transfer the element at the index to
 *  the given memory location. And then, delete the node from the list
 *
 *  @param l a slist object 
 *  @param i the index of an element to retrieve and remove
 *  @param e the pointer of a memory location to store the target element
 *  @return 1 if succeed, 0 otherwise.
 */
int slist_remove (slist * l, int i, void * e) ;


/** @brief Print out the elements in the given list
 *
 *  Print each element in the list in sequence, by calling elem_print
 *
 *  @param l a slist object 
 *  @param elem_print the pointer of a function that prints the content of
           an element e to standard output
 */
void slist_print (slist * l, void (* elem_print)(void * e)) ;


/** @brief Create a new list that contains all elements of the two lists
 * 
 *  Create a new slist that contains all elements of the two lists.
 *  The time complexity of this function must be a linear function of
 *  the number of the elements from the two lists.
 *  If l1 and l2 have different element sizes or different elem_compare
 *  functions, they cannot be merged, thus for this case, this function 
 *  returns NULL
 *
 *  @param l1 a given slist
 *  @param l2 a given slist
 *  @return the pointer of the newly created merged list
 *          NULL if l1 and l2 are not compatible.
 */
slist * slist_merge(slist * l1, slist * l2) ;
