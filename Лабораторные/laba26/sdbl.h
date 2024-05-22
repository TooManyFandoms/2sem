#ifndef _STACK_H_
#define _STACK_H_

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
	size_t size;
	size_t pool_size;
	double *buf;
} stack_dbl;

void sdbl_init(stack_dbl *s);
void sdbl_destroy(stack_dbl *s);
bool sdbl_push(stack_dbl *s, double el);
double sdbl_pop(stack_dbl *s);
double sdbl_peek(stack_dbl *s);
bool sdbl_is_empty(stack_dbl *s);

#endif
