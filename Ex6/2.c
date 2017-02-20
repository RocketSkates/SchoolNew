#include <stdio.h>

int sum(unsigned int i) {

	if (i <= 9) {
		return i;
	}
	return i + sum(i/10);
}

int  main() {
	int i = 464;
	printf("Sum of %d is %d\n", i, sum(i));
	return 0;
}