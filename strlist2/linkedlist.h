template<class T> class ListNode ;
template<class T> class LinkedList ;

template <class T>
class ListNode {
	private:
		T elem ;
		ListNode * prev ;
		ListNode * next ;

		friend class LinkedList<T> ;

	public:
		ListNode () ;
		ListNode (const T * elem) ;
		~ListNode () ;

		void print () ;
	
} ;


template <class T>
class LinkedList {
	private:
		ListNode<T> head ;
		ListNode<T> tail ;
		int length ;
		
	
	public:
		LinkedList() ;
		~LinkedList() ;

		int addFirst (const T * src) ;
		int addLast (const T * src) ;

		int removeFirst (T * dst) ;
		int removeLast (T * dst) ;

		void print () ;
} ;


template <class T>
ListNode<T>::ListNode () 
{
	prev = 0x0 ;
	next = 0x0 ;
}

template <class T>
ListNode<T>::ListNode (const T * elem) 
{
	//this->elem = elem ;
	this->elem = *elem ;
}

template <class T>
ListNode<T>::~ListNode ()
{
}

template <class T>
void ListNode<T>::print ()
{
	std::cout << "[" << this->elem << "]" ;
}

/**/

template <class T>
LinkedList<T>::LinkedList () 
{
	head.prev = 0x0 ; 
	head.next = &(tail) ;

	tail.prev = &(head) ;
	tail.next = 0x0 ;

	length = 0 ;
}

template <class T>
LinkedList<T>::~LinkedList () 
{
	ListNode<T> * i ;

	i = head.next ;
	while (i != &tail) {
		ListNode<T> * c ;
		c = i ;
		i = i->next ; 
		delete c ;
	}
}

template <class T>
int LinkedList<T>::addFirst (const T * s) 
{
	ListNode<T> * n = new ListNode<T>(s) ;

	n->prev = &head ;
	n->next = head.next ;
	head.next->prev = n ;
	head.next = n ;

	return 1 ;
}

template <class T>
int LinkedList<T>::addLast (const T * s)
{
	ListNode<T> * n = new ListNode<T>(s) ;

	n->next = &tail ;
	n->prev = tail.prev ;

	tail.prev->next = n ;
	tail.prev = n ;

	return 1 ;
}

template <class T>
int LinkedList<T>::removeFirst (T * s) 
{
	if (head.next == &tail)
		return 0 ;

	ListNode<T> * n ;

	n = head.next ;

	head.next = n->next ;
	n->next->prev = &head ;

	*s = n->elem ;
	delete n ;

	return 1 ;
}

template <class T>
int LinkedList<T>::removeLast (T * s) 
{
	if (head.next == &tail)
		return 0 ;

	ListNode<T> * n ;

	n = tail.prev ; 

	tail.prev = n->prev ;
	n->prev->next = &tail ;

	*s = n->elem ;

	delete n ;

	return 1 ;
}

template <class T>
void LinkedList<T>::print () 
{
	ListNode<T> * i ;
	for (i = head.next ; i != &tail ; i = i->next) {
		//std::cout << *i << " " ;
		i->print() ;
		std::cout << " " ;
	}
	std::cout << std::endl ;
}
