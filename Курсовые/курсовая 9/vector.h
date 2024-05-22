#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <stdbool.h>

typedef struct
{
	long double key;
	char value[100];
} value_type;

typedef struct 
{
	value_type *begin;
	size_t size;
	size_t allocated;
} vector;

void create(vector *v);

void destroy(vector *v);

bool is_empty(vector *v);

bool is_full(vector *v);

void push(vector *v, value_type value);

value_type pop(vector *v);

void print(vector *v);

size_t size(vector *v);

int comparator(long double x, long double y);

void insertion_sort(vector *v);

int bin_search(vector *v, long double key);

void searching(vector *v, long double key);

#endif
