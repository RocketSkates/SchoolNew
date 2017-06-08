#include "ProfessionBasedSuperHero.h"

ProfessionBasedSuperHero::ProfessionBasedSuperHero(const char* name, double age, bool radioactive, const char* profession, int yearsExperience) : SuperHero(name,age,radioactive) {
	setProfession(profession);
	setYearsExperience(yearsExperience);
}

ProfessionBasedSuperHero::ProfessionBasedSuperHero(const char* profession, int yearsExperience):SuperHero() {
	setProfession(profession);
	setYearsExperience(yearsExperience);
}

ProfessionBasedSuperHero::ProfessionBasedSuperHero(const ProfessionBasedSuperHero& professionBasedSuperHero) : SuperHero(professionBasedSuperHero.getName(), professionBasedSuperHero.getAge(), professionBasedSuperHero.getRadioactive()) {
	setProfession(professionBasedSuperHero.getProfession());
	setYearsExperience(professionBasedSuperHero.getYearsExperience());
}

void ProfessionBasedSuperHero::setYearsExperience(int yearsExperience) {
	if (yearsExperience >= 0) _yearsExperience = yearsExperience;
}

void ProfessionBasedSuperHero::setProfession(const char* profession) {
	if (profession != nullptr && _profession != nullptr && profession != _profession) _profession = strdup(profession);
}