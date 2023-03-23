typedef struct _gdlist_node {
	void * elem ;
	struct _gdlist_node * prev ;
	struct _gdlist_node * next ;
} gdlist_node ; 

typedef struct {
	gdlist_node head ;
	gdlist_node tail ;
	size_t elem_size ;
} gdlist ;


/** @brief Create a new gdlist object
 *
 *  Allocate a new gdlist object and initialize it with the given argument.
 *  Return the pointer of the newly allocated gdlist object.
 *
 *  @param elem_size the number of bytes of an element
 *  @param compare a pointer of the function that compares two elements.
           return 0 if e1 and e2 are equal, a negative integer if e1 precedes e2, 
		   a positive integer if e2 precedes e1.
 */
gdlist * gdlist_alloc (size_t elem_size, int (* compare)(void *e1, void *e2)) ;



/** @brief Deallocate the given gdlist object
 * 
 *  Deallocate the memory of the gdlist object along with all gdlist_node 
 *  objects contained in the list.
 *
 *  @param l a gdlist object to free
 */
void gdlist_free (gdlist * l) ;



/** @brief Count the number of the elements in the list
 * 
 *  Count the number of the gdlist elements in the given list.
 *
 *  @param l a gdlist object 
 *  @return The number of the gdlist elements in the list, thus
            it is zero or a positive integer.
 */
int gdlist_length (gdlist * l) ;


/** @brief Get the first index of an element that satifies the given condition
 * 
 *  Search for an element that satisfies the condition specifieid as elem_cond 
 *  from the head to tail, and return the first index.
 *
 *  @param l a gdlist object 
 *  @param elem_cond the pointer of a function that returns 1 if element e 
           satifies the search condition. Return 1 if satisfied, otherwise 0.
 *  @return the index of the first element that satifies the search condition.
 */
int gdlist_search (gdlist * l, int (* elem_cond)(void * e)) ;


/** @brief Insert a given element to the list
 * 
 *  Find the location to place the given element using elem_compare,
 *  and add a new gdlist_node entry to the location.
 *
 *  @param l a gdlist object 
 *  @param e the pointer of the newly given element.
 *  @return 1 if succeed, 0 otherwise.
 */
int gdlist_add (gdlist * l, void * e) ;


/** @brief Retrieve the element at a given index, and remove it from the list
 * 
 *  If the given index is valid, transfer the element at the index to
 *  the given memory location. And then, delete the node from the list
 *
 *  @param l a gdlist object 
 *  @param i the index of an element to retrieve and remove
 *  @param e the pointer of a memory location to store the target element
 *  @return 1 if succeed, 0 otherwise.
 */
int gdlist_remove (gdlist * l, int i, void * e) ;


/** @brief Print out the elements in the given list
 *
 *  Print each element in the list in sequence, by calling elem_print
 *
 *  @param l a gdlist object 
 *  @param elem_print the pointer of a function that prints the content of
           an element e to standard output
 */
void gdlist_print (gdlist * l, void (* elem_print)(void * e)) ;


/** @brief Create a new list that contains all elements of the two lists
 * 
 *  Create a new gdlist that contains all elements of the two lists.
 *  The time complexity of this function must be a linear function of
 *  the number of the elements from the two lists.
 *
 *  @param l1 a given gdlist
 *  @param l2 a given gdlist
 *  @return the pointer of the newly created merged list
 */
gdlist * gdlist_merge(gdlist * l1, gdlist * l2) ;

