#include "stdafx.h"
#include "MyDate.h"
#include <string> 
#include <iostream>
#include <cmath>

using namespace std;

MyDate::MyDate(){
	m_day = 0;
	m_month = 0;
	m_year = 0;
}

MyDate::MyDate(int day, int month, int year) {
	if (month == 2) {
		if (day < 29 && day>0) {
			if (year < 2100 && year>1900) {
				m_day = day;
				m_month = month;
				m_year = year;
			}
		}
	}

	else if (day < 31 && day>0) {
		if (month < 13 && month>0) {
			if (year < 2100 && year>1900) {
				m_day = day;
				m_month = month;
				m_year = year;
			}
		}
	}
	else {
		MyDate();
	}
}

void MyDate::init() {
	m_day = 9;
	m_month = 4;
	m_year = 2017;
}

int MyDate::set(int day, int month, int year) {
	if (month == 2) {
		if (day < 29 && day>0) {
			if (year < 2100 && year>1900) {
				m_day = day;
				m_month = month;
				m_year = year;
				return 0;
			}
		}
	}

	else if (day < 31 && day>0) {
		if (month < 13 && month>0) {
			if (year < 2100 && year>1900) {
				m_day = day;
				m_month = month;
				m_year = year;
				return 0;
			}
		}
	}

	return -1;

}

int MyDate::setDay(int day) {
	if (this->m_month == 2) {
		if (day < 29 && day>0) {
			m_day = day;
			return 0;
		}
	}
	else if (day < 31 && day>0) {
		m_day = day;
		return 0;
	}
	return -1;
}

int MyDate::setMonth(int month) {
	if (month == 2) {
		if (this->m_day < 28) {
			m_month = month;
			return 0;
		}
	}
	else if (month < 13 && month>0) {
		if (this->m_day < 31 && this->m_day>0) {
			m_month = month;
			return 0;
		}
	}
	return -1;
}

int MyDate::setYear(int year) {
	if (year < 2100 && year>1900) {
		m_year = year;
		return 0;
	}
	return -1;
}

int MyDate::getDay() {
	return m_day;
}

int MyDate::getMonth() {
	return m_month;
}

int MyDate::getYear() {
	return m_year;
}

bool MyDate::isBefore(const MyDate& newDate) {
	if (this->m_year < newDate.m_year) return true;
	else if ((this->m_year == newDate.m_year) && (this->m_month < newDate.m_month)) return true;
	else if ((this->m_year == newDate.m_year) && (this->m_month == newDate.m_month) && (this->m_day < newDate.m_day)) return true;
	return false;
}

int MyDate::delay(int num) {
	int months = 0, days = 0;
	bool passesFeb = false;
	if (num > 358 || num < 0) return -1;
	else {
		months = num / 30;
		days = num % 30;
		// Keep a flag for if the delay will pass February
		if ((this->m_month == 1 && months > 1) || (this->m_month == 2 && months >= 0)) passesFeb = true;
		// If the number of days that we add to the current date will cause to pass a month (also for February case)
		if ((this->m_month != 2 && this->m_day + days > 30) || (this->m_month == 2 && this->m_day + days > 28)) {
			int temp = (this->m_day + days) - 30;
			if (passesFeb) this->setDay(temp + 2);
			else this->setDay(temp);
			this->setMonth(this->m_month + months + 1);
		}
		// If the number of months to add will cause the date to move to the next year.
		if ((this->m_month + months) > 12) this->setYear(this->m_year + 1);
		else { // If the number of days to add will not change the month, change regularly.
			this->setMonth(this->m_month + months);
			this->setDay(this->m_day + days);
		}
	}
	return 0;
}

int MyDate::bringForward(int num) {
	int months = 0, days = 0, after = 0;
	bool passesFeb = false;
	if (num > 358 || num < 0) return -1;
	else {
		months = num / 30;
		days = num % 30;
		after = this->m_month - months; 
		if (after < 2) passesFeb = true;
		if (after < 0 || (after ==1 && this->m_day-days <0)) {// This means the month is less than January after we deduct the months and we have to go a year back!
			after = std::abs(after);
			int temp = std::abs(this->m_day - days);
			this->setYear(this->m_year - 1);
			this->setMonth(12 - months);
			if (this->m_month == 2) this->setDay(28 - temp);
			else this->setDay(30 - temp);
			return 0;
		}
		// If the days to deduct will cause to switch a month
		if ((this->m_month != 2 && (30-this->m_day-days<0)) || (this->m_month == 2 && (this->m_day - days<0))) {
			int temp = std::abs(this->m_day - days);
			if (passesFeb) this->setDay(28 - temp);
			else this->setDay(30-temp);
			if (after > 0) this->setMonth(this->m_month - 1);
		}
		else { // If the number of days to add will not change the month, change regularly.
			this->setMonth(this->m_month - months);
			this->setDay(this->m_day - days);
		}
		// 
		if ((this->m_month - months) < 0) this->setYear(this->m_year - 1);
	}
	return 0;

}

//char* MyDate::print() {
//	string str = std::to_string(m_day) + "/" + std::to_string(m_month) + "/" + std::to_string(m_year);
//	char* ch = _strdup(str.c_str());
//	return ch;
//}

/*Return a char array of the current date as string format.*/
char* MyDate::print()
{
	//Build the template and convert to char array.
	string str = std::to_string(m_day) + "/" + std::to_string(m_month) + "/" + std::to_string(m_year);
	char* chr = strdup(str.c_str());

	return chr;
}


char* MyDate::strdup(const char* s)
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