#pragma once

#include <iostream>
#include "Monomial.h"

#define MAX_Monoms 10

class Polynomial
{
	Monomial* poly[MAX_Monoms];
	int numMonoms;
public:
	Polynomial();
	~Polynomial();
	Polynomial(const Polynomial & poly1);
	int GetNum() const { return numMonoms; }
	friend std::ostream& operator << (std::ostream& out, const Polynomial& p);

	Polynomial& operator >> (const char* str);

	int maxExp() const;

	void sort();
	char* getStringRepresentation() const;
};

std::ostream& operator << (std::ostream& out, const Polynomial& p);