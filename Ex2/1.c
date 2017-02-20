#include <stdio.h>
void main()
{
	int grade1, grade2, grade3;
	int sum = grade1 + grade2 + grade3;
	printf("Students’ grades: \n");
	scanf("%d%d%d", &grade1, &grade2, &grade3);
	if (grade1>100 || grade1<0 || grade2>100 || grade2>0 || grade3>100 || grade3>0)
		printf("Invalid Input\n");
	else if ((sum <= 178) && (grade1 == 60 || grade2 == 60 || grade3 == 60))
		printf("Go Home\n");
	else if (sum >= 290)
		printf("Move To Third Year\n");
	else if (sum >= 122 && sum<290)
		printf("Move To Second Year\n");
	else if (sum >= 61 && sum<122)
		printf("Stay in First Year\n");
}