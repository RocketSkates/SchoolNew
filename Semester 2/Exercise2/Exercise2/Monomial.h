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
    friend std::ostream& operator << (std::ostream& out, const Monomial& m);
    operator += (const Monomial& m)
    char* stringRepresentation() const;
};

std::ostream& operator << (std::ostream& out, const Monomial& m);