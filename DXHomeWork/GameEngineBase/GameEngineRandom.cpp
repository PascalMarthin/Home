﻿#include "PreCompile.h"
#include "GameEngineRandom.h"
#include <chrono>

GameEngineRandom GameEngineRandom::MainRandom;

GameEngineRandom::GameEngineRandom()
	: mt_(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()))
{

}

GameEngineRandom::~GameEngineRandom() 
{
}

