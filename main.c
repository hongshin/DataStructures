#include <stdio.h>
#include <string.h>
#include "gentry.h"
#include "slist.h"


void gentry_print (void * p)
{
	gentry * e = (gentry *) p ;
	printf("(%s, %d) ", e->name, e->score) ;
}

int gentry_compare (void *p1, void *p2)
{
	gentry * e1 = (gentry *) p1 ;
	gentry * e2 = (gentry *) p2 ;

	if (e1->score < e2->score)
		return -1 ;
	else if (e1->score > e2->score)
		return 1 ;

	if (strlen(e1->name) < strlen(e2->name))
		return -1 ;
	else if (strlen(e1->name) > strlen(e2->name))
		return 1 ;

	return 0 ;
}

int gentry_cond (void * p)
{
	gentry * e = (gentry *) p ;

	if (700 < e->score && e->score < 800) 
		return 1 ;
	return 0 ;
}

int test_slist_add ()
{
	slist * l ;

	l = slist_alloc(sizeof(gentry), gentry_compare) ;

	gentry e1 = {"Rob", 750}, e2 = {"Jack", 510}, e3 = {"Mike", 1105}, e4 = {"Paul", 720}, e5 = {"Justin", 750}, e6 = {"Rob", 200} ;

	slist_add(l, &e1) ;
	slist_add(l, &e2) ;
	slist_add(l, &e3) ;
	slist_add(l, &e4) ;
	slist_add(l, &e5) ;
	slist_add(l, &e6) ;

	slist_print(l, gentry_print) ;

	slist_free(l) ;
	return 0 ;
}

int test_slist_search_remove ()
{
	slist * l ;

	l = slist_alloc(sizeof(gentry), gentry_compare) ;

	gentry e1 = {"Rob", 750}, e2 = {"Jack", 510}, e3 = {"Mike", 1105}, e4 = {"Paul", 720}, e5 = {"Justin", 750}, e6 = {"Rob", 200} ;

	slist_add(l, &e1) ;
	slist_add(l, &e2) ;
	slist_add(l, &e3) ;
	slist_add(l, &e4) ;
	slist_add(l, &e5) ;
	slist_add(l, &e6) ;

	int index ;
	index = slist_search(l, gentry_cond) ;

	gentry e ;
	slist_remove(l, index, &e) ;
	slist_print(l, gentry_print) ;

	index = slist_search(l, gentry_cond) ;
	slist_remove(l, index, &e) ;
	slist_print(l, gentry_print) ;

	slist_free(l) ;
	return 0 ;
}


int test_slist_merge ()
{
	slist * l1, *l2, *l_merged ;

	l1 = slist_alloc(sizeof(gentry), gentry_compare) ;
	l2 = slist_alloc(sizeof(gentry), gentry_compare) ;


	gentry e1 = {"Rob", 750}, e2 = {"Jack", 510}, e3 = {"Mike", 1105}, e4 = {"Paul", 720}, e5 = {"Justin", 750}, e6 = {"Rob", 200} ;

	slist_add(l1, &e1) ;
	slist_add(l1, &e2) ;
	slist_add(l1, &e3) ;

	slist_add(l2, &e4) ;
	slist_add(l2, &e5) ;
	slist_add(l2, &e6) ;

	l_merged = slist_merge(l1, l2) ;

	slist_print(l_merged, gentry_print) ;

	slist_free(l1) ;
	slist_free(l2) ;
	slist_free(l_merged) ;

	return 0 ;
}


int main ()
{
	test_slist_add() ;
	test_slist_search_remove() ;
	test_slist_merge() ;
	return 0 ;
}
