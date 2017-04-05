#pragma once
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
	bool isBefore(const MyDate& newDate);
	int delay(int num);
	int bringForward(int num);
	char* print();


	//~MyDate() {};
};

