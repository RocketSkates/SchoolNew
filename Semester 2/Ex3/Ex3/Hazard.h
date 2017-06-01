#pragma once
#include <string>
#include <cstring>

class Hazard
{
public:
	Hazard() {};
	Hazard(std::string message, std::string attack, std::string clash)
	{
		_hazardMessage = new std::string(message);
		_hazardAttackMessage = new std::string(attack);
		_hazardClashMessage = new std::string(clash);
	};
	virtual ~Hazard();
	virtual	std::string getHazardMessage() const { return *_hazardMessage; }
	virtual	std::string getHazardAttackMessage() const { return *_hazardAttackMessage; }
	virtual	std::string getHazardClashMessage() const { return *_hazardAttackMessage; }

protected:
	const std::string* _hazardMessage;
	const std::string* _hazardAttackMessage;
	const std::string* _hazardClashMessage;
};