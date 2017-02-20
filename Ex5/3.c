#include <stdio.h>

void intersect(int* A, int sizeA, int* B, int sizeB, int** AintB) {
	int i, j;
	int size = 0;
	int *temp;
	if (sizeA >= sizeB) {
		for (i = 0;i < sizeA;i++)
			for (j = 0;j < sizeB;j++) {
				if (A[i] == B[j]) {
					temp = (int*) realloc(*AintB, ++size * sizeof(int));
					AintB[size - 1] = A[i];
				}
			}
	}
	*AintB = temp;
}


int main()
{
	int A[] = { 1,2,3,4,5 };
	int B[] = { 4,5,6,7,8 };
	int *a;
	int *b;
	int sum,i=0,sizeA=0,sizeB=0;
	int inter[] = { 1,2 };
	int* AintB = inter;
	a = A;
	b = B;

	intersect(a,5,b,5, AintB);

	while (AintB[i] != '\0') {
		printf("%d\n", AintB[i]);
		i++;
	}
	//printf("%d", sum);
}