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
	int even[100];
	int odd[100];
	int size = 0,i,j,num1=0,num2=0,starteven=0,temp;
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
	/* Sort even and odd numbers in arrays */
	for (int i = 0; i<size;i++)
	{
		if (arr[i] % 2 == 0) {
			even[num1] = arr[i];
			num1++;
		}
		else {
			odd[num2] = arr[i];
			num2++;
		}
	}
	/* Sort even number's array*/
	for (int i = 0; i<num1;i++)
	{
		for (int j = 0;j<num1 - 1;j++)
		{
			if (even[j]>even[j + 1])
			{
				int temp = even[j];
				even[j] = even[j + 1];
				even[j + 1] = temp;
			}
		}
	}
	/* Sort odd number's array*/
	for (int i = 0; i<num2;i++)
	{
		for (int j = 0;j<num2 - 1;j++)
		{
			if (odd[j]>odd[j + 1])
			{
				int temp = odd[j];
				odd[j] = odd[j + 1];
				odd[j + 1] = temp;
			}
		}
	}
	if (even[0] < odd[0]) {
		for (i = 0;i < num1;i++) {
			printf("%d ", even[i]);
		}
		for (i = 0;i < num2;i++) {
			printf("%d ", odd[i]);
		}
	}
	else {
		for (i = 0;i < num2;i++) {
			printf("%d ", odd[i]);
		}
		for (i = 0;i < num1;i++) {
			printf("%d ", even[i]);
		}
	}
}