#pragma once

#include "stdafx.h"

class Button
{
public:
	Button(const sf::View& view, const sf::Vector2f _position, const sf::Font& _font, const std::string _text_data, const unsigned _character_size);
	~Button();

	const bool isPressed() const;
	const std::string GetText() { return this->text.getString(); };

	void update(const sf::Vector2f& mousePos);
	void SelfPrint(sf::RenderTarget& window);

public:
	enum button_status { BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE };

protected:
	short unsigned button_status;

	sf::RectangleShape body;

	sf::Font font;
	sf::Text text;

	sf::Color textColor_idle, textColor_hover, textColor_active;

	sf::Color bodyColor_idle, bodyColor_hover, bodyColor_active;
};