/* Sigal Gurman */
/* 204734669 */
/* 27.11.2016 */
/* ******* */
/* Program to check the type of the entered triangle. */
/* ******* */

#include <stdio.h>

void main()
{
	int side1, side2, side3;
	printf("Input sides : \n");
	scanf("%d,%d,%d",&side1,&side2,&side3);
	
	/* Check if not a triangle */
	if(side1+side2<side3 || side1+side3<side2 || side3+side2<side1) {
		printf("Not a triangle\n");
		exit(0);
	}
	/* Check if triangle is either an isosceles or equilateral */
	if( side1==side2 || side2==side3 || side1==side3) {
		printf("An isosceles triangle\n");
		exit(0);
	}
	if (side1 == side2 && side2 == side3) {
		printf("equilateral triangle\n");
		exit(0);
	}
	/* If it's a triangle but isn't isosceles or equilateral than it's Different sides of a triangle */
	else  {
		printf("Different sides of a triangle\n");
	}
}