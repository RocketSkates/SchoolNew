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

int	existsInStrings(char* strings[], int size, char ch) {
	static int flag = 0;
	static int i = 0;
	if (i == size) {
		return flag;
	}
	else {
		if (charNExist(strings[i], ch) > 0) {
			flag = 1;
			return flag;
		}
		else {
			i++;
			return existsInStrings(strings, size, ch);
		}
	}

}

int  main() {
	/*char str[] = "bkdbkdsakakakjllkajkjkjk";
	char c = 'k';
	char* s;
	s = str;*/
	char* strings[] = { "summer", "winter", "spring" };
	char ch4 = 'e';
	int size = 3;
	printf("num is %d\n", existsInStrings(strings,size,ch4));
	return 0;
}