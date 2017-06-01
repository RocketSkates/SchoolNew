#include "Hazard.h"
#include <string>

Hazard::~Hazard()
{
	delete(_hazardMessage);
	delete(_hazardAttackMessage);
	delete(_hazardClashMessage);
}
