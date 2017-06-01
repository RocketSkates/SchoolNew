#pragma once
#include "Room.h"
class RegularRoom :
	public Room
{
public:
	RegularRoom(int num1, int num2, int num3) :Room(num1, num2, num3) {};
	~RegularRoom();
};

