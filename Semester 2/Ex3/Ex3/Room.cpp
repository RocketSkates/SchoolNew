#include "Room.h"
#include "Hazard.h"
#include <string>

using namespace std;


Room::Room(int tunnel1, int tunnel2, int tunnel3) {
	_tunnels[0] = tunnel1;
	_tunnels[1] = tunnel2;
	_tunnels[2] = tunnel3;
	_hazard = nullptr;
}

int Room::getTunnel1() const {
	int one = this->_tunnels[0];
	int two = this->_tunnels[1];
	int three = this->_tunnels[2];
	if (one < two && one < three) return one;
	else if (two < one && two < three) return two;
	else if (three < one &&three < two) return three;
	return 0;
}

int Room::getTunnel2() const {
	int one = this->_tunnels[0];
	int two = this->_tunnels[1];
	int three = this->_tunnels[2];
	if ((one > two && one < three) || (one > three && one < two)) return one;
	if ((two > one&&two < three) || (two > three&&two < one)) return two;
	if ((three<one &&three>two) || (three > one&&three < two)) return three;
	return 0;
}

int Room::getTunnel3() const {
	int one = this->_tunnels[0];
	int two = this->_tunnels[1];
	int three = this->_tunnels[2];
	if (one > two && one > three) return one;
	else if (two > one && two > three) return two;
	else if (three > one &&three > two) return three;
	return 0;
}

std::string Room::roomHazard() const {
	if (_hazard != nullptr)
		return _hazard->getHazardMessage();
	return std::string("");
}

bool Room::roomIsEmpty() const {
	if (_hazard != nullptr)
		return true;
	return false;
}

bool Room::attackInRoom(std::string& message) const { // TODO - check for blocked room!!!
	string s = this->roomHazard();
	if (s == "Bat is near") {
		message = "Bat is laughing";
		return 1;
	}
	else if (s == "Pit is near") {
		message = "Pit is whistling";
		return 1;
	}
	else if (s == "MushMush is near") {
		message = "You got MushMush";
		return 1;
	}
	else {
		message = "";
		return 0;
	}
	return 0;
}

bool Room::clashInRoom(std::string& msg) const {
	string s = this->roomHazard();
	if (s == "") {
		msg = "";
		return 1;
	}
	else if (s == "MushMush is near") {
		msg = "MushMush got you";
		return false;
	}
	else if (s == "Pit is near") {
		msg = "You fell into a Pit";
		return false;
	}
	else if (s == "Bat is near") { // TODO - move player to other room
		msg = "A Bat will move you";
		return false;
	}

}

bool Room::isMushMushHere() const {
	string s = this->roomHazard();
	if (s == "MushMush is near") return true;
	return false;
}

void Room::setHazard(const Hazard* haz) {
	_hazard = haz;
}

Room::~Room() {
	_tunnels[0] = 0;
	_tunnels[1] = 0;
	_tunnels[2] = 0;
	delete(_hazard);
}