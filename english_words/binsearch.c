#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char * words [400000] ;
int n_words = 0 ;

int main (int argc, char ** argv)
{
	FILE * fp = fopen("words_alpha.txt", "r") ;

	n_words = 0 ;
	while (!feof(fp)) {
		char buf[256] ;

		fgets(buf, 256, fp) ;

		int len = strlen(buf) ;
		while (!isalpha(buf[len - 1])) {
			buf[len - 1] = '\0' ;
			len-- ;
		}

		words[n_words] = strdup(buf) ;
		n_words++ ;
	}


	char * keyword = argv[1] ;


	int begin = 0, end = n_words - 1 ;

	while (begin <= end) {
		int mid = (begin + end) / 2 ;

		printf("(debug) begin: %s (%d), mid: %s (%d), end: %s (%d)\n", 
			words[begin], begin, words[mid], mid, words[end], end) ;

		if (strcmp(words[mid], keyword) == 0) {
			printf("%d\n", mid) ;
			return 0 ;
		}
		else if (strcmp(words[mid], keyword) < 0) {
			begin = mid + 1 ;
		}
		else /* keyword < words[mid] */ {
			end = mid - 1 ;
		}
	}
	printf("%s is not defined.\n", keyword) ;

	fclose(fp) ;

	return 0 ;
}
