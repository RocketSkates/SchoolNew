#include "AnimalBasedSuperHero.h"

AnimalBasedSuperHero::AnimalBasedSuperHero(const char* name, double age, bool radioactive, const char* animal) {
	_name = strdup(name);
	_age = age;
	_radioactive = radioactive;
	_animal = strdup(animal);
}

AnimalBasedSuperHero::AnimalBasedSuperHero(const AnimalBasedSuperHero& animalBasedSuperHero) {
	_name = strdup(animalBasedSuperHero.getName());
	_age = animalBasedSuperHero.getAge();
	_radioactive = animalBasedSuperHero.getRadioactive();
	_animal = strdup(animalBasedSuperHero.getAnimal());
}
