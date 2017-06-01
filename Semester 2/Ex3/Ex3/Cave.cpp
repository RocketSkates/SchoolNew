
#include "Cave.h"
#include "SealedRoom.h"
#include "RegularRoom.h"
#include "Bat.h"
#include "Pit.h"
#include "MushMush.h"
#include "Hazard.h"
#include <string>

using namespace std;

Cave::Cave(const int* const sealedRooms, int size) {
	int tunnels[3];
	GameOver = false;
	int t1, t2, t3;
	for (int i = 0; i < 20; i++) { 
		Room* tmp;
		// Don't hate me, I couldn't find a better way to do this.
		if (i == 0) { tunnels[0] = 2; tunnels[1] = 18;tunnels[2] = 19; } // init the tunnels for each room, depends on which room we are looking at right now.
		else if (i == 1) { tunnels[0] = 5; tunnels[1] = 17;tunnels[2] = 18; }
		else if (i == 2) { tunnels[0] = 0; tunnels[1] = 4;tunnels[2] = 17; }
		else if (i == 3) { tunnels[0] = 7; tunnels[1] = 16;tunnels[2] = 19; }
		else if (i == 4) { tunnels[0] = 2; tunnels[1] = 6;tunnels[2] = 15; }
		else if (i == 5) { tunnels[0] = 1; tunnels[1] = 9;tunnels[2] = 14; }
		else if (i == 6) { tunnels[0] = 4; tunnels[1] = 8;tunnels[2] = 13; }
		else if (i == 7) { tunnels[0] = 3; tunnels[1] = 11;tunnels[2] = 12; }
		else if (i == 8) { tunnels[0] = 6; tunnels[1] = 10;tunnels[2] = 11; }
		else if (i == 9) { tunnels[0] = 5; tunnels[1] = 10;tunnels[2] = 13; }
		else if (i == 10) { tunnels[0] = 8; tunnels[1] = 9;tunnels[2] = 12; }
		else if (i == 11) { tunnels[0] = 7; tunnels[1] = 8;tunnels[2] = 15; }
		else if (i == 12) { tunnels[0] = 7; tunnels[1] = 10;tunnels[2] = 14; }
		else if (i == 13) { tunnels[0] = 6; tunnels[1] = 9;tunnels[2] = 17; }
		else if (i == 14) { tunnels[0] = 5; tunnels[1] = 12;tunnels[2] = 16; }
		else if (i == 15) { tunnels[0] = 4; tunnels[1] = 11;tunnels[2] = 19; }
		else if (i == 16) { tunnels[0] = 3; tunnels[1] = 14;tunnels[2] = 18; }
		else if (i == 17) { tunnels[0] = 1; tunnels[1] = 2;tunnels[2] = 13; }
		else if (i == 18) { tunnels[0] = 0; tunnels[1] = 1;tunnels[2] = 16; }
		else if (i == 19) { tunnels[0] = 0; tunnels[1] = 3;tunnels[2] = 15; }
		while (sealedRooms) {
			for (int j = 0; j < size; j++) {
				if (sealedRooms[j] == i) {
					t1 = tunnels[0];
					t2 = tunnels[1];
					t3 = tunnels[2];
					tmp = new SealedRoom(t1, t2, t3);
					_rooms[i] = tmp;
					break;
				}
			}
		}
		t1 = tunnels[0];
		t2 = tunnels[1];
		t3 = tunnels[2];
		tmp = new RegularRoom(t1, t2, t3);
		_rooms[i] = tmp;
	}
}

const Room * Cave::getRoomAtIndex(int index) const
{
	if (index >= 0 && index <= 19)
	{
		return _rooms[index];
	}
	else
		throw "Invalid Index Exception";
}

void Cave::plotHazard(int idx, const std::string & eventName)
{
	Hazard* hazard;

	if (idx >= 0 && idx <= 19 && _rooms[idx]->getHazard() == nullptr)
	{
		if (eventName.compare("MushMush") == 0)
			hazard = new MushMush();
		else if (eventName.compare("Pit") == 0)
			hazard = new Pit();
		else if (eventName.compare("Bat") == 0)
			hazard = new Bat();
		else
			throw "Invalid Hazard Exception";

		if (hazard != nullptr)
			_rooms[idx]->setHazard(hazard);
	}
	else
	{
		throw "Invalid Index Exception";
	}
}

