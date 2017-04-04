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
	int arr[100][100];
	int rows = 0, i, j, columns = 0, temp, p = 0;
	printf("Please enter matrix rows\n");
	scanf("%d", &rows);
	if (rows < 1 || rows>100) {
		printf("Wrong input\n");
		exit(0);
	}
	printf("Please enter matrix columns\n");
	scanf("%d", &columns);
	if (columns < 1 || columns>100) {
		printf("Wrong input\n");
		exit(0);
	}
	if (rows != columns) {
		printf("Wrong input\n");
		exit(0);
	}
	printf("Please enter all matrix variables\n");
	for (i = 0;i < columns;i++) {
		for (j = 0;j < rows;j++) {
			scanf("%d", &arr[j][i]);
		}
	}

	for (i = 0;i < columns;i++) {
			temp = arr[p][i];
			arr[p][i] = arr[rows - p-1][i];
			arr[rows - p-1][i] = temp;
			p++;
	}
	/*Print*/
	for (i = 0;i < columns;i++) {
		for (j = 0;j < rows;j++) {
			printf("%d ", arr[j][i]);
		}
		printf("\n");
	}
}