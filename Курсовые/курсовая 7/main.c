#include <stdio.h>
#include <stdlib.h>
#include "vector_dbl.h"
#include "vector_int.h"
#include "matrix.h"

int main(void)
{
	int m, n;
	double num;
	v_int CIP, PI;
	v_dbl YE;
    
	printf("Input size: ");
	scanf("%d%d", &m, &n);

	int count = 0;
	create_int(&CIP);
	create_int(&PI);
	create_dbl(&YE);
	for (int i = 1; i <= m; i++) {
		push_int(&CIP, count);
		for (int j = 1; j <= n; j++) {
			scanf("%lf", &num);
			if (num != 0) {
				push_int(&PI, j);
				push_dbl(&YE, num);
				count++;
			}
		}
	}

	printf("\n");
    
	if (is_empty_dbl(&YE)) {
		printf("Can't divide by zero\n");
		destroy_int(&CIP);
		return 1;
	}

	task(&CIP, &YE);
	print_matrix(&CIP, &PI, &YE, m, n);
	printf("\n");
	printf("CIP: ");
	print_int(&CIP);
	printf("PI: ");
	print_int(&PI);
	printf("YE: ");
	print_dbl(&YE);

	destroy_int(&CIP);
	destroy_int(&PI);
	destroy_dbl(&YE);

	return 0;
}
