#pragma once

#include "stdafx.h"
#include "instance.h"
#include "../Manegers/Headers/drawble.h"
#include "../Manegers/Headers/WithPhysics.h"
using namespace drawable;
using namespace WithPhysics;

class Entity : public Instance, public Movable {
public:
	Entity();
	Entity(sf::Texture& texture, bool facingRight = true);
	Entity(sf::Texture& texture, sf::RectangleShape& Body, bool facingRight = true);
	~Entity();

	// SETS/ GETS
	sf::RectangleShape& GetRectShape() { return this->body; };
	const sf::RectangleShape& GetConstRectShape() { return this->body; };
	void SetEntityBody(const sf::RectangleShape& newPosition) { this->body = newPosition; };
	
	// FUNCTIONS
	virtual void Execute() = 0;
	virtual void SelfPrintAll() = 0;
	virtual void SelfPrintSelected() = 0;

		//Formato de print
	//void SelfPrintAll(sf::RenderWindow& window, float timeDiff);
	//void SelfPrintSelected(sf::RenderWindow& window, unsigned int animationKey, float timeDiff);

protected:
	sf::RectangleShape body;
};