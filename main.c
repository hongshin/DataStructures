#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gelist.h"


int gentry_equal (gentry e1, gentry e2)
{
	if (strcmp(e1.name, e2.name) != 0)
		return 0 ;
	if (e1.score != e2.score) 
		return 0 ;

	return 1 ;
}

void test_gelist_remove ()
{
	printf("\n== test_gelist_remove ==\n") ;

	gentry e1 = {"Rob", 750}, e2 = {"Jack", 510}, e3 = {"Mike", 1105}, e4 = {"Paul", 720} ;

	gelist * l = gelist_alloc(5) ;
	
	gelist_add(l, e1) ;
	gelist_add(l, e2) ;
	gelist_add(l, e3) ;
	gelist_add(l, e4) ;	


	gentry e ;
	int r ;
	printf("remove the element at index 2 from\n") ;
	printf("  ") ; gelist_print(l) ;    
	
	r = gelist_remove(l, 2, &e) ;
	printf("result:\n") ;
	printf("  ") ; gelist_print(l) ;
	if (!(r == 1 && gentry_equal(e, e4))) {
		printf("test_gelist_remove failed.\n") ;
		exit(1) ;
	}

	r = gelist_remove(l, -1, &e) ;
	if (!(r == 0)) {
		printf("test_gelist_remove failed.\n") ;
		exit(1) ;
	}

	r = gelist_remove(l, 4, &e) ;
	if (!(r == 0)) {
		printf("test_gelist_remove failed.\n") ;
		exit(1) ;
	}

	gelist_free(l) ;

	printf("test_gelist_remove successfully passed.\n") ;
}

void test_gelist_search_by_name ()
{
	printf("\n== test_gelist_search_by_name ==\n") ;

	gentry e1 = {"Rob", 750}, e2 = {"Jack", 510}, e3 = {"Mike", 1105}, e4 = {"Paul", 720}, e5 = {"Jack", 1000} ;

	gelist * l = gelist_alloc(5) ;
	
	gelist_add(l, e1) ;
	gelist_add(l, e2) ;
	gelist_add(l, e3) ;
	gelist_add(l, e4) ;	
	gelist_add(l, e5) ;

	gentry e ;
	int r ;

	r = gelist_search_by_name(l, "Jack") ;
	if (!(r == 1)) {
		printf("test_gelist_search_by_name failed.\n") ;
		exit(1) ;
	}

	r = gelist_search_by_name(l, "Tom") ;
	if (!(r == -1)) {
		printf("test_gelist_search_by_name failed.\n") ;
		exit(1) ;
	}

	gelist_free(l) ;
	printf("test_gelist_search_by_name successfully passed.\n") ;
}

void test_gelist_remove_by_name ()
{
	printf("\n== test_gelist_remove_by_name ==\n") ;

	gentry e1 = {"Rob", 750}, e2 = {"Jack", 510}, e3 = {"Mike", 1105}, e4 = {"Paul", 720}, e5 = {"Jack", 1000} ;

	gelist * l = gelist_alloc(5) ;
	
	gelist_add(l, e1) ;
	gelist_add(l, e2) ;
	gelist_add(l, e3) ;
	gelist_add(l, e4) ;	
	gelist_add(l, e5) ;

	gentry e ;
	int r ;

	printf("remove Jack from\n") ;
	printf("  ") ; gelist_print(l) ;

	r = gelist_remove_by_name(l, "Jack", &e) ;
	printf("result:\n") ;
	printf("  ") ; gelist_print(l) ;

	if (!(r == 1 && gentry_equal(e, e5))) {
		printf("test_gelist_remove_by_name failed.\n") ;
		exit(1) ;
	}

	r = gelist_remove_by_name(l, "Tom", &e) ;
	if (!(r == 0)) {
		printf("test_gelist_remove_by_name failed.\n") ;
		exit(1) ;
	}

	gelist_free(l) ;
	printf("test_gelist_remove_by_name successfully passed.\n") ;
}

void test_gelist_merge() 
{
	printf("\n== test_gelist_merge ==\n") ;

	gentry e1 = {"Rob", 750}, e2 = {"Jack", 510}, e3 = {"Mike", 1105}, e4 = {"Paul", 720}, e5 = {"Jack", 1000} ;

	gelist * l1 = gelist_alloc(5) ;
	gelist_add(l1, e1) ;
	gelist_add(l1, e2) ;

	gelist * l2 = gelist_alloc(5) ;
	gelist_add(l2, e3) ;
	gelist_add(l2, e4) ;	
	gelist_add(l2, e5) ;

	gelist * lm = gelist_merge(l1, l2) ;

	printf("merge \n") ;
	printf("  ") ; gelist_print(l1) ;
	printf("  ") ; gelist_print(l2) ;
	printf("result: \n") ;
	printf("  ") ; gelist_print(lm) ;

	gelist_free(l1) ;
	gelist_free(l2) ;
	gelist_free(lm) ;
}


int main ()
{
	test_gelist_remove() ;
	test_gelist_search_by_name() ;
	test_gelist_remove_by_name() ;
	test_gelist_merge() ;

	return 0 ;
}
