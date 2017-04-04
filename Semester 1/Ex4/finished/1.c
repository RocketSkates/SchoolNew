
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int arr[100], arr2[50];
	int size = 0,i,j,num=0,k=0,p,size2=0;
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
	for (i = 0; i<size; i++)
	{
		for (j = i + 1; j<size; j++)
		{
			/* If duplicate found then increment count by 1 */
			if (arr[i] == arr[j])
			{
				arr2[k] = arr[i];
				k++;
					for (p = 0; p<k; p++)
					{
						if (arr2[p] == arr[i])
							break;
					}
					num++;
			}
		}
		
	}

	k = 0;
	for (p = 0; p<size; p++)
	{
		if (arr2[p] == arr[p])
			k++;
	}
	if (k == size) {
		printf("%d\n", 1);
		exit(0);
	}
	printf("%d\n", num);
}