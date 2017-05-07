#include "Polynomial.h"

Polynomial::Polynomial() :numMonoms(0) {
	for (int i = 0; i < MAX_Monoms; i++)
		poly[i] = NULL;
}


Polynomial::~Polynomial() {
	for (int i = 0; i < MAX_Monoms; i++)
		delete poly[i];
}


Polynomial::Polynomial(const Polynomial & poly1) {
	numMonoms = poly1.GetNum();
	for (int i = 0; i < numMonoms; i++)
		poly[i] == poly1[i];
}
