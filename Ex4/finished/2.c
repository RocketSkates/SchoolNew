/* Sigal Gurman */
/* 204734669 */
/* 27.12.2016 */
/* ******* */
/*  */
/* ******* */


#include <stdio.h>
#include <stdlib.h>

int main()
{
	int arr[100];
	int size = 0,i,j,num=0;
	printf("Please enter array size\n");
	scanf("%d", &size);
	if (size < 1 || size>100) {
		printf("Wrong input\n");
		exit(0);
	}
	printf("Please enter all array variables\n");
	for (i = 0;i < size;i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i<size;i++)
	{
		for (int j = 0;j<size - 1;j++)
		{
			if (arr[j]>arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	for (i = 0;i < size;i++) {
		printf("%d ", arr[i]);
	}
}