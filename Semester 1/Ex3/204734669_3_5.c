/* Sigal Gurman */
/* 204734669 */
/* 9.12.2016 */
/* *********** */
/* The program receives two numbers and prints if the first number contains the second and in which index. */
/* *********** */


#include <stdio.h>

float Contains(num1, num2) {
	float flag = 0, pos = 0, temp2 = 0;
	int tempnum = num2, digits = 0, temp1 = 0;
	temp1 = num2;
	/* Calculate the number of digits in num2 */
	while (temp1 > 0) {
		digits++;
		temp1 = temp1 / 10;
	}
	temp1 = 0;
	while (num1 > 0) {
		temp1 = num1 % 10;
		temp2 = tempnum % 10;
		if (temp1 == temp2) {
			flag++;
			pos++;
			num1 = num1 / 10;
			tempnum = tempnum / 10;
			if (flag == digits) {
				return (pos-1);
			}
		}
		else {
			flag = 0;
			pos++;
			num1 = num1 / 10;
			tempnum = num2;
		}

	}

	return -1;

}

void main()
{
	int num1, num2;
	char letter,s=' ';
	/* Get two numbers from user */
	printf("Please enter number 1:\n");
	scanf("%i", &num1);
	printf("Please enter number 2:\n");
	scanf("%i", &num2);
	printf("%f\n", Contains(num1, num2));
}