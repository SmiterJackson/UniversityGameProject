#pragma once

#include "stdafx.h"

class Game 
{
public:
	Game();
	~Game();

	void Execute();

protected:
	enum state { Error = -1, Menu = 0, Playing, Paused};
	int state;
	sf::Vector2f mouseToDesktop, mouseToWindow, mouseToView;
	sf::Vector2i mouseToGrid;
};