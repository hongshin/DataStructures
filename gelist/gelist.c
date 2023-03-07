#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gelist.h"

gelist * gelist_alloc (int n)
{
	if (n < 0)
		return 0x0 ;

	gelist * l ;

	l = (gelist *) malloc(sizeof(gelist)) ;

	l->max_entries = n ;
	l->num_entries = 0;
	l->entries = (gentry *) calloc(sizeof(gentry), n) ;

	return l ;
}

void gelist_free (gelist * l)
{
	if (l->entries) 
		free(l->entries) ;
	free(l) ;
}

int gelist_get (gelist * l, int i, gentry * e)
{
	if (i < 0 || l->num_entries <= i) 
		return 0 ;

	*e = l->entries[i] ;
	return 1 ;
}

int gelist_add (gelist * l, gentry e)
{
	if (l->num_entries == l->max_entries) {
		if (l->max_entries)
			l->max_entries = l->max_entries * 2 ;
		else
			l->max_entries = 8 ;
		gentry * new_entries = (gentry *) calloc(sizeof(gentry), l->max_entries) ;
		memcpy(new_entries, l->entries, sizeof(gentry) * l->num_entries) ;
		if (l->entries)
			free(l->entries) ;
		l->entries = new_entries ;
	}
	// assume l->num_entries < l->max_entries

	int v = 0 ;
	while (!(l->entries[v].score < e.score || v == l->num_entries)) {
		v++ ;
	}

	for (int i = l->num_entries ; i > v ; i--) {
		l->entries[i] = l->entries[i - 1] ;
	}
	l->entries[v] = e ;
	l->num_entries++ ;
	return 1 ;
}

int gelist_remove (gelist * l, int i, gentry * e) 
{
	return 1 ;
}

void gelist_print (gelist * l) 
{
	for (int i = 0 ; i < l->num_entries ; i++) {
		printf("(%s, %d) ", l->entries[i].name, l->entries[i].score) ;
	}
	printf("\n") ;
}
