#pragma once

#include "stdafx.h"
#include "../Lists/Headers/myList.h"
#include "../Entities/Headers/entity.h"
#include "../Entities/Headers/instance.h"
#include "../Manegers/Headers/inputHandler.h"

class BaseStage : public Instance, public InputHandler, public Printable {
public:
	BaseStage();
	~BaseStage();



	void Execute(sf::Event& event);
	void SelfPrintAll(sf::RenderWindow& window, float timeDiff);
	void SelfPrintSelected(sf::RenderWindow& window, unsigned int animationKey, float timeDiff);

protected:
	sf::RenderWindow& contextWindow;
	MyList<AnimatedEntity> myEntities;
	std::vector<sf::RectangleShape> hitbleBounds;
};
