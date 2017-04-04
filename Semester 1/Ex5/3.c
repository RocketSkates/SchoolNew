#include <stdio.h>

void intersect(int* A, int sizeA, int* B, int sizeB, int** AintB) {
	int i, j;
	int size = 0;
	int *temp;
	if (sizeA >= sizeB) {
		for (i = 0;i < sizeA;i++)
			for (j = 0;j < sizeB;j++) {
				if (A[i] == B[j]) {
					size++;
					*AintB = realloc(*AintB, 1 * sizeof(int));
					AintB[size - 1] = A[i];
				}
			}
	}
}


int main()
{
	int A[] = { 1,2,3,4,5 };
	int B[] = { 4,5,6,7,8 };
	int *a = calloc(5 * sizeof *a);
	int *b = calloc(5 * sizeof *b);
	int sum, i = 0, sizeA = 0, sizeB = 0;
	int* AintB = calloc(1 * sizeof(int));
	a = A;
	b = B;

	intersect(a,5,b,5, &AintB);

	while (AintB[i] != '\0') {
		printf("%d\n", AintB[i]);
		i++;
	}
	free(a);
	free(b);
	free(AintB);
	//printf("%d", sum);
}