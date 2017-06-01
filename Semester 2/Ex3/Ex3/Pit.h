#pragma once
#include <string>
#include "Hazard.h"

class Pit : public Hazard
{
public:
	Pit() :Hazard("Pit is near", "Pit is whistling", "You fell into a Pit") {}
	~Pit();
};