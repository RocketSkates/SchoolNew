#include "SuperHero.h"

SuperHero::SuperHero() {
	_name = NULL;
	_age = 0;
	_radioactive = 0;
}

SuperHero::SuperHero(const char* name, double age, bool radioactive = false) {
	setName(name);
	setAge(age);
	setRadioactive(radioactive);
}

SuperHero::SuperHero(const SuperHero& superHero) {
	setName(superHero.getName());
	setAge(superHero.getAge());
	setRadioactive(superHero.getRadioactive());
}

void SuperHero::setName(const char* name) {
	if (name != NULL && name != _name && _name != NULL) _name = strdup(name);
}

//________________________________________________________________________________
//__________________________WRITING TO FILES______________________________________
//________________________________________________________________________________

void SuperHero::load(ifstream& in_file) {
	int size;
	in_file.read((char*)&size, sizeof(int));
	if (_name != NULL) delete[] _name;
	_name = new char[size + 1];
	in_file.read(_name, size);
	_name[size] = '\0';

	size = 0;
	in_file.read((char*)&_age, sizeof(_age));
}

void SuperHero::save(ofstream& out_file) const {
	int size;
	if (_name != NULL) size = strlen(_name);
	out_file.write((char*)&size, sizeof(size));
	out_file.write(_name, size);

	out_file.write((char*)&_age, sizeof(_age));
}