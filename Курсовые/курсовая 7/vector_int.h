#ifndef __VECTORINT_H__
#define __VECTORINT_H__

#include <stdbool.h>
#include <string.h>

typedef struct {
	int *begin;
	size_t size;
	size_t allocated;
} v_int;

void create_int(v_int *v);

void destroy_int(v_int *v);

bool is_empty_int(v_int *v);

bool is_full_int(v_int *v);

void push_int(v_int *v, int value);

int pop_int(v_int *v);

void print_int(v_int *v);

size_t size_int(v_int *v);

int get_int(v_int *v, int i);

#endif
