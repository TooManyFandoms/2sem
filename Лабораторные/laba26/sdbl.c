#include "sdbl.h"

void sdbl_init(stack_dbl *s){
	s->size=0;
	s->buf=NULL;
	s->pool_size=0;
}

void sdbl_destroy(stack_dbl *s){
	s->size=0;
	s->pool_size=0;
	free(s->buf);
	s->buf=NULL;
}

static bool grow_buffer(stack_dbl *s){
	size_t new_size=s->pool_size*2;
	if (s->pool_size==0){
		new_size=4;
	}
	double *new_buf=realloc(s->buf, new_size*sizeof(double));
	if (new_buf==NULL){
		return false;
	}
	s->buf=new_buf;
	s->pool_size=new_size;
	return true;
}

bool sdbl_push(stack_dbl *s, double el){
	if (s->size >= s->pool_size){
		if (!grow_buffer(s)){
			return false;
		}	
	}
	s->buf[s->size]=el;
	s->size++;
	return true;
}

double sdbl_pop(stack_dbl *s){
	double res = s->buf[s->size-1];
	s->size--;
	return res;
}

double sdbl_peek(stack_dbl *s){
	return s->buf[s->size-1];
}

bool sdbl_is_empty(stack_dbl *s){
	return s->size==0;
}
