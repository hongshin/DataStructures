#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lalist.h"

lalist_t * 
lalist_alloc (int arr_cap, int elem_size) 
{
	lalist_t * l = malloc(sizeof(lalist_t)) ;
	l->arr_cap = arr_cap ;
	l->elem_size = elem_size ;
	l->first = malloc(sizeof(lalist_node_t)) ;
	l->first->arr = calloc(elem_size, arr_cap) ;
	l->first->n_elem = 0 ;
	l->first->next = NULL ;

	return l ;
}

void
lalist_free (lalist_t * l)
{
	/* TODO */
	lalist_node_t * curr =  l->first;
	lalist_node_t* prev = NULL;
	while(curr != NULL){
		free(curr->arr);
		prev = curr;
		curr = curr->next;
		free(prev);
	}
	free(l);
	return ;
}

int 
lalist_length (lalist_t * l)
{
	int n = 0 ;
	lalist_node_t * i ;
	for (i = l->first ; i != NULL ; i = i->next) {
		n += i->n_elem ;
	}
	return n ;
}

void
lalist_insert_first (lalist_t * l, void * e)
{
	/* TODO */
	//n-elem이 3이하이면 거기다 넣고 아니면 새로 할당
	lalist_node_t* new = (lalist_node_t* )malloc(sizeof(lalist_node_t));
	new->arr = calloc(l->arr_cap,l->elem_size);

	if(l->first->n_elem == 0){
		memcpy(l->first->arr, e, l->elem_size);
		l->first->n_elem ++;
		return;
	}
	else if(l->first->n_elem > 0 && l->first->n_elem < l->arr_cap){
		memcpy(new->arr, e, l->elem_size);
		new->n_elem++;
		int i;
		for(i = 0; i < l->first->n_elem; i++){
			memcpy(new->arr+(i+1)*(l->elem_size), l->first->arr+(i*l->elem_size),l->elem_size);
			new->n_elem++;
		}
		new->next = l->first->next;
		l->first = new;
		return;
	}
	else{
		memcpy(new->arr, e, l->elem_size);
		new->next = l->first;
		l->first = new;
		l->first->n_elem ++;
		return;
	}
}

void
lalist_insert_last (lalist_t * l, void * e)
{
	/* TODO */
	lalist_node_t* new = (lalist_node_t* )malloc(sizeof(lalist_node_t));
	new->arr = calloc(l->arr_cap,l->elem_size);

	lalist_node_t* curr = l->first;
	while(curr->next != NULL){
		curr = curr->next;
	}
	if(curr->n_elem != l->arr_cap){
		int i = 0;
		while(*(int*)(curr->arr+(i*l->elem_size)) != 0){
			i++;
		}
		memcpy(curr->arr+(i*l->elem_size), e, l->elem_size);
		curr->n_elem++;
		return;
	}
	else{
		memcpy(new->arr, e, l->elem_size);
		new->n_elem++;

		new->next = NULL;
		curr->next = new;
		return;
	}
}

int
lalist_insert_at (lalist_t * l, int index, void * e)
{
	/* TODO */
	if(index < 0){
		printf("Invalid range\n");
		return 0;
	}
	if(index > lalist_length(l)){
		printf("Invalid range\n");
		return 0;
	}
	lalist_node_t* curr;
	lalist_node_t* prev = NULL;
	int num = 0;
	int node = 0;
	int found = 0;
	int index_in_node;
	for(curr = l->first; curr != NULL; curr = curr->next){
		index_in_node = 0;
		for(int i = 0; i < curr->n_elem; i++){
			if(num == index){
				found = 1;
				break;
			}
			index_in_node++;
			num++;
		}
		if(found)
			break;
		prev=curr;
		node++;
	}

	lalist_node_t* new = (lalist_node_t*)malloc(sizeof(lalist_node_t));
	new->arr = calloc(l->arr_cap,l->elem_size);
	lalist_node_t* new2 = (lalist_node_t*)malloc(sizeof(lalist_node_t));
	new2->arr = calloc(l->arr_cap,l->elem_size);
	int i = 0;
	for(i; i < index_in_node; i++){
		memcpy(new->arr+i*(l->elem_size), curr->arr+i*(l->elem_size), l->elem_size);
		new->n_elem++;
	}
	memcpy(new->arr+i*(l->elem_size), e, l->elem_size);
	new->n_elem++;
	int j = 0;
	for(i = index_in_node; i < curr->n_elem; i++){
		memcpy(new2->arr+j*(l->elem_size), curr->arr+i*(l->elem_size), l->elem_size);
		new2->n_elem++;
		j++;
	}

	new2->next = curr->next;
	new->next = new2;
	if(prev == NULL){
		l->first = new;
	}
	else{
		prev->next = new;
	}
	free(curr->arr);
	free(curr);
	lalist_pack(l);
	return 1;
}

