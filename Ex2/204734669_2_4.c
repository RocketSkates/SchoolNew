/* Sigal Gurman */
/* 204734669 */
/* 27.11.2016 */
/* ******* */
/* Program to check if two numbers contain the same digits. */
/* ******* */


#include <stdio.h>

void main()
{
	int num1, num2, i=1, j=1, temp1, temp2, temp3;
	int flag=0;
	
	printf("Input numbers : \n");
	scanf("%d,%d", &num1, &num2);
	temp3 = num2;
	/* Check if the two numbers have the same digits */
	for(i=1;i<3;i++) {
		if(i==1){
			temp1 = num1 % 10;
			num1 /= 10;
		}
		else {
			temp1 = num1;
		}
		
		for(j=1;j<3;j++) {
			/* Split the numbers into a single digit */
			if(j==1){
				temp2 = num2 % 10;
				num2 /= 10;
			}
			else {
				temp2 = num2;
			}
			/* If two numbers are identical, turn flag to true. */
			if(temp1==temp2)
			{
				flag++;
				if (flag == 2) {
					break;
				}
			}
			else{
				flag = 0;
			}
		}
		num2 = temp3;
	}

	if(flag==2) printf ("Same digits\n");
	else printf("Not the same digits\n");

}