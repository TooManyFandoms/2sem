#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "list.h"

int main(int argc, char const *argv[])
{	
	printf("\nWrite:\nFRONT to add elem in list front\n");
	printf("BACK to add elem in list back\n");
	printf("DELETE to delete elem from list\n");
	printf("PRINT to show list\n");
	printf("SIZE to show size of list\n");
	printf("TASK to swap second and penultimate elems\n");
	printf("COLORS to show enum colors list\n");
	printf("HELP to see commands again\n");
	printf("BYE to exit\n\n");
	list* l;
	int key;
	l = list_create();
	char str[100];
	char elem[100];
	char *choose;
	char *el;
	bool flag = true;
	while (flag) {
		choose = gets_(str);
		if (!feof(stdin)) {
			if (!strcmp(choose, "FRONT")) {
				printf("Write color from enum to add it to list:\n");
				el = gets_(elem);
				if (!feof(stdin)) {
					if (str_to_enum(el) != -1) {
						front_insert(l, str_to_enum(el));
					} else {
						printf("This is no color\n");
					}
				}
			} else if (!strcmp(choose, "BACK")) {
				printf("Write color from enum to add it to list:\n");
				el = gets_(elem);
				if (!feof(stdin)) {
					if (str_to_enum(el) != -1) {
						back_insert(l, str_to_enum(el));
					} else {
						printf("This is no color\n");
					}
				}
			} else if (!strcmp(choose, "DELETE")) {
				printf("Enter key:\n");
				scanf("%d", &key);
				delete(l, key);
			} else if (!strcmp(choose, "PRINT")) {
				printf("\n");
				print(l);
			} else if (!strcmp(choose, "SIZE")) {
				printf("Size: %d\n", count(l));
			} else if (!strcmp(choose, "TASK")) {
				task(l);
			} else if (!strcmp(choose, "COLORS")) {
				printf("Colors enum list:\n");
				for (int i = 0; i < 43; i++) {
					printf("%d: ", i);
					print_colors(i);
					printf("\n");
				}
			} else if (!strcmp(choose, "BYE")) {
				if (count(l) != 0) {
					destroy(l);
				}
				flag = false;	
			} else if (!strcmp(choose, "HELP")) {
				printf("\nWrite:\nFRONT to add elem in list front\n");
				printf("BACK to add elem in list back\n");
				printf("DELETE to delete elem from list\n");
				printf("PRINT to show list\n");
				printf("TASK to swap second and penultimate elems\n");
				printf("COLORS to show enum colors list\n");
				printf("HELP to see commands again\n");
				printf("BYE to exit\n\n");
			} else if (!strcmp(choose, "")) {
				continue;
			} else {
				printf("Wrong command\n");
				continue;
			}
		} else {
			if (count(l) != 0) {
				destroy(l);
			}
			break;
		}
	}
	free(l);
	return 0;
}
