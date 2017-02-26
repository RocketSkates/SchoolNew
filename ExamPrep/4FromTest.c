#include <stdio.h>
#include <string.h>
#define N 5 

int AlternatelySum(int num) {
	static int x;
	if (num <= 9) return num;
	if (num < 100) {
		return (num % 10) - (num / 10);
	}
	return (num % 10) - ((num % 100)/10) + AlternatelySum(num / 100);
}

void main()
{
	int num = 7762348;
	printf("%d", AlternatelySum(num));

}