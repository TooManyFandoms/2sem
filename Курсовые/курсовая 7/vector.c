#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector_dbl.h"
#include "vector_int.h"

double get_dbl(v_dbl *v, int i){
	return v->begin[i];
}

int get_int(v_int *v, int i){
	return v->begin[i];
}

void print_dbl(v_dbl *v) {
	for (int i = 0; i < v->size; ++i) {
		printf("%lf ", get_dbl(v, i));
	}
	printf("\n");
}

void print_int(v_int *v) {
	for (int i = 0; i < v->size; ++i) {
		printf("%d ", get_int(v, i));
	}
	printf("\n");
}

bool is_empty_dbl(v_dbl *v) {
	return v->size == 0;
}

bool is_empty_int(v_int *v) {
	return v->size == 0;
}

bool is_full_dbl(v_dbl *v) {
	return v->size == v->allocated;
}

bool is_full_int(v_int *v) {
	return v->size == v->allocated;
}

size_t size_dbl(v_dbl *v) {
	return v->size;
}

size_t size_int(v_int *v) {
	return v->size;
}

void create_dbl(v_dbl *v) {
	v->size = 0;
	v->allocated = 0;
	v->begin = NULL;
}

void create_int(v_int *v) {
	v->size = 0;
	v->allocated = 0;
	v->begin = NULL;
}

void destroy_dbl(v_dbl *v) {
	free(v->begin);
	v->size = 0;
	v->allocated = 0;
	v->begin = NULL;
}

void destroy_int(v_int *v) {
	free(v->begin);
	v->size = 0;
	v->allocated = 0;
	v->begin = NULL;
}

void push_dbl(v_dbl *v, double value) {
	if (is_full_dbl(v)) {
		v->allocated += 10;
		v->begin = realloc(v->begin, v->allocated * sizeof(double));
	}
	v->begin[v->size] = value;
	v->size++;
}

void push_int(v_int *v, int value) {
	if (is_full_int(v)) {
		v->allocated += 10;
		v->begin = realloc(v->begin, v->allocated * sizeof(int));
	}
	v->begin[v->size] = value;
	v->size++;
}

double pop_dbl(v_dbl *v) {
	double res = get_dbl(v, v->size - 1);
	v->size--;
	return res;
}

int pop_int(v_int *v) {
	int res = get_int(v, v->size - 1);
	v->size--;
	return res;
}

double fabs(double a) {
	if (a < 0) {
		return -a;
	}
	return a;
}

double max(v_dbl *YE) {
	double max_el = get_dbl(YE, 0);
	for (int i = 0; i < size_dbl(YE); i++) {
		if (fabs(get_dbl(YE, i)) > max_el) {
			max_el = get_dbl(YE, i);
		}
	}
	return max_el;
}
