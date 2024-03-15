#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct membership_t {
	enum member_type {student, prof} type ;
	union {
		long long student_number ;
		char office[20] ;
	} ;
} ;


struct person {
	char name[10] ; 
	int age ;
	struct membership_t membership ;
} ;

int main ()
{
	struct person shin ;

	strcpy(shin.name, "Shin Hong") ;
	shin.age = 38 ;
	shin.membership.type = prof ;
	strcpy(shin.membership.office, "316 S4-1") ;
	

	printf("%ld\n", sizeof(struct person)) ;

	return EXIT_SUCCESS ;
}
