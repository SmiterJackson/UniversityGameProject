#pragma once

#include "stdafx.h"

class InputHandler {
public:
	InputHandler();
	~InputHandler();

	virtual void UpdateInput(sf::Event& event) = 0;

protected:
	static const sf::Keyboard keys;
};