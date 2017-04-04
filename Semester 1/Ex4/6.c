#include <stdio.h>
#include <stdlib.h>

void AskForRowsAndColumns(int *rows, int *columns);
void InitializeArray(int arr[][100], int rows, int columns);
void FlipArray(int arr[][100], int rows, int columns);

void main()
{
	int arr[100][100], rows, columns, i = 0, j = 0;
	int  index = NULL, num = NULL, counter = 0, res = 0;

	AskForRowsAndColumns(&rows, &columns);
	InitializeArray(arr, rows, columns);

	for (i = rows - 1; i >= 0; i--)
	{
		if (index != NULL && num != NULL)
		{
			if (counter == 3 && (index - 1) < columns && (index - 1) >= 0 && arr[i][index - 1] == num)
			{
				res = 1;
				break;
			}
		}

		num = NULL;
		counter = 0;
		for (j = 0; j < columns; j++)
		{
			if (num != NULL && arr[i][j] == num)
			{
				index = j;
				counter++;
			}
			else if (!(counter > 1 && counter % 2 != 0))
			{
				num = arr[i][j];
				counter = 1;
			}
		}

	}

	printf("%d\n", res);
}

void AskForRowsAndColumns(int* rows, int* columns)
{
	printf("Please enter matrix rows\n");
	scanf("%d", &*rows);
	if (*rows < 1 || *rows > 100)
	{
		printf("Wrong input\n");
		exit(1);
	}

	printf("Please enter matrix columns\n");
	scanf("%d", &*columns);
	if ((*columns < 1 || *columns > 100))
	{
		printf("Wrong input\n");
		exit(1);
	}
}

void InitializeArray(int arr[][100], int rows, int columns)
{
	int i, j;

	printf("Please enter all matrix variables\n");
	for (i = 0; i < rows; i++)
	{
		j = 0;
		do {
			scanf("%d", &arr[i][j]);
			j++;
		} while (j != columns);
	}
}

void FlipArray(int arr[][100], int rows, int columns)
{
	int i, j;

	for (i = 0; i < rows; i++)
	{
		if (columns - i - 1 < columns)
		{
			int tmp = arr[i][columns - i - 1];
			arr[i][columns - i - 1] = arr[i][i];
			arr[i][i] = tmp;
		}
	}
}