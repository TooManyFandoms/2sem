#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

iterator* iterator_create(list* lst)
{
	iterator* it = (iterator*)malloc(sizeof(iterator));
	it->nod = lst->head;
	return it;
}

iterator* iterator_next(iterator* it)
{
	if (it != NULL) {
		it->nod = it->nod->next;
		return it;
	}
	return NULL;
}

iterator* iterator_prev(iterator* it)
{
	if (it != NULL) {
		it->nod = it->nod->prev;
		return it;
	}
	return NULL;
}

node* iterator_get(iterator* it)
{
	return it->nod;
}

list* list_create()
{
	list* lst = (list*) malloc(sizeof(list));
	lst->head = lst->tail = NULL;
	lst->size = 0;
	return lst;
}

void print(list* lst)
{
	if (lst == NULL || lst->head == NULL) {
		return;
	}
	iterator* iter = iterator_create(lst);
	if (iterator_get(iter) != NULL) {
		print_colors(iterator_get(iter)->data);
		printf(" ");
	}
	iter = iterator_next(iter);
	while (iterator_get(iter) != lst->head) {
		print_colors(iterator_get(iter)->data);
		printf(" ");
		iter = iterator_next(iter);
	}
	free(iter);
	printf("\n");
}

void back_insert(list* lst, value_type c)
{
	if (lst == NULL) {
		printf("The list not exists\n");
		return;
	}
	node* new = (node*)malloc(sizeof(node));
	if (lst->head == NULL) {
		lst->head = new;
		lst->head->data = c;
		lst->tail = lst->head;
		lst->head->next = lst->head->prev = lst->tail;
		lst->size++;
	} else {     
		lst->tail->next = new;
		new->prev = lst->tail;
		new->next = lst->head;
		lst->tail = new;
		lst->tail->data = c;
		lst->head->prev = lst->tail;
		lst->size++;
    }
}

void front_insert(list* lst, value_type c)
{
	if (lst == NULL) {
		printf("The list not exists\n");
		return;
	}
	node* new = (node*)malloc(sizeof(node));
	if (lst->head == NULL) {
		lst->head = new;
		lst->head->data = c;
		lst->tail = lst->head;
		lst->head->next = lst->head->prev = lst->tail;
		lst->size++;
	} else {
		lst->head->prev = new;
		new->data = c;
		new->next = lst->head;
		lst->tail->next = new;
		lst->head = new;
		lst->head->prev = lst->tail;
		lst->size++;
	}
}

void delete(list* lst, int k)
{
	if (count(lst) == 0) {
		printf("The list not exists\n");
		return;
	}
	if (k >= count(lst)) {
		printf("This node not exists\n");
		return;
	}
	if (count(lst) == 1 && k == 0) {
		lst->tail = lst->head = NULL;
		lst->size--;
		return;
	}
	iterator* iter = iterator_create(lst);
	for (int i = 0; i < k; i++) {
		iter = iterator_next(iter);
	}
	node* first = iterator_get(iter);
	if (first != lst->head && first != lst->tail) {
		first->prev->next = first->next;
		first->next->prev = first->prev;
		free(first);
		lst->size--;
	} else if (first == lst->head) {
		lst->head = first->next;
		lst->tail->next = lst->head;
		first->next->prev = lst->tail;
		free(first);
		lst->size--;
	} else if (first == lst->tail) {
		lst->tail = first->prev;
		lst->head->prev = lst->tail;
		first->prev->next = lst->head;
		free(first);
		lst->size--;
	}
	free(iter);
}

int count(list* lst)
{
	return lst->size;
}

void destroy(list* lst)
{
	iterator* iter = iterator_create(lst);
	iter = iterator_next(iter);
	while (iterator_get(iter) != lst->head) {
		node *pi = iterator_get(iter);
		iter = iterator_next(iter);
		free(pi);
	}
	free(lst->head);
	free(iter);
	lst->head = 0;
	printf("\n");
}

void task(list *a) {
	if (count(a) > 3) {
		node *x = a->head->next;
		node *y = a->head->prev->prev;
		value_type tmp = x->data;
		x->data = y->data;
		y->data = tmp;
	} else if (count(a) == 2) {
		node *x = a->head;
		node *y = a->head->prev;
		value_type tmp = x->data;
		x->data = y->data;
		y->data = tmp;
	} else {
		return;
	}
}

