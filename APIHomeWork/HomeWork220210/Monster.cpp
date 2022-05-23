#include "Monster.h"

Monster::Monster() 
	: ConsoleObject(nullptr, nullptr, {0,0})
{

}

Monster::Monster(TextScreen* _Screen, const char* _Text, const ConsoleVector& _Vector)
	: ConsoleObject(_Screen, _Text, _Vector)
{
}

Monster::~Monster() 
{
}


void Monster::Update()
{
}
