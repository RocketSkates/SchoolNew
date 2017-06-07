#include "SuperHero.h"

SuperHero::SuperHero() {
	_name = nullptr;
	_age = 0;
	_radioactive = 0;
}

SuperHero::SuperHero(const char* name, double age, bool radioactive = false) {
	_name = strdup(name);
	if (age >= 15 || age <= 40) _age = age;
	else _age = 0;
	_radioactive = radioactive;
}

SuperHero::SuperHero(const SuperHero& superHero) {
	_name = superHero._name;
	_age = superHero._age;
	_radioactive = superHero._radioactive;
}

