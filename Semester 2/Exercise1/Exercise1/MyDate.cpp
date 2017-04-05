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
	if (num > 358 || num < 0) return -1;
	else {

	}
}

MyDate::~MyDate()
{
}
