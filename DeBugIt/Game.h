#pragma once
//#include "GameStateManager.h"

enum class GameStateId
{
	TitleScreen,
	Playing,
	PauseMenu,
	WinMenu,
	LoseMenu,
	TowerMenu,
	Count
};

class Game 
{
public:
	Game() : m_currentState (GameStateId::Playing) {}
	void run();


private:
	GameStateId m_currentState;
};