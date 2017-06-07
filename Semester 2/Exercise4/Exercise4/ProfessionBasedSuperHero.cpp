#include "ProfessionBasedSuperHero.h"

ProfessionBasedSuperHero::ProfessionBasedSuperHero(const char* name, double age, bool radioactive, const char* profession, int yearsExperience) {
	_name = strdup(name);
	_age = age;
	_radioactive = radioactive;
	_profession = strdup(profession);
	_yearsExperience = yearsExperience;
}

ProfessionBasedSuperHero::ProfessionBasedSuperHero(const char* profession, int yearsExperience):SuperHero() {
	_profession = strdup(profession);
	_yearsExperience = yearsExperience;
}

ProfessionBasedSuperHero::ProfessionBasedSuperHero(const ProfessionBasedSuperHero& professionBasedSuperHero) {
	_name = strdup(professionBasedSuperHero.getName());
	_age = professionBasedSuperHero.getAge();
	_radioactive = professionBasedSuperHero.getRadioactive();
	_profession = strdup(professionBasedSuperHero.getProfession());
	_yearsExperience = professionBasedSuperHero.getYearsExperience();
}