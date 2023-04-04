#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "list.h"
#include "stack.h"

int eval (char ** tokens, int n_tokens)
{
	stack * operands = stack_alloc(sizeof(int)) ;

	int i ;
	for (i = 0 ; i < n_tokens ; i++) {
		char * token = tokens[i] ;

		if (isdigit(token[0])) {
			int num ;
			num = atoi(token) ;
			stack_push(operands, &num) ;
		}
		else if (strcmp(token, "+") == 0) {
			int v1, v2, val ;

			if (stack_pop(operands, &v2) == 0 || stack_pop(operands, &v1) == 0) {
				fprintf(stderr, "Invalid expression\n") ;
				exit(1) ;
			}

			val = v1 + v2 ;
			stack_push(operands, &val) ;
		}
		else if (strcmp(token, "-") == 0) {
			int v1, v2, val ;

			if (stack_pop(operands, &v2) == 0 || stack_pop(operands, &v1) == 0) {
				fprintf(stderr, "Invalid expression\n") ;
				exit(1) ;
			}

			val = v1 - v2 ;
			stack_push(operands, &val) ;
		}
		else if (strcmp(token, "*") == 0) {
			int v1, v2, val ;

			if (stack_pop(operands, &v2) == 0 || stack_pop(operands, &v1) == 0) {
				fprintf(stderr, "Invalid expression\n") ;
				exit(1) ;
			}

			val = v1 * v2 ;
			stack_push(operands, &val) ;
		}
		else if (strcmp(token, "/") == 0) {
			int v1, v2, val ;

			if (stack_pop(operands, &v2) == 0 || stack_pop(operands, &v1) == 0) {
				fprintf(stderr, "Invalid expression\n") ;
				exit(1) ;
			}
			if (v2 == 0) {
				fprintf(stderr, "Divide by zero\n") ;
				exit(1) ;
			}

			val = v1 / v2 ;
			stack_push(operands, &val) ;
		}
		else {
			fprintf(stderr, "Unknown token: %s\n", token) ;
			exit(1) ;
		}
	}

	int val ;
	if (stack_pop(operands, &val) == 0 || !stack_empty(operands)) {
		fprintf(stderr, "Invalid expression\n") ;
		exit(1) ;
	}

	stack_free(operands) ;

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