value_type str_to_enum(char *elem)
{
	if (!strcmp(elem, "BLACK")) {
		return black;
	} else if (!strcmp(elem, "CHARCOAL")) {
		return charcoal;
	} else if (!strcmp(elem, "GRAY")) {
		return gray;
	} else if (!strcmp(elem, "WHITE")) {
		return white;
	} else if (!strcmp(elem, "PINK")) {
		return pink;
	} else if (!strcmp(elem, "FUSHIA")) {
		return fushia;
	} else if (!strcmp(elem, "RED")) {
		return red;
	} else if (!strcmp(elem, "PLUM")) {
		return plum;
	} else if (!strcmp(elem, "PURPLE")) {
		return purple;
	} else if (!strcmp(elem, "COBALT")) {
		return cobalt;
	} else if (!strcmp(elem, "NAVY")) {
		return navy;
	} else if (!strcmp(elem, "BLUE")) {
		return blue;
	} else if (!strcmp(elem, "BLUE_GREEN")) {
		return blue_green;
	} else if (!strcmp(elem, "TURQUOISE")) {
		return turquoise;
	} else if (!strcmp(elem, "EMERALD")) {
		return emerald;
	} else if (!strcmp(elem, "DARK_GRAY")) {
		return dark_gray;
	} else if (!strcmp(elem, "LIGHT_GRAY")) {
		return light_gray;
	} else if (!strcmp(elem, "BONE")) {
		return bone;
	} else if (!strcmp(elem, "LIGHT_PINK")) {
		return light_pink;
	} else if (!strcmp(elem, "MAUVE")) {
		return mauve;
	} else if (!strcmp(elem, "VIOLET")) {
		return violet;
	} else if (!strcmp(elem, "PERIWINCLE")) {
		return periwinkle;
	} else if (!strcmp(elem, "LIGHT_BLUE")) {
		return light_blue;
	} else if (!strcmp(elem, "SEA_FOAM")) {
		return sea_foam;
	} else if (!strcmp(elem, "DARK_BROWN")) {
		return dark_brown;
	} else if (!strcmp(elem, "BROWN")) {
		return brown;
	} else if (!strcmp(elem, "BEIGE")) {
		return beige;
	} else if (!strcmp(elem, "CREAM")) {
		return cream;
	} else if (!strcmp(elem, "PEACH")) {
		return peach;
	} else if (!strcmp(elem, "CORAL")) {
		return coral;
	} else if (!strcmp(elem, "RUST")) {
		return rust;
	} else if (!strcmp(elem, "ORANGE")) {
		return orange;
	} else if (!strcmp(elem, "MUSTARD")) {
		return mustard;
	} else if (!strcmp(elem, "BANANA")) {
		return banana;
	} else if (!strcmp(elem, "GREEN")) {
		return green;
	} else if (!strcmp(elem, "OLIVE")) {
		return olive;
	} else if (!strcmp(elem, "HUNTER")) {
		return hunter;
	} else if (!strcmp(elem, "TEAL")) {
		return teal;
	} else if (!strcmp(elem, "CAMEL")) {
		return camel;
	} else if (!strcmp(elem, "COPPER")) {
		return copper;
	} else if (!strcmp(elem, "YELLOW")) {
		return yellow;
	} else if (!strcmp(elem, "CHARTREUSE")) {
		return chartreuse;
	} else if (!strcmp(elem, "CELERY")) {
		return celery;
	} else {
		return -1;
	}
}

void print_colors(value_type elem)
{
	if (elem == 0) {
		printf("BLACK");
	} else if (elem == 1) {
		printf("CHARCOAL");
	} else if (elem == 2) {
		printf("GRAY");
	} else if (elem == 3) {
		printf("WHITE");
	} else if (elem == 4) {
		printf("PINK");
	} else if (elem == 5) {
		printf("FUSHIA");
	} else if (elem == 6) {
		printf("RED");
	} else if (elem == 7) {
		printf("PLUM");
	} else if (elem == 8) {
		printf("PURPLE");
	} else if (elem == 9) {
		printf("COBALT");
	} else if (elem == 10) {
		printf("NAVY");
	} else if (elem == 11) {
		printf("BLUE");
	} else if (elem == 12) {
		printf("BLUE_GREEN");
	} else if (elem == 13) {
		printf("TURQUOISE");
	} else if (elem == 14) {
		printf("EMERALD");
	} else if (elem == 15) {
		printf("DARK_GRAY");
	} else if (elem == 16) {
		printf("LIGHT_GRAY");
	} else if (elem == 17) {
		printf("BONE");
	} else if (elem == 18) {
		printf("LIGHT_PINK");
	} else if (elem == 19) {
		printf("MAUVE");
	} else if (elem == 20) {
		printf("VIOLET");
	} else if (elem == 21) {
		printf("PERIWINCLE");
	} else if (elem == 22) {
		printf("LIGHT_BLUE");
	} else if (elem == 23) {
		printf("SEA_FOAM");
	} else if (elem == 24) {
		printf("DARK_BROWN");
	} else if (elem == 25) {
		printf("BROWN");
	} else if (elem == 26) {
		printf("BEIGE");
	} else if (elem == 27) {
		printf("CREAM");
	} else if (elem == 28) {
		printf("PEACH");
	} else if (elem == 29) {
		printf("CORAL");
	} else if (elem == 30) {
		printf("RUST");
	} else if (elem == 31) {
		printf("ORANGE");
	} else if (elem == 32) {
		printf("MUSTARD");
	} else if (elem == 33) {
		printf("BANANA");
	} else if (elem == 34) {
		printf("GREEN");
	} else if (elem == 35) {
		printf("OLIVE");
	} else if (elem == 36){
		printf("HUNTER");
	} else if (elem == 37) {
		printf("TEAL");
	} else if (elem == 38) {
		printf("CAMEL");
	} else if (elem == 39) {
		printf("COPPER");
	} else if (elem == 40) {
		printf("YELLOW");
	} else if (elem == 41) {
		printf("CHARTREUSE");
	} else if (elem == 42) {
		printf("CELERY");
	}
}

char *gets_(char *s)
{
	fflush(stdin);
	int i, k = getchar();
	if (k == EOF)
		return NULL;
	for (i = 0; k != EOF && k != '\n'; ++i) {
		s[i] = k;
		k = getchar();
		if (k == EOF && !feof(stdin))
			return NULL;
	}
	s[i] = '\0';
	return s;
}
