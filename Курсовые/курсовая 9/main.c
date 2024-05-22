#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "vector.h"

int main(int argc, char const *argv[])
{	
	vector v;
	create(&v);
	value_type t;
	while (!feof(stdin)) {
		printf("Enter key & value | other to break: ");
		if (scanf("%Lf%s", &t.key, t.value) == 2) {
			push(&v, t);
		} else {
			break;
		}
	}
	
	printf("\n");
	insertion_sort(&v);
	print(&v);
	printf("\n");
	fflush(stdin);
	long double find;
	int err;
	char c;
	while ((c = getchar()) != '\n' && c != EOF) { };
	printf("\nSearch in table:\n");
	while (1) {
		if (!is_empty(&v)) {
			printf("Enter key | ctrl + d to break: ");
			err = scanf("%Lf", &find); 
			if (err == 0) {
				printf("Wrong input\n");
				while ((c = getchar()) != '\n' && c != EOF) { };
				continue;
			}
			if (err == EOF) {
				break;
			}
			searching(&v, find);	
		} else  {
			printf("The table is empty\n");
			break;
		}
		
	}
	printf("\n");
	destroy(&v);
	return 0;
}
