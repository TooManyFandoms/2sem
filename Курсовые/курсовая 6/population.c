#include <stdio.h>
#include <string.h>

#include "countries.h"

int main(int argc, char * argv[]){
	int country_pop=0;
	int capital_pop=0;
	int n=0;
	int k=0;
	europe p;
	float avg_country=0;
	float avg_capital=0;
	if (argc==2 && (strcmp(argv[1],"-d")!=0)){
		FILE * in = fopen(argv[1],"r");
		if (in==NULL){
			printf("Can't open file\n");
			return 2;
		}
		while (fread(&p, sizeof(p), 1, in)==1){
			country_pop=country_pop+p.countpop;
			n=n+1;
			capital_pop=capital_pop+p.cappop;
			k=k+1;
		}
		fseek(in, 0, SEEK_SET);
		if (n==0){
			printf("There is no countries in file\n");
			return 4;
		}
		avg_country=country_pop/n;
		avg_capital=capital_pop/k;
		while (fread(&p, sizeof(p), 1, in)==1){
			if ((p.countpop>avg_country) && (p.cappop<avg_capital)){
				printf("%s\n", p.country);
			}
		}
	}
	else if (argc==3 && (strcmp(argv[2],"-d")==0)){
		FILE * in = fopen(argv[1],"r");
		if (in==NULL){
			printf("Can't open file\n");
			return 5;
		}
		while (fread(&p, sizeof(p), 1, in)==1){
			country_pop=country_pop+p.countpop;
			n=n+1;
		}
		fseek(in, 0, SEEK_SET);
		if (n==0){
			printf("There is no countries in file\n");
			return 6;
		}
		avg_country=country_pop/n;
		while (fread(&p, sizeof(p), 1, in)==1){
			if (p.countpop>avg_country){
				printf("%s\n", p.country);
			}
		}

	}
	else {
		printf("Please choose file\n");
	}
}