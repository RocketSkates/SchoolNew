#include <stdio.h>

typedef struct
{
	char * bookName;
	int bookCode;
	int NumOfbooks;
}Book;

int** insertbookToStore(Book ** bookstore, int *size) {
	char name[30];
	int code,i,num=0;
	Book **tmp = bookstore;
	printf("Enter book code:\n");
	scanf("%d", &code);

	//Check if code exists in bookstore
	for (i = 0;i < *size;i++) {
		if (bookstore[i]->bookCode == code) {
			printf("Enter num of books:\n");
			scanf("%d", &num);
			bookstore[i]->NumOfbooks = bookstore[i]->NumOfbooks + num;
			exit();
		}
	}

	printf("Enter book name:\n");
	scanf("%s", &name);
	printf("Enter num of books:\n");
	scanf("%d", &num);

	bookstore = (Book**)realloc(bookstore, ((*size)+1)*(sizeof(Book*)));
	if (bookstore == NULL) return tmp;
	bookstore[*size + 1]->bookCode = code;
	bookstore[*size + 1]->bookName = name;
	bookstore[*size + 1]->NumOfbooks = num;
	(*size)++;
	return *bookstore;
}

int  main() {
	struct Book *bookstore;
	bookstore[1]

}