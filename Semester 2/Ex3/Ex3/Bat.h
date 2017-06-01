#pragma once
#include <string>
#include "Hazard.h"

class Bat : public Hazard
{
public:
	Bat() :Hazard("Bat is near", "Bat is laughing", "A Bat will move you") {}
	~Bat();
};