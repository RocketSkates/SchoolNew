#pragma once

#include <string>
using namespace std;
class Room;
class Cave
{
	Room* _rooms[20];
	int playerIdx;
	bool GameOver;

public:
    Cave(const int* const sealedRooms, int size);
    ~Cave();
    const Room* getRoomAtIndex(int index) const;
    void plotHazard(int idx, const std::string& eventName);
	void plotPlayerIdx(int idx);
    int findMushMush(void) const;
	void movePlayer(int idx);
    std::string playerAttack(int idx);
    std::string playerClash(int idx);
	bool gameOver() const;
    
    void hazardNearPlayer(std::string* hazards) const;
};
