#pragma once
#include "ConsoleObject.h"

// Ό³Έν :
class Player : public ConsoleObject
{
public:
	// constrcuter destructer
	Player(TextScreen* _Screen, const char* _Text);
	~Player();

	// delete Function
	Player(const Player& _Other) = delete;
	Player(Player&& _Other) noexcept = delete;
	Player& operator=(const Player& _Other) = delete;
	Player& operator=(Player&& _Other) noexcept = delete;


	void Update();

protected:

private:
	// Monster* OtherMonster;

};

