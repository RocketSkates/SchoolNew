#include "Monomial.h"


Monomial::Monomial() {
	coef = 0;
	expo = 0;
}

Monomial::Monomial(int coeff, int exp = 0) {
	coef = coeff;
	expo = exp;
}

