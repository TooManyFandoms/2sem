#include "sort.h"

double remove_max (stack_dbl *s){
	stack_dbl tmp;
	sdbl_init(&tmp);
	double max=sdbl_peek(s);
	while (!sdbl_is_empty(s)){
		if (sdbl_push(&tmp, sdbl_pop(s))){
			if (sdbl_peek(&tmp) > max){
				max=sdbl_peek(&tmp);
			}
		}
	}
	int n=0;
	while (!sdbl_is_empty(&tmp)){
		if ((sdbl_peek(&tmp)==max)&&(n==0)){
			n++;
			sdbl_pop(&tmp);
		}
		else {
			sdbl_push(s, sdbl_pop(&tmp));	
		}
	}
	sdbl_destroy(&tmp);
	return max;
}

void sort(stack_dbl *s){
	stack_dbl res;
	sdbl_init(&res);
	while (!sdbl_is_empty(s)){
		sdbl_push(&res, remove_max(s));
	}
	stack_dbl prom;
	sdbl_init(&prom);
	while (!sdbl_is_empty(&res)){
		sdbl_push(&prom, sdbl_pop(&res));
	}
	sdbl_destroy(&res);
	while (!sdbl_is_empty(&prom)){
		sdbl_push(s, sdbl_pop(&prom));
	}
	sdbl_destroy(&prom);
}
