#pragma once

#include <iostream>

class Monomial
{
	int coef;
	int expo;
public:
    Monomial(int coeff, int exp = 0);
    Monomial();
	int GetExp() const { return expo; }
	int GetCoeff() const { return coef; }
	void SetCoeff(int n) { coef = n; }
	bool operator += (const Monomial& m);
	Monomial operator * (const Monomial& m);
	Monomial& operator *= (const Monomial& m);
	Monomial& operator = (const Monomial& m);
	Monomial& operator -- ();
    char* stringRepresentation() const;
	friend std::ostream& operator << (std::ostream& out, const Monomial& m);
};

std::ostream& operator << (std::ostream& out, const Monomial& m);