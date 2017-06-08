#ifndef SUPERHERO__H_
#define SUPERHERO__H_
#include <iostream>
#include <fstream>
#include <string.h>
#include <typeinfo>

using namespace std;

class SuperHero
{
public:
	SuperHero();
	SuperHero(const char* name, double age, bool radioactive=false);
	SuperHero(const SuperHero& superHero);
	virtual ~SuperHero();

	const char* getName() const { return _name; }
	double getAge() const { return _age; }
	bool getRadioactive() const { return _radioactive; }
	void setName(const char* name);
	void setAge(double age) { _age = age; }
	void setRadioactive(bool radioactive) { _radioactive = radioactive; }


	virtual void load(ifstream& in_file);
	virtual void save(ofstream& out_file) const;


protected:
	char* _name;
	double _age;
	bool _radioactive;

};

#endif