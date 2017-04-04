#include <stdio.h>

int charNExist(char* str, char c) {
	static int i=0;
	static int num = 0;
	if (str[i] != '\0'){
		if (str[i] == c) {
			i++;
			num++;
			return charNExist(str, c);
		}
		else {
			i++;
			return charNExist(str, c);
		}
	}
	else return num;
}

int  main() {
	char str[] = "bkdbkdsakakakjllkajkjkjk";
	char c = 'k';
	char* s;
	s = str;
	printf("num is %d\n", charNExist(s,c));
	return 0;
}