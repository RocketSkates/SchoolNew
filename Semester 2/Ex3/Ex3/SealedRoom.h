#pragma once
#include "Room.h"

class SealedRoom : public Room
{
public:
	SealedRoom(int num1, int num2, int num3) : Room(num1, num2, num3) {};
	~SealedRoom();
};

