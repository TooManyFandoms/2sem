#ifndef LIST_H
#define LIST_H

typedef enum {
	black,
	charcoal,
	gray,
	white,
	pink,
	fushia,
	red,
	plum,
	purple,
	cobalt,
	navy,
	blue,
	blue_green,
	turquoise,
	emerald,
	dark_gray,
	light_gray,
	bone,
	light_pink,
	mauve,
	violet,
	periwinkle,
	light_blue,
	sea_foam,
	dark_brown,
	brown,
	beige,
	cream,
	peach,
	coral,
	rust,
	orange,
	mustard,
	banana,
	green,
	olive,
	hunter,
	teal,
	camel,
	copper,
	yellow,
	chartreuse,
	celery,
} value_type;

typedef struct _list_node
{
	value_type data;
	struct _list_node *next;
	struct _list_node *prev;
} node;

typedef struct _iterator
{
	node* nod;
} iterator;

typedef struct _list
{
	node* head;
	node* tail;
	int size;
} list;

list* list_create();

iterator* iterator_create(list* lst);

iterator* iterator_next(iterator* it);

iterator* iterator_prev(iterator* it);

node* iterator_get(iterator* it);

void iterator_destroy(iterator* it);

void back_insert(list* lst, value_type value);

void front_insert(list* lst, value_type value);

void delete(list* lst, int k);

void print(list* lst);

void function(list* lst, int k);

int count(list* lst);

void destroy(list* lst);

void task(list *a);

value_type str_to_enum(char *elem);

void print_colors(value_type elem);

char *gets_(char *s);

#endif
