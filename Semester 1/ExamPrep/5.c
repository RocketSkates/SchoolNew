#include <stdio.h>
#include <string.h>

char** initStrings(int* size){
	int s = 0,i;
	char** strings=NULL;
	char buff[1024];
	/*printf("Enter size:\n");
	scanf("%d", size);*/
	if (buff == 0) return NULL;
	strings = malloc((*size) * sizeof(char*));
	if (strings == NULL) return NULL;

	for (i = 0;i < *size; i++) {
		printf("Enter value for index %d\n", i);
		gets(buff);
		strcpy((strings+i),buff);
	}
	return strings;
}


void main()
{
	int size = 2;
	char** str = NULL;
	initStrings(&size);

}