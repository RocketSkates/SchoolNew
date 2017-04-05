#include "stdafx.h"
#include "MyDate.h"


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
	else {
		return -1;
	}
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
	else return -1;
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
	else return -1;
}

int MyDate::setYear(int year) {
	if (year < 2100 && year>1900) {
		m_year = year;
		return 0;
	}
	else return -1;
}

bool MyDate::isBefore(const MyDate& newDate) {
	if (this->m_year < newDate.m_year) return true;
	else if ((this->m_year == newDate.m_year) && (this->m_month < newDate.m_month)) return true;
	else if ((this->m_year == newDate.m_year) && (this->m_month == newDate.m_month) && (this->m_day < newDate.m_day)) return true;
	else return false;
}

int MyDate::delay(int num) {
	int months = 0, days = 0;
	bool passesFeb = false;
	if (num > 358 || num < 0) return -1;
	else {
		months = num / 30;
		days = num % 30;
		if ((this->m_month == 1 && months > 1) || (this->m_month == 2 && months > 0)) {
			passesFeb = true;
			// If the number of days that we add to the current date will cause to pass a month (also for February case)
			if ((this->m_month != 2 && this->m_day + days > 30) || (this->m_month == 2 && this->m_day + days > 28)) {
				int temp = (this->m_day + days) - 30;
				if (passesFeb) this->setDay(temp + 2);
				else this->setDay(temp);
				this->setMonth(this->m_month + months + 1);
			}
			else { // If the number of days to add will not change the month, change regularly.
				this->setMonth(this->m_month + months);
				this->setDay(this->m_month + months);
			}
			// If the number of months to add will cause the date to move to the next year.
			if ((this->m_month + months) > 12) this->setYear(this->m_year + 1);
		}
	}
}

int MyDate::bringForward(int num) {
	int months = 0, days = 0;
	bool passesFeb = false;
	if (num > 358 || num < 0) return -1;


}

