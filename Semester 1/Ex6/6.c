#include <stdio.h>

int copyUpperCase(const char* A, char* B) {
	static int i=0;
	static int iB = 0;
	static int num = 0;
	if (A[i] == '\0') return num;
	if (A[i] > 64 && A[i] < 91) {
		B[iB] = A[i];
		i++;
		iB++;
		num++;
		return copyUpperCase(A, B);
	}
	else {
		i++;
		return copyUpperCase(A, B);
	}
}

int  main() {
	const char A[50] = "StUdEnT";
	char B[50];
	//printf("%d", 7 / 2);
	printf("num is %d\n", copyUpperCase(A, B));
	return 0;
}