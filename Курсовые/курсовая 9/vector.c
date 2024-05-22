#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "vector.h"

void print(vector *v)
{
	for (int i = 0; i < v->size; ++i) {
		printf("%Lf %s\n", v->begin[i].key, v->begin[i].value);
	}
	printf("\n");
}

bool is_empty(vector *v)
{
	return v->size == 0;
}

bool is_full(vector *v)
{
	return v->size == v->allocated;
}

size_t size(vector *v)
{
	return v->size;
}

void create(vector *v)
{
	v->size = 0;
	v->allocated = 0;
	v->begin = NULL;
}

void destroy(vector *v)
{
	free(v->begin);
	v->size = 0;
	v->allocated = 0;
	v->begin = NULL;
}

void push(vector *v, value_type value)
{
	if (is_full(v)) {
		v->allocated += 10;
		v->begin = realloc(v->begin, v->allocated * sizeof(value_type));
	}
	v->begin[v->size] = value;
	v->size++;
}

value_type pop(vector *v)
{
	value_type res = v->begin[v->size - 1];
	v->size--;
	return res;
}

int comparator(long double x, long double y)
{
	if (x > y) {
		return 1;
	} else if (x < y) {
		return -1;
	} else {
		return 0;
	}
}

void insertion_sort(vector *v)
{
	value_type tmp;
	int j;
	for (int i = 1; i < size(v); i++) {
		tmp = v->begin[i];
		j = i - 1;
		while ((j >= 0) && (comparator(v->begin[j].key, tmp.key) == 1)) {
			v->begin[j + 1] = v->begin[j];
			j--;
		}
		v->begin[j + 1] = tmp;
	}
}

int bin_search(vector *v, long double key)
{
	int left = -1, right = size(v), mid;
	while (right > left + 1) {
		mid = (left + right) / 2;
		if (comparator(key, v->begin[mid].key) == -1 || comparator(key, v->begin[mid].key) == 0) {
			right = mid;
		} else if (comparator(key, v->begin[mid].key) == 1) {
			left = mid;
		}
	}
	if (comparator(key, v->begin[right].key) == 0) {
		return right;
	} else {
		return -1;
	}
}

void searching(vector *v, long double key)
{
	int it = bin_search(v, key);
	if (it != -1) {
		while(comparator(key, v->begin[it].key) == 0) {
			printf("%Lf %s\n", v->begin[it].key, v->begin[it].value);
			it++;
		}
		printf("\n");
	} else {
		printf("This key no exists\n");
	}
}
