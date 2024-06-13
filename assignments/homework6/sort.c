#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>

enum algo_opt {
	Insert, 
	Heap,
	Quick,
	Merge 
} ;

char * algo_opts[5] = {
	"insert",
	"heap",
	"quick",
	"merge",
	NULL } ;

int n_elements = 0 ;
double * elements ;

int algo = 0 ;

FILE * fin = NULL ;
FILE * fout = NULL ; 

void load_elements ()
{
	int i ;
	for (i = 0 ; i < n_elements ; i++) {
		int r ;
		r = fscanf(fin, "%lf", &(elements[i])) ;
		if (r != 1) {
			fprintf(stderr, "Error. Failed at reading input file: %d\n", r) ;
			exit(EXIT_FAILURE) ;
		}
	}
}

void store_result ()
{
	int i ;
	for (i = 0 ; i < n_elements ; i++) {
		int r ;
		r = fprintf(fout, "%lf\n", elements[i]) ;
		if (r <= 0) {
			fprintf(stderr, "Error. Failed at writing the result.\n") ;
			exit(EXIT_FAILURE) ;
		}
	}
}

void insertion_sort ()
{	
	/*TODO*/
}

void heap_sort ()
{
	/*TODO*/
}

void quick_sort ()
{
	/*TODO*/
}

void merge_sort ()
{
	/*TODO*/
}

void sort ()
{
	switch (algo) {
		case Insert :
			insertion_sort() ;
			break ;

		case Heap:
			heap_sort() ;
			break ;

		case Quick: 
			quick_sort() ;
			break ;

		case Merge:
			merge_sort() ;
			break ;

		default:
			fprintf(stderr, "Error. Unkown algorithm option.\n") ;
			exit(EXIT_FAILURE) ;
			break ;
	}
}


int main (int argc, char ** argv)
{
	struct timeval ts_begin ;
	struct timeval ts_end ;

	int opt ;
	while ((opt = getopt(argc, argv, "n:i:o:s:")) != -1) {
		switch (opt) {

			case 'n': {
				n_elements = atoi(optarg) ;

				if (n_elements <= 0 || 40000000 < n_elements) {
					fprintf(stderr, "Error. \'n\' must be a positive integer no greater than 10^9.\n") ;
					exit(EXIT_FAILURE) ;
				}

				elements = calloc(n_elements, sizeof(double)) ;
				break ;
			}

			case 'i' : {
				fin = fopen(optarg, "r") ;

				if (fin == NULL) {
					fprintf(stderr, "Error. Fail to open %s\n", optarg) ;
					exit(EXIT_FAILURE) ;
				}
				break ;
			}

			case 'o' : {
				fout = fopen(optarg, "w") ;
				if (fout == NULL) {
					fprintf(stderr, "Error. Fail to open %s\n", optarg) ;
					exit(EXIT_FAILURE) ;
				}
				break ;
			}

			case 's' : {
				while (algo_opts[algo] && strcmp(algo_opts[algo], optarg) != 0) {
					algo++ ;
				}
				if (algo_opts[algo] == NULL) {
					fprintf(stderr, "Usage: -n <num elements> -i <input file> -o <output file> -s [insert|heap|quick|merge]") ;
					exit(EXIT_FAILURE) ;
				}
				break ;
			}

			default: {
				fprintf(stderr, "Usage: -n <num elements> -i <input file> -o <output file> -s [insert|heap|quick|merge]") ;
				exit(EXIT_FAILURE) ;
				break ;
			}
		}
	}

	load_elements() ;

	gettimeofday(&ts_begin, NULL) ;

	sort() ;

	gettimeofday(&ts_end, NULL) ;

	store_result() ;


	if (ts_begin.tv_usec < ts_end.tv_usec) {
		printf("%ld.%06ld\n", 	
			(long int) (ts_end.tv_sec - ts_begin.tv_sec), 
			(long int) (ts_end.tv_usec - ts_begin.tv_usec)) ;
	}
	else {
		printf("%ld.%06ld\n",
			(long int) (ts_end.tv_sec - ts_begin.tv_sec - 1),
			(long int) (ts_begin.tv_usec - ts_end.tv_usec)) ;
	}

	if (fin)
		fclose(fin) ;
	if (fout)
		fclose(fout) ;

	return EXIT_SUCCESS ;
}
