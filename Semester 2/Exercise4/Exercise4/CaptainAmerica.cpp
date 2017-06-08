#include "CaptainAmerica.h"

CaptainAmerica::CaptainAmerica(const char* name, double age, bool radioactive, const char* profession, int yearsExperience, double ageIncludingFreezing) {
	setName(name);
	setAge(age);
	setRadioactive(radioactive);
	setProfession(profession);
	setYearsExperience(yearsExperience);
	setAgeIncludingFreezing(ageIncludingFreezing);
}

CaptainAmerica::CaptainAmerica(const char* profession, int yearsExperience, double ageIncludingFreezing):ProfessionBasedSuperHero() {
	setProfession(profession);
	setYearsExperience(yearsExperience);
	setAgeIncludingFreezing(ageIncludingFreezing);
}

CaptainAmerica::CaptainAmerica(double ageIncludingFreezing) :CaptainAmerica() {
	setAgeIncludingFreezing(ageIncludingFreezing);
}

CaptainAmerica::CaptainAmerica(const CaptainAmerica& captainAmerica):ProfessionBasedSuperHero(captainAmerica.getName(),captainAmerica.getAge(),captainAmerica.getRadioactive(),captainAmerica.getProfession(),captainAmerica.getYearsExperience()) {
	setAgeIncludingFreezing(captainAmerica.getAgeIncludingFreezing());
}

void CaptainAmerica::setAgeIncludingFreezing(double ageIncludingFreezing) {
	if (ageIncludingFreezing > _age) _ageIncludingFreezing = ageIncludingFreezing;
}