int 
lalist_remove_first (lalist_t * l, void * e)
{
	/* TODO */
	if(l->first == NULL){
		return 0;
	}
	lalist_node_t* new = (lalist_node_t*)malloc(sizeof(lalist_node_t));
	new->arr = calloc(l->arr_cap,l->elem_size);
	for(int i = 0; i < l->first->n_elem; i++){
		memcpy(new->arr+i*(l->elem_size), l->first->arr+(i+1)*(l->elem_size),l->elem_size);
		if(*(int*)(new->arr+(i*(l->elem_size))) != 0){
			new->n_elem++;
		}
	}
	memcpy(e,l->first->arr,l->elem_size);

	new->next = l->first->next;
	l->first = new;
	return 1;
}

int
lalist_remove_last (lalist_t * l, void * e)
{
	/* TODO */
	if(l->first == NULL)
		return 0;
	lalist_node_t* prev;
	lalist_node_t* curr = l->first;
	for(curr; curr->next != NULL; curr=curr->next){
		prev = curr;
	}
	lalist_node_t* new = (lalist_node_t*)malloc(sizeof(lalist_node_t));
	new->arr = calloc(l->arr_cap,l->elem_size);
	for(int i = 0; i < curr->n_elem-1; i++){
		memcpy(new->arr+i*(l->elem_size),curr->arr+i*(l->elem_size),l->elem_size);
		if(*(int*)(new->arr+(i*(l->elem_size))) != 0){
			new->n_elem++;
		}
	}
	memcpy(e, curr->arr+(new->n_elem)*(l->elem_size), l->elem_size);

	if(*(int*)(new->arr) == 0){
		prev->next = NULL;
		free(new);
		return 1;
	}
	
	new->next = NULL;
	prev->next = new;
	return 1;
}

int
lalist_remove_at (lalist_t * l, int index, void * e)
{
	/* TODO */
	if(index < 0){
		printf("Invalid range\n");
		return 0;
	}
	if(index > lalist_length(l)){
		printf("Invalid range\n");
		return 0;
	}
	lalist_node_t* curr;
	lalist_node_t* prev = NULL;
	int num = 0;
	int node = 0;
	int found = 0;
	int index_in_node;
	for(curr = l->first; curr != NULL; curr = curr->next){
		index_in_node = 0;
		for(int i = 0; i < curr->n_elem; i++){
			if(num == index){
				found = 1;
				break;
			}
			index_in_node++;
			num++;
		}
		if(found)
			break;
		prev=curr;
		node++;
	}
	lalist_node_t* new = (lalist_node_t*)malloc(sizeof(lalist_node_t));
	new->arr = calloc(l->arr_cap,l->elem_size);
	
	int i = 0;
	for(i; i < index_in_node; i++){
		memcpy(new->arr+i*(l->elem_size), curr->arr+i*(l->elem_size), l->elem_size);
		new->n_elem++;
	}
	memcpy(e, curr->arr+i*(l->elem_size), l->elem_size);
	for(i = index_in_node+1; i < curr->n_elem; i++){
		memcpy(new->arr+(i-1)*(l->elem_size), curr->arr+i*(l->elem_size), l->elem_size);
		new->n_elem++;
	}
	new->next = curr->next;
	if(prev == NULL){
		l->first = new;
	}
	else{
		prev->next = new;
	}
	free(curr->arr);
	free(curr);

	return 1;
}


void
lalist_apply (lalist_t * l, void (* func)(void * e)) 
{
	/* TODO */
	lalist_node_t* curr;

	for(curr = l->first; curr != NULL; curr = curr->next){
		int i;
		for(int i = 0; i < l->arr_cap; i++){
			func(curr->arr+(l->elem_size*i));
		}
	}
	free(curr);
	return;
}

void 
lalist_info (lalist_t * l)
{
	lalist_node_t * i ;
	int j = 0 ;
	printf("========\n") ;
	for (i = l->first, j = 0 ; i != NULL ; i = i->next, j++) {
		printf(" - node %d : %d elements\n", j, i->n_elem) ;
	}
	printf("========\n") ;
}

void
lalist_pack (lalist_t * l)
{
	if(l->first == NULL){
		printf("Nothing to pack\n");
		return;
	}
	/* TODO */
	lalist_node_t* curr;
	lalist_t* new = lalist_alloc(l->arr_cap,l->elem_size);

	for(curr = l->first; curr != NULL; curr = curr->next){
		for(int i = 0; i < curr->n_elem; i++){
			void* data = malloc(sizeof(l->elem_size));

			memcpy(data, curr->arr+i*(l->elem_size), l->elem_size);
			lalist_insert_last(new,data);
		}
	}
	l->first = new->first;
	return;
}
