#include <stdio.h>
#include <stdlib.h>
#include "vector_dbl.h"
#include "vector_int.h"
#include "matrix.h"

void print_line(v_int *CIP, v_int *PI, v_dbl *YE, int n, int i){
	int begin = 0;
	int end = 0;
	begin = get_int(CIP, i);
	if (i == size_int(CIP) - 1) {
		end = size_dbl(YE);
	} else {
		end = get_int(CIP, i+1);    
	}
	for (int j = 0; j < n; j++){
		if ((begin<end) && get_int(PI, begin)==j+1){
			printf("%lf ", get_dbl(YE, begin));
			begin++;
		}
		else {
			printf("%d ", 0);
		}
	}
}

void print_matrix(v_int *CIP, v_int *PI, v_dbl *YE, int m, int n){
	for (int i = 0; i < m; i++){
		print_line(CIP, PI, YE, n, i);
		printf("\n");
	}
}

void task(v_int *CIP, v_dbl *YE) {
	int begin = 0;
	int end = 0;
	double max_el = max(YE);
	int i=0;
	while (i < size_dbl(YE)){
		if (get_dbl(YE, i) == max_el) {
			for (int j = 0; j < size_int(CIP); j++) {
				begin = get_int(CIP, j);
				if (j == size_int(CIP) - 1) {
					end = size_dbl(YE);
				} else {
					end = get_int(CIP, j+1);    
				}
				if ((begin <= i) && (end > i)) {
					for (int k = begin; k < end; k++) {
						YE->begin[k] = get_dbl(YE, k)/max_el;
					}
					i=end;
					break;
				}
			}
		}
		else {
			i++;
		}
	}
}