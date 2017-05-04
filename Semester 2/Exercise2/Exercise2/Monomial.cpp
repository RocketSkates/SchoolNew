#include "Monomial.h"

#include <string>
#include <stdlib.h>
#include <sstream>
#include <cstring>

namespace patch
{
	template < typename T > std::string to_string(const T& n)
	{
		std::ostringstream stm;
		stm << n;
		return stm.str();
	}
}


Monomial::Monomial() {
	coef = 0;
	expo = 0;
}

Monomial::Monomial(int coeff, int exp) {
	coef = coeff;
	expo = exp;
}

bool Monomial::operator += (const Monomial& m) {
	coef = coef + m.GetCoeff();
	return 0;
}

Monomial Monomial::operator * (const Monomial& m) {
	coef = coef*m.GetCoeff();
	expo = expo + m.GetExp();
	return *this;
}

Monomial& Monomial::operator *= (const Monomial& m) {
	coef = coef*m.GetCoeff();
	expo = expo + m.GetExp();
	return *this;
}

Monomial& Monomial::operator == (const Monomial& m) {
	coef = m.GetCoeff();
	expo = m.GetExp();
	return *this;
}

Monomial& Monomial::operator -- () {
	this->coef--;
	return *this;
}

char* Monomial::stringRepresentation() const {
	//if (expo == 0) return coef;
	char* newStr;
	if (expo == 0) {
		strcpy(newStr, patch::to_string(coef).c_str());
	}
	else if (coef == 0) {
		strcpy(newStr, patch::to_string(0).c_str()); //convert 0 to char*
	}
	else if (expo == 1) {
		const char* temp = patch::to_string(coef).c_str();
		char* temp1 = strcpy(temp1, temp); // Workaround for c_str returning const
		strcpy(newStr, strcat(temp1,"x")); 
	}
	else if (coef == 1) {
		const char* temp = patch::to_string(expo).c_str();
		strcpy(newStr, strcat("x^", temp)); 
	}
	else {
		const char* temp = patch::to_string(coef).c_str();
		char* temp1 = strcpy(temp1, temp); // Workaround for c_str returning const
		strcpy(newStr, strcat(temp1, "x^")); 
		temp = patch::to_string(expo).c_str();
		char* temp1 = strcpy(temp1, temp); // Workaround for c_str returning const
		strcpy(newStr, strcat(newStr, temp1));
	}
	return newStr;
}

std::ostream& operator << (std::ostream& out, const Monomial& m) {
	out << m.stringRepresentation();
	return out;
}