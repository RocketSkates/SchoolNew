/* Sigal Gurman */
/* 204734669 */
/* 27.11.2016 */
/* ******* */
/* Program to calculate the roots of a quadratic equation. */
/* ******* */


#include <stdio.h>
#include <math.h>

void Calculate(int inRoot, int a, int b){
	float root1, root2;
	/* If the value in the root is 0- there is only one root to calculate.*/
	root1 = ((b*(-1)) + sqrt(inRoot)) / (2 * a);
	if(inRoot==0){
			printf("Only one root : %.2lf\n",root1);
	}
	/* Calculate and print the second root (if exists). */
	if(inRoot>0){
		root2 = ((b*(-1)) - sqrt(inRoot)) / (2 * a);
		if (root1 > root2) {
			printf("root1: %.2lf\n", root1);
			printf("root2: %.2lf\n", root2);
		}
		else {
			printf("root1: %.2lf\n", root2);
			printf("root2: %.2lf\n", root1);
		}
		
	}
}

void main()
{
	int a, b, c;
	float inRoot;
	printf("Input a : \n");
	scanf("%i", &a);
	printf("Input b : \n");
	scanf("%i", &b);
	printf("Input c : \n");
	scanf("%i", &c);
	/* Calculate the value to be inside the root */
	inRoot=pow(b,2)-4*a*c;
	
	/* Check the value in the root. */
	if(inRoot<0){
		printf("Equation doesn’t have a real root\n");
		exit(0);
	}
	if(inRoot>=0){
		Calculate(inRoot, a, b);
	}	

}