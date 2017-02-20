/* Sigal Gurman */
/* 204734669 */
/* 30.11.2016 */
/* ******* */
/*  */
/* ******* */

#include <stdio.h>

void main()
{
	int num, flag = 1, sum=0, endsum=0, temp=0;

	/* Get number from user */
	printf("Please enter a number: \n");
	scanf("%d", &num);
	/* Check if valid input */
	if (num < 0) {
		printf("Invalid input. \n");
		exit(0);
	}
	while (num > 9) {
		temp=num;
		num=0;
		while (temp > 9) {
			endsum = endsum + (temp % 10);
			temp = temp / 10;
		}
	}
	
	printf("%d\n", endsum);
}