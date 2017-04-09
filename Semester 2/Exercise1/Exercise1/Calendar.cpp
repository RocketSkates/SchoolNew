#include "stdafx.h"
#include "Calendar.h"
#include <string> 
#include <iostream>

#define SIZE 30

using namespace std;

int Calendar::setDate(const MyDate& newDate, int num) {
	if (num < 0 || num>30) return -1;
	_calendar[num - 1]->setDay(newDate.getDay);
	_calendar[num - 1]->setMonth(newDate.getMonth);
	_calendar[num - 1]->setYear(newDate.getYear);
}

bool Calendar::isFree(int num) {
	if ((*_calendar[num - 1]).getDay == 0 && (*_calendar[num - 1]).getMonth == 0 && (*_calendar[num - 1]).getYear == 0) return true;
	else return false;
}

int Calendar::firstFree() {
	for (int i = 0; i < SIZE; i++){
		if (isFree(i)) return i;
	}
	return -1;
}

int Calendar::insert(const MyDate& newDate) {
	int free = firstFree();
	if (!free) return -1;
	setDate(newDate, free);
}

int Calendar::oldest() {
	int num = firstFree();
	int temp;
	if (num == -1) return -1;
	for (int i = 0; i < SIZE-1;i++) {
		if (_calendar[i]->isBefore(*_calendar[i+1])) temp = i;
		else temp = i+1;
	}
	return temp;
}

int Calendar::datesNum(const MyDate& newDate) {
	int num = 0;
	int num1 = firstFree();
	if (num1 == -1) return num;
	for (int i = 0; i < SIZE;i++) {
		if (((*_calendar[i]).getYear == newDate.getYear) && ((*_calendar[i]).getMonth == newDate.getMonth) && ((*_calendar[i]).getDay == newDate.getDay)) num++;
	}
	return num;
}

void Calendar::deleteAll() {
	for (int i = 0; i < SIZE;i++) {
		*_calendar[i] = MyDate();
	}
}

int Calendar::deleteDate(int num) {
	if (num < 1 || num>30) return -1;
	*_calendar[num] = MyDate();
}

char* Calendar::print()
{
	string str = "";
	for (int i = 0; i < SIZE; i++)
	{
		//Check if current is not empty.
		if (((*_calendar[i]).getDay !=0)&&((*_calendar[i]).getMonth != 0)&&((*_calendar[i]).getYear != 0))
		{
			//If not empty - add it to the string result.
			std::string strt(_calendar[i]->print());
			if (str != "")
				str += " ";
			str += strt;
		}
	}
	//Convert to *Char and check if its empty.
	//Return match result.
	char* chr = strdup(str.c_str());
	if (std::strcmp(chr, "") == 0)
	{
		str = "Empty Calendar";
		return strdup(str.c_str());
	}

	return chr;
}

/*StrDup implenentation.*/
char* Calendar::strdup(const char* s)
{
	size_t slen = strlen(s);
	char* result = (char*)malloc(slen + 1);
	if (result == NULL)
	{
		return NULL;
	}

	memcpy(result, s, slen + 1);
	return result;
}