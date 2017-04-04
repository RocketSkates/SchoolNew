#include <stdio.h>

int SumStr(char* str) {
	int sum = 0,i;
	char *p = str;
	for (i = 0; str[i] != '\0'; i++) {
		if (str[i]>47 && str[i]<57) {
			sum = sum + (str[i] - '0');
		}
		p++;
	}
	return sum;
}

void Strcat(char* t, char* s) {
	int i,sizes=0,flag=0,j;
	for (i = 0; s[i] != '\0'; i++) {
		sizes++;
	}
	i = 0;

	while (flag != 1) {
		if (t[i] == '\0') {
			for (j = 0; j <sizes ; j++) {
				t[i + j] = s[j];
				flag = 1;
			}
		}
		i++;
	}
}

void Strend(char* s, char* t) {
	int i, sizes = 0, flag = 0, j, sizet=0;
	for (i = 0; s[i] != '\0'; i++) {
		sizes++;
	}
	for (i = 0; s[i] != '\0'; i++) {
		sizet++;
	}
	i = 0;

	while (s[i] != '\0') {
		if (s[i] == t[0]) {
			for (j = 0; j <sizet; j++) {
				if (s[i+j] == t[j]) {
					if ((i + j) == sizes) {
						flag = 1;
					}
				}
				else flag = 0;
			}
		}
		i++;
	}
	return flag;
}

int main()
{
	char label[] = "nksa843nlk346j43ljls";
	char *labelPtr;
	char tt[] = "dffh";
	char *t;
	char ss[] = "winddffh";
	char *s;
	int sum;
	s = ss;
	t = tt;
	Strend(s,t);
	//printf("%d", sum);
}