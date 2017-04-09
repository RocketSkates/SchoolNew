#pragma once
#include "MyDate.h"
#define SIZE 30

class Calendar
{
	MyDate* _calendar[SIZE];
public:
	Calendar() {};

	int setDate(const MyDate& newDate, int num);
	bool isFree(int num);
	int firstFree();
	int insert(const MyDate& newDate);
	int oldest();
	int datesNum(const MyDate& newDate);
	void deleteAll();
	int deleteDate(int num);
	char* print();
	void sortDates();
	char* strdup(const char* s);

	~Calendar() {};
};

