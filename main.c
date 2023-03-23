#include <stdio.h>
#include <string.h>
#include "gentry.h"
#include "gdlist.h"


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

int test_gdlist_add ()
{
	gdlist * l ;

	l = gdlist_alloc(sizeof(gentry), gentry_compare) ;

	gentry e1 = {"Rob", 750}, e2 = {"Jack", 510}, e3 = {"Mike", 1105}, e4 = {"Paul", 720}, e5 = {"Justin", 750}, e6 = {"Rob", 200} ;

	gdlist_add(l, &e1) ;
	gdlist_add(l, &e2) ;
	gdlist_add(l, &e3) ;
	gdlist_add(l, &e4) ;
	gdlist_add(l, &e5) ;
	gdlist_add(l, &e6) ;

	gdlist_print(l, gentry_print) ;

	gdlist_free(l) ;
	return 0 ;
}

int test_gdlist_search_remove ()
{
	gdlist * l ;

	l = gdlist_alloc(sizeof(gentry), gentry_compare) ;

	gentry e1 = {"Rob", 750}, e2 = {"Jack", 510}, e3 = {"Mike", 1105}, e4 = {"Paul", 720}, e5 = {"Justin", 750}, e6 = {"Rob", 200} ;

	gdlist_add(l, &e1) ;
	gdlist_add(l, &e2) ;
	gdlist_add(l, &e3) ;
	gdlist_add(l, &e4) ;
	gdlist_add(l, &e5) ;
	gdlist_add(l, &e6) ;

	int index ;
	index = gdlist_search(l, gentry_cond) ;

	gentry e ;
	gdlist_remove(l, index, &e) ;
	gdlist_print(l, gentry_print) ;

	index = gdlist_search(l, gentry_cond) ;
	gdlist_remove(l, index, &e) ;
	gdlist_print(l, gentry_print) ;

	gdlist_free(l) ;
	return 0 ;
}


int test_gdlist_merge ()
{
	gdlist * l1, *l2, *l_merged ;

	l1 = gdlist_alloc(sizeof(gentry), gentry_compare) ;
	l2 = gdlist_alloc(sizeof(gentry), gentry_compare) ;


	gentry e1 = {"Rob", 750}, e2 = {"Jack", 510}, e3 = {"Mike", 1105}, e4 = {"Paul", 720}, e5 = {"Justin", 750}, e6 = {"Rob", 200} ;

	gdlist_add(l1, &e1) ;
	gdlist_add(l1, &e2) ;
	gdlist_add(l1, &e3) ;

	gdlist_add(l2, &e4) ;
	gdlist_add(l2, &e5) ;
	gdlist_add(l2, &e6) ;

	l_merged = gdlist_merge(l1, l2) ;

	gdlist_print(l_merged, gentry_print) ;

	gdlist_free(l1) ;
	gdlist_free(l2) ;
	gdlist_free(l_merged) ;

	return 0 ;
}


int main ()
{
	test_gdlist_add() ;
	test_gdlist_search_remove() ;
	test_gdlist_merge() ;
	return 0 ;
}
