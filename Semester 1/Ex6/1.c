#include <stdio.h>

typedef struct Product
{
	char* name;
	int code;
	int amount;
}product;

typedef struct Store
{
	product ** items;
	int num_of_items;
	char* name;
}store;

product* createItem(product* p) {
	product* p1 = NULL;
	strcpy(p1->name, p->name);
	printf("%c", p1->name);
}

int  main() {
	struct Product p;
}