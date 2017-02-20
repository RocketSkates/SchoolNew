/* Sigal Gurman */
/* 204734669 */
/* 30.11.2016 */
/* ******* */
/*  */
/* ******* */

#include <stdio.h>

void main()
{
	int num, flag = 1,i;

	/* Get number from user */
	printf("Please enter a number: \n");
	scanf("%d", &num);
	/* Check if valid input */
	if (num < 0) {
		printf("Invalid input. \n");
		exit(0);
	}
	for (i = 2;i < num;i++) {
		if (num%i == 0) {
			printf("False\n");
			exit(0);
		}
	}
	printf("True\n");

}