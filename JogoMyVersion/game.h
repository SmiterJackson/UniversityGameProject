#pragma once

#include "../Stages/Headers/baseStage.h"

class Game 
{
public:
	Game();
	~Game();

	void Execute();

protected:
	enum state { Menu = 0, Playing, Paused};
	sf::Vector2f mouseToDesktop, mouseToWindow, mouseToView;
	sf::Vector2i mouseToGrid;
};