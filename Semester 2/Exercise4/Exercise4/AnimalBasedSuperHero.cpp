#include "AnimalBasedSuperHero.h"

AnimalBasedSuperHero::AnimalBasedSuperHero(const char* name, double age, bool radioactive, const char* animal) {
	setName(name);
	setAge(age);
	setRadioactive(radioactive);
	setAnimal(animal);
}

AnimalBasedSuperHero::AnimalBasedSuperHero(const AnimalBasedSuperHero& animalBasedSuperHero):SuperHero(animalBasedSuperHero.getName(), animalBasedSuperHero.getAge(), animalBasedSuperHero.getRadioactive()) {
	/*_name = strdup(animalBasedSuperHero.getName());
	_age = animalBasedSuperHero.getAge();
	_radioactive = animalBasedSuperHero.getRadioactive();*/
	setAnimal(animalBasedSuperHero.getAnimal());
}

void AnimalBasedSuperHero::setAnimal(const char* animal) {
	if (animal != nullptr &&_animal != nullptr && animal != _animal) _animal = strdup(animal);
}

//________________________________________________________________________________
//__________________________WRITING TO FILES______________________________________
//________________________________________________________________________________

void AnimalBasedSuperHero::load(ifstream& in_file) {
	SuperHero::load(in_file);
	int size;
	in_file.read((char*)&size, sizeof(int));
	if (_animal != NULL) delete[] _animal;
	_animal = new char[size + 1];
	in_file.read(_animal, size);
	_animal[size] = '\0';
}