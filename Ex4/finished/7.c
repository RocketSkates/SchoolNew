
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char arr[100], arr2[100];
	char letter,temp;
	int i,j=0,size=0;

	printf("Please enter string\n");
	gets(arr);

	printf("Please enter letter\n");
	scanf(" %c", &letter);

	for (i = 0; arr[i]!='\0'; i++)
	{
		size++;
	}

	for (i = 0; i<size; i++)
	{
			if (arr[i] != letter)
			{
				arr2[j] = arr[i];
				j++;
			}
	}
	for (i = 0;i < j;i++) {
		printf("%c", arr2[i]);
	}
	printf("\n");
}