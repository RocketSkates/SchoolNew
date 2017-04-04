#include <stdio.h>
#include <string.h>
#define SIZE 21

typedef struct Movie {
	char * _movieName;
	int _seasonNum;
	int _chapterNum;
	int _lenInMinutes;
}movie;

typedef struct Country {
	char * _countryName;
	movie ** _moviesSet;
	int _moviesSetLen;
}country;

typedef struct Member {
	char _memberName[SIZE];
	int _memberId;
	country * _memberCountry;
}member;


movie* searchMovieByCountry(country* c, char* moviesName) {
	int i=0;

	for (i = 0;i < c->_moviesSetLen;i++) {
		if (strcmp(c->_moviesSet[i]->_movieName, moviesName) == 0) return c->_moviesSet[i];
	}
	return NULL;
}

int addMovieToCountry(country* country, movie* movie) {

	if (searchMovieByCountry(country, movie) == NULL) {
		country->_moviesSetLen++;
		country->_moviesSet = (movie**)realloc(movie*, ++(c->_moviesSetLen));
		if (country->_moviesSet == NULL) return 0;
	}
	else return 1;
}

movie** MoviesNotAllowedToCountry(country* country, movie**moviesPtr, int arrMoviesSize, int* arrSize) {
	movie ** NotAllowed[] = (movie*)malloc(arrMoviesSize);
	int i;
	(*arrSize) = 0;

	for (i = 0;i < arrMoviesSize;i++) {
		if (searchMovieByCountry(country, moviesPtr[i]->_movieName) == NULL) {
			NotAllowed[*arrSize] = moviesPtr[i];
			(*arrSize)++;
		}
	}
	return NotAllowed;
}

void main()
{

}