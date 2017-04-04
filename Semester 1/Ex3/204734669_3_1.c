/* Sigal Gurman */
/* 204734669 */
/* 30.11.2016 */
/* ******* */
/*  */
/* ******* */

#include <stdio.h>

void main()
{
	int day, month;
	/* Get day and month from user */
	printf("Please enter the day and month: \n");
	scanf("%d", &day);
	scanf("%d", &month);
	/* Check if the entered values are valid as a date */
	switch (month) {
			/* Check if the entered month is one of the months with 31 days. */
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		if (day < 1 || day>31) printf("Invalid Date\n");
		if (day==31 && month==12) printf("1.1\n");
		if(day==31) printf("%d.%d\n",1, month+1);
		else printf("%d.%d\n", day + 1, month);
		exit(0);
		/* Check if the entered month is one of the months with 30 days. */
	case 4: case 6: case 9: case 11:
		if (day < 1 || day > 30) printf("Invalid Date\n");
		if (day == 30) printf("%d.%d\n", 1, month + 1);
		else printf("%d.%d\n", day + 1, month);
		exit(0);
	case 2:
		if (day < 1 || day > 28) printf("Invalid Date\n");
		if (day == 28) printf("%d.%d\n", 1, 3);
		else printf("%d.%d\n", day + 1, 2);
	default:
		printf("Invalid Date\n");
	}
}