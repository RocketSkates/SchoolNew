/* Sigal Gurman */
/* 204734669 */
/* 27.11.2016 */
/* ******* */
/* Program to check if an entered letter is lower or upper. */
/* ******* */


#include <stdio.h>

void main()
{
	char letter;
	printf("Input letter : \n");
	scanf("%c", &letter);
	
	/* Check if character is uppercase */
	if(letter >= 65 && letter <= 90) {
		printf("Upper letter\n");
	}
	/* Check if character is lowercase */
	else if(letter >= 97 && letter <= 122) {
		printf("Lower letter\n");
	}
	/* If the letter is neither lowercase nor uppercase, it's not a letter. */
	else  {
		printf("Not a letter\n");
	}
}