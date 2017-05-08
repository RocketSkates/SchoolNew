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
		poly[i] = poly1.poly[i];
}

Polynomial& Polynomial::operator= (const Polynomial& p) {
	numMonoms = p.GetNum();
	for (int i = 0; i < numMonoms; i++)
		poly[i] = p.poly[i];
}

Polynomial& Polynomial::operator >> (const char* str) { //TODO
	Polynomial p1;
	char* temp;
}

Polynomial& Polynomial::operator+= (const Polynomial& p) {

	for (int i = 0; i < numMonoms; i++){
		for (int j = 0; j < p.numMonoms; j++){
			if (poly[i]->GetExp() == p.poly[j]->GetExp()) {
				poly[i]->SetCoeff(poly[i]->GetCoeff() + p.poly[j]->GetCoeff());
			}
		}
	}
}

Polynomial& Polynomial::operator+= (const Monomial& m) {
	for (int i = 0; i < numMonoms; i++) {
			if (poly[i]->GetExp == m.GetExp()) {
				poly[i]->SetCoeff(poly[i]->GetCoeff() + m.GetCoeff());
			}
		}
}

Polynomial& Polynomial::operator-= (const Polynomial& p) {
	for (int i = 0; i < numMonoms; i++) {
		for (int j = 0; j < p.numMonoms; j++) {
			if (poly[i]->GetExp() == p.poly[j]->GetExp()) {
				poly[i]->SetCoeff(poly[i]->GetCoeff() - p.poly[j]->GetCoeff());
			}
		}
	}
}

Polynomial& Polynomial::operator-= (const Monomial& m) {
	for (int i = 0; i < numMonoms; i++) {
		if (poly[i]->GetExp == m.GetExp()) {
			poly[i]->SetCoeff(poly[i]->GetCoeff() - m.GetCoeff());
		}
	}
}

