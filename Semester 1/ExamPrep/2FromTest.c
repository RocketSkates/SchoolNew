#include <stdio.h>
#include <string.h>
#define N 5 

void sortWords(char ***words, int size){
	int i,j;
	char temp;
	for (i = 0;i < size;i++) {
		for (j = 0;j < size;j++) {
			if (*(words)[j] != NULL && *(words)[j+1] != NULL) {
				if (strcmp(*(words)[j], *(words)[j+1] > 0)) {
					temp = *(words)[j];
					*(words)[j] = *(words)[j+1];
					*(words)[j+1] = temp;
				}
			}
			
		}
	}

}



void main()
{
	char word1[] = "hello";
	char word2[] = "helz";
	//printf("%d",isPrior(word1, word2));
	//sortWords(&words, 4);

}