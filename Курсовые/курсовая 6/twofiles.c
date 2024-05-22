#include <stdio.h>

#include "countries.h"

int main(int argc, char * argv[]) {
	if (argc!=3){
		printf("Please choose 2 files\n");
		return 1;
	}
	FILE * in = fopen(argv[1],"r");
	FILE * out = fopen(argv[2],"w");
	if (in==NULL){
		printf("Can't open first file\n");
		return 2;
	}
	if (out==NULL){
		printf("Can't open second file\n");
		return 3;
	}
	europe c;
	while (fscanf(in, "%[^:]:%[^:]:%d:%d\n", c.country, c.capital, &c.countpop, &c.cappop)==4){
		if (fwrite(&c, sizeof(c), 1, out)!=1){
			printf("Error\n");
			return 4;
		}
	}
}
