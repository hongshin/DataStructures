#include <cstdlib>
#include <iostream>
#include <string.h>
#include "linkedlist.h"

template <typename T>
ListNode<T>::ListNode () 
{
	elem = 0x0 ;
	prev = 0x0 ;
	next = 0x0 ;
}

template <typename T>
ListNode<T>::ListNode (T elem) 
{
	this->elem = elem ;
	//*(this->elem) = *elem ;
}

template <typename T>
ListNode<T>::~ListNode ()
{
}

template <typename T>
void ListNode<T>::print ()
{
	std::cout << "[" << this->elem << "]" ;
}

LinkedList::LinkedList() 
{
	head.prev = 0x0 ; 
	head.next = &(tail) ;

	tail.prev = &(head) ;
	tail.next = 0x0 ;

	length = 0 ;
}

StrList::~StrList () 
{
	StrListNode * i ;

	i = head.next ;
	while (i != &tail) {
		StrListNode * c ;
		c = i ;
		i = i->next ; 
		delete c ;
	}
}

int StrList::addFirst (const char * s) 
{
	StrListNode * n = new StrListNode(s) ;

	n->prev = &head ;
	n->next = head.next ;
	head.next->prev = n ;
	head.next = n ;

	return 1 ;
}

int StrList::addLast (const char * s)
{
	StrListNode * n = new StrListNode(s) ;

	n->next = &tail ;
	n->prev = tail.prev ;

	tail.prev->next = n ;
	tail.prev = n ;

	return 1 ;
}

int StrList::removeFirst (char * &s) 
{
	if (head.next == &tail)
		return 0 ;

	StrListNode * n ;

	n = head.next ;

	head.next = n->next ;
	n->next->prev = &head ;

	s = strdup(n->elem) ;
	delete n ;

	return 1 ;
}

int StrList::removeLast (char * &s) 
{
	if (head.next == &tail)
		return 0 ;

	StrListNode * n ;

	n = tail.prev ; 

	tail.prev = n->prev ;
	n->prev->next = &tail ;

	s = strdup(n->elem) ;

	delete n ;

	return 1 ;
}

void StrList::print () 
{
	StrListNode * i ;
	for (i = head.next ; i != &tail ; i = i->next) {
		std::cout << *i << " " ;
		//i->print() ;
		//std::cout << " " ;
	}
	std::cout << std::endl ;
}
