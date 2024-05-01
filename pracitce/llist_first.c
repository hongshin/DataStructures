#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef
    struct _llist_node_t {
        char* data;
        struct _llist_node_t* next;
    }llist_node_t;

typedef
    struct {
        llist_node_t* first;
    }llist_t;

llist_t* create_llist(){
    llist_t* l = (llist_t *)malloc(sizeof(llist_t));
    l->first = NULL;

    return l;
}

int insert_llist(llist_t* l, char* s){
    llist_node_t* new = (llist_node_t *)malloc(sizeof(llist_node_t));
    new->data = s;

    if(l->first == NULL){
        l->first = new;
        new->next = new;
        return 1;
    }

    llist_node_t* curr = l->first;
    while(curr->next != l->first){
        curr = curr->next;
    }
    new->next = l->first;
    curr->next = new;
    
    return 1;
}

void print_llist(llist_t* l){
    llist_node_t* curr = l->first;

    while(curr->next != l->first){
        printf("%s ", curr->data);
        curr = curr->next;
    }   
    
    printf("\n");

}

int delete_llist (llist_t* l, char* s)
{
    llist_node_t* curr = l->first;
    llist_node_t* prev;

    while(curr->next != l->first){
        if(strcmp(curr->data, s)== 0){
            break;
        }
        prev = curr;
        curr = curr->next;
    }

    if(curr->next == l->first){
        if(strcmp(curr->data, s)==0){
            l->first = NULL;
            free(curr);
            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        prev->next = curr->next;
        free(curr);
        return 1;
    }
}
int main ()
{
	llist_t * l = create_llist() ;

	insert_llist(l, "BAT") ;
	insert_llist(l, "CAT") ;
	insert_llist(l, "EAT") ;
	insert_llist(l, "FAT") ;
	insert_llist(l, "GAT") ;
	insert_llist(l, "HAT") ;
	insert_llist(l, "VAT") ;
	insert_llist(l, "WAT") ;


	delete_llist(l, "FAT") ;
	delete_llist(l, "VAT") ;

	print_llist(l) ;

	// free_llist(l) ;

	return EXIT_SUCCESS ;
}