void Cave::plotPlayerIdx(int idx) {
	if ((idx < 0 || idx>19) || (!this->_rooms[idx]->roomIsEmpty())) throw "Invalid Index Exception";
	playerIdx = idx;
}

int Cave::findMushMush() const {
	for (int i = 0; i < 20; i++){
		if (_rooms[i]->isMushMushHere()) return 1;
	}
	throw "MushMush Not Found Exception";
}

void Cave::movePlayer(int idx) {
	if (idx < 0 || idx>19) throw "Invalid Index Exception";
	if ((_rooms[playerIdx]->getTunnel1() == idx) || (_rooms[playerIdx]->getTunnel2() == idx) || (_rooms[playerIdx]->getTunnel3() == idx))
		playerIdx = idx;
	else throw "Invalid Index Exception";
}

std::string Cave::playerAttack(int idx)
{
	bool accessible;
	if ((_rooms[playerIdx]->getTunnel1() == idx) || (_rooms[playerIdx]->getTunnel2() == idx) || (_rooms[playerIdx]->getTunnel3() == idx))
		accessible = true;
	if (playerIdx != -1 && accessible)
	{
		std::string message;
		bool res = _rooms[idx]->attackInRoom(message);

		if (res) GameOver = true;
		else
		{
			try
			{
				int IdxToMoveMushMush = -1;
				int idx = findMushMush();
				int tunnel = -1;
				if ((tunnel = _rooms[playerIdx]->getTunnel1()) && _rooms[tunnel]->getHazard() != nullptr)
				{
					if ((tunnel = _rooms[playerIdx]->getTunnel2()) && _rooms[tunnel]->getHazard() != nullptr){
						if ((tunnel = _rooms[playerIdx]->getTunnel2()) && _rooms[tunnel]->getHazard() == nullptr) IdxToMoveMushMush = tunnel;
					}
					else IdxToMoveMushMush = tunnel;
				}
				else IdxToMoveMushMush = tunnel;
				if (IdxToMoveMushMush != -1){
					const Hazard* hazard = _rooms[idx]->getHazard();
					_rooms[tunnel]->setHazard(hazard);
					_rooms[idx]->setHazard(nullptr);
				}
			}
			catch (const std::exception& ex)
			{
				throw ex;
			}
		}

		return message;
	}
	else
		throw "Invalid Index Exception";

	return std::string("");
}

std::string Cave::playerClash(int idx)
{
	if (idx >= 0 && idx <= 19)
	{
		const Hazard* hazard = _rooms[playerIdx]->getHazard();
		std::string message = std::string("");

		if (hazard != nullptr)
		{
			const Bat* b = dynamic_cast<const Bat*>(hazard);
			if (b)
			{
				_rooms[idx]->setHazard(nullptr);
				plotPlayerIdx(idx);


				if (!_rooms[playerIdx]->clashInRoom(message))
				{

					if (idx + 1 >= 0 && idx + 1 <= 19)
						return playerClash(idx + 1);
				}
				else GameOver = true;
			}
		}
		else
		{
			GameOver = true;
			return std::string("");
		}

		return message;
	}
	else
		throw "Invalid Index Exception";
}

bool Cave::gameOver() const
{
	return GameOver;
}

void Cave::hazardNearPlayer(std::string * hazards) const
{
	if (playerIdx != -1)
	{
		int t1, t2, t3;
		t1 = _rooms[playerIdx]->getTunnel1();
		t2 = _rooms[playerIdx]->getTunnel2();
		t3 = _rooms[playerIdx]->getTunnel3();

		hazards[0] = _rooms[t1]->roomHazard();
		hazards[1] = _rooms[t2]->roomHazard();
		hazards[2] = _rooms[t3]->roomHazard();
	}
}

Cave::~Cave() { // TODO - finish
	for (int i = 0; i < 20; i++){
		delete(_rooms[i]);
	}
}