#include <stdio.h>

int isPalyndrom(char* str, int length) {
	static int i=0;
	static int middle = 0;
	if (length % 2 == 0) middle = length/2;
	else middle = (length + 1) / 2;
	if ((i+1) == middle && length % 2 == 0) {
		if (str[i] == str[i + 1]) return 1;
		else return 0;
	}
	if (i == middle && length % 2 != 0) return 1;
	if (str[i] == str[length - i-1]) {
		i++;
		return isPalyndrom(str, length);
	}
}

int  main() {
	char str[] = "ba";
	//printf("%d", 7 / 2);
	printf("num is %d\n", isPalyndrom(str,strlen(str)));
	return 0;
}