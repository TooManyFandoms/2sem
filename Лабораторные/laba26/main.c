#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "sdbl.h"
#include "sort.h"

int main(){
	stack_dbl s;
	sdbl_init(&s);
	double el=0;
	printf("Enter elements:\n");
	while (scanf("%lf", &el)==1){
		if (!sdbl_push(&s, el)){
			printf("Can't be add");
		}
	}
	sort(&s);
	printf("Your sorted stack:\n");
	while (!sdbl_is_empty(&s)){
		printf("%lf ", sdbl_pop(&s));	
	}
	printf("\n");
}
