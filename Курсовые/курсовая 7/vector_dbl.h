#ifndef __VECTORDBL_H__
#define __VECTORDBL_H__

#include <stdbool.h>
#include <string.h>

typedef struct {
	double *begin;
	size_t size;
	size_t allocated;
} v_dbl;

void create_dbl(v_dbl *v);

void destroy_dbl(v_dbl *v);

bool is_empty_dbl(v_dbl *v);

bool is_full_dbl(v_dbl *v);

void push_dbl(v_dbl *v, double value);

double pop_dbl(v_dbl *v);

void print_dbl(v_dbl *v);

size_t size_dbl(v_dbl *v);

double get_dbl(v_dbl *v, int i);

double fabs(double a);

double max(v_dbl *YE);

#endif
