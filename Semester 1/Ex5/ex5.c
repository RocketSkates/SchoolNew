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