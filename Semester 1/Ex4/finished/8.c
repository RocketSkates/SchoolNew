
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char arr[100], arr2[100];
	char letter,temp;
	int i,j=0,size=0;

	printf("Please enter string\n");
	gets(arr);

	for (i = 0; arr[i] != '\0'; i++)
	{
		size++;
	}

	for (i = 0; i<size; i=i+2)
	{
		if (i != size - 1) {
			temp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = temp;
			}
	}
	for (i = 0;i < size;i++) {
		printf("%c", arr[i]);
	}
	printf("\n");
}