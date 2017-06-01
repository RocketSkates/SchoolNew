#pragma once
#include <string>
#include "Hazard.h"

class MushMush : public Hazard
{
public:
	MushMush() :Hazard("MushMush is near", "You got MushMush", "MushMush got you") {}
	~MushMush();
};