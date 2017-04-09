#pragma once
#include <iostream>


using namespace std;

class MyDate
{
	int m_day;
	int m_month;
	int m_year;

public:
	MyDate();
	MyDate(int day, int month, int year);

	void init();
	int set(int day, int month, int year);
	int setDay(int day);
	int setMonth(int month);
	int setYear(int year);
	int getDay();
	int getMonth();
	int getYear();
	bool isBefore(const MyDate& newDate);
	int delay(int num);
	int bringForward(int num);
	char* print();
	char* strdup(const char* s);

	//~MyDate() {};
};

