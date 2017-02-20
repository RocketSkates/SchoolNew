/* Sigal Gurman */
/* 204734669 */
/* 27.11.2016 */
/* ******* */
/* Program to calculate what year the student should pass to based on his grades. */
/* ******* */

#include <stdio.h>

void main()
{
	int grade1, grade2, grade3;
	int i=1;
	int sum;
	/* string flag="home"; home= Go home, stay= Stay in first year, move2= Move to second year, move3= Move to third year */
	printf("Students’ grades: \n");
	scanf("%d,%d,%d", &grade1, &grade2, &grade3);
	sum=grade1+grade2+grade3;
	
	/* Check if grades are between 0 and 100 */
	if(grade1<0 || grade1>100 || grade2<0 || grade2>100 || grade3<0 || grade3>100) {
		printf("Invalid Input\n");
		exit(0);
	}
	/* Check if one grade is 100 and the rest are at least 95 (95+95+100=270) */
	else if(sum>=290) {
		printf("Move To Third Year\n");
		exit(0);
	}
	/* check if two grades are at least 60 (but student is not qualified to pass to third year) */
	else if ((grade1 >= 60 && grade2 >= 60) || (grade3 >= 60 && grade2 >= 60) || (grade1 >= 60 && grade3 >= 60)) {
		printf("Move To Second Year\n");
	}
	/* Check if one of the grades is higher than 60 */
	else if ((grade1 >= 60 || grade2 >= 60 || grade3 >= 60) && (sum >= 60)) {
		printf("Stay in First Year\n");
		exit(0);
	}
	else printf("Go home\n");
}