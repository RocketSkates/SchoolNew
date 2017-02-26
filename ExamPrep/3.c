#include <stdio.h>
#include <string.h>

int recStrCmp(char* str1, char* str2) {
	static int result;
	static int i = 0;
	if (str1[i] != str2[i]) {
		return -1;
	}
	if (*str1 == *str2) {
		result = 0;
		return recStrCmp(str1+1, str2+1);
	}

}


void main()
{
	char str1[5] = "abcde";
	char str2[5] = "abcde";
	char* s1;
	char* s2;
	s1 = str1;
	s2 = str2;
	printf("%d", recStrCmp(s1, s2));
}