#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "stack.h"

int is_wellformed (char * buf) 
{
    stack * opens = stack_alloc(sizeof(char)) ;

    for (char * c = buf ; *c != 0x0 ; c++) {
        switch (*c) {
            case '(':
            case '<':
            case '[':
            case '{':
                {
                    stack_push(opens, c) ;
                    break ;
                }

            case ')':
            case '>':
            case ']':
            case '}':
                {
                    char openc ;
                    if (!stack_pop(opens, &openc))
                        return 0 ;
                    if ((openc == '(' && *c != ')') ||
                        (openc == '<' && *c != '>') ||
                        (openc == '[' && *c != ']') ||
                        (openc == '{' && *c != '}'))
                        return 0 ;
                        
                    break ;
                }

            default: 
                {
                    break ;
                }
        }
    }
    int remains = stack_size(opens) ;
    stack_free(opens) ;
    return (remains == 0) ;
}

int main ()
{

    char buf[128] ;
    scanf("%127s", buf) ;

    if (is_wellformed(buf)) {
        printf("well-formed.\n") ;
    }
    else {
        printf("ill-formed.\n") ;
    }

    return 0 ;
}

