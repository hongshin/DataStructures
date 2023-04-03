#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "list.h"
#include "stack.h"

int eval (char ** tokens, int n_tokens)
{
	stack * st = stack_alloc(sizeof(int)) ;


	int i ;
	for (i = 0 ; i < n_tokens ; i++) {
		char * token = tokens[i] ;

		if (isdigit(token[0])) {
			int num ;
			num = atoi(token) ;
			stack_push(st, &num) ;
		}
		else if (strcmp(token, "+") == 0) {
			int v1, v2, val ;

			if (stack_pop(st, &v2) == 0 || stack_pop(st, &v1) == 0) {
				fprintf(stderr, "Invalid expression\n") ;
				exit(1) ;
			}

			val = v1 + v2 ;
			stack_push(st, &val) ;
		}
		else if (strcmp(token, "-") == 0) {
			int v1, v2, val ;

			if (stack_pop(st, &v2) == 0 || stack_pop(st, &v1) == 0) {
				fprintf(stderr, "Invalid expression\n") ;
				exit(1) ;
			}

			val = v1 - v2 ;
			stack_push(st, &val) ;
		}
		else if (strcmp(token, "*") == 0) {
			int v1, v2, val ;

			if (stack_pop(st, &v2) == 0 || stack_pop(st, &v1) == 0) {
				fprintf(stderr, "Invalid expression\n") ;
				exit(1) ;
			}

			val = v1 * v2 ;
			stack_push(st, &val) ;
		}
		else if (strcmp(token, "/") == 0) {
			int v1, v2, val ;

			if (stack_pop(st, &v2) == 0 || stack_pop(st, &v1) == 0) {
				fprintf(stderr, "Invalid expression\n") ;
				exit(1) ;
			}
			if (v2 == 0) {
				fprintf(stderr, "Divide by zero\n") ;
				exit(1) ;
			}

			val = v1 / v2 ;
			stack_push(st, &val) ;
		}
		else {
			fprintf(stderr, "Unknown token: %s\n", token) ;
			exit(1) ;
		}
	}

	int val ;
	if (stack_pop(st, &val) == 0 || !stack_empty(st)) {
		fprintf(stderr, "Invalid expression\n") ;
		exit(1) ;
	}

	stack_free(st) ;

	return val ;
}



int main ()
{
	char * tokens[128] ;
	int n_tokens = 0 ;

	while (!feof(stdin) && n_tokens < 128) {
		char token[128] ;

		if (scanf("%127s", token) == EOF) {
			break ;
		}
		tokens[n_tokens] = strdup(token) ;
		n_tokens++ ;
	}

	printf("\n") ;
	printf("= %d\n", eval(tokens, n_tokens)) ;

	return 0 ;
}
