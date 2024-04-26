#include <stdio.h>
#include <stdlib.h>
#include "intlist.h"

int n_elements = 0 ;
int n_pairs = 0 ; 

intlist_t ** equiv ;

void find_equiv_class ()
{
	int * checked ;
	int n_checked = 0 ;
	int i, j ;

	checked = (int *) calloc(n_elements, sizeof(int)) ;
	for (i = 0 ; i < n_elements ; i++) {
		checked[i] = 0 ;
	}

	n_checked = 0 ;
	while (n_checked < n_elements) {
		
		intlist_t * a_class = intlist_create() ;

		for (i = 0 ; i < n_elements ; i++) {
			if (checked[i] == 0) {
				intlist_add(a_class, i) ;
				checked[i] = 1 ;
				n_checked++ ;
				break ;
			}
		}

		i = 0 ;
		while (i < intlist_len(a_class)) {
			int e1 ;
			intlist_get(a_class, i, &e1) ;
			for (j = 0 ; j < intlist_len(equiv[e1]) ; j++) {
				int e2 ;
				intlist_get(equiv[e1], j, &e2) ;
				if (checked[e2] == 0) {
					intlist_add(a_class, e2) ;
					checked[e2] = 1 ;
					n_checked++ ;
				}
			}
			i++ ;
		}

		for (i = 0 ; i < intlist_len(a_class) ; i++) {
			int e ;
			intlist_get(a_class, i, &e) ;
			printf("%d ", e) ;
		}
		printf("\n") ;

		intlist_free(a_class) ;
	}

}



int main ()
{
	FILE * fp = fopen("data", "r") ;
	int i, j ;


	fscanf(fp, "%d %d", &n_elements, &n_pairs) ;

	equiv = (intlist_t **) calloc(n_elements, sizeof(intlist_t *)) ;

	for (i = 0 ; i < n_elements ; i++) {
		equiv[i] = intlist_create() ;
	}
	
	for (i = 0 ; i < n_pairs ; i++) {
		int a, b ;
		fscanf(fp, "%d %d", &a, &b) ;
		
		intlist_add(equiv[a], b) ;
		intlist_add(equiv[b], a) ;
	}

	find_equiv_class() ;

	free(equiv) ;
	fclose(fp) ;

	return EXIT_SUCCESS ;
}
