#include "../Headers/button.h"

#define BUTTON_TO_VIEW_PROPORCION 10.0f

Button::Button(const sf::View& view, const sf::Vector2f _position, const sf::Font& _font, const std::string _text_data, const unsigned _character_size) :
	button_status(0), body(sf::Vector2f(view.getSize().x / BUTTON_TO_VIEW_PROPORCION, view.getSize().y / BUTTON_TO_VIEW_PROPORCION)), 
	font(_font), text(), textColor_idle(sf::Color(187, 158, 132)), textColor_hover(sf::Color(240, 120, 16)), textColor_active(sf::Color(250, 40, 0)),
	bodyColor_idle(sf::Color(80, 80, 80)), bodyColor_hover(sf::Color(60, 60, 60)), bodyColor_active(sf::Color(30, 30, 30))
{
	this->button_status = BTN_IDLE;

	this->body.setOrigin(this->body.getSize() / 2.0f);
	this->body.setPosition(_position);
	this->body.setFillColor(bodyColor_idle);

	this->text.setFont(this->font);
	this->text.setString(_text_data);
	this->text.setFillColor(textColor_idle);
	this->text.setCharacterSize(_character_size);
	this->text.setPosition(
		this->body.getPosition().x - this->text.getGlobalBounds().width / 2.f,
		this->body.getPosition().y - this->text.getGlobalBounds().height / 2.f
	);
}
Button::~Button()
{}

const bool Button::isPressed() const
{
	if (this->button_status == BTN_ACTIVE)
		return true;
	return false;
}

void Button::update(const sf::Vector2f& mousePos)
{
	this->button_status = BTN_IDLE;
	
	if (this->body.getGlobalBounds().contains(mousePos))
	{
		this->button_status = BTN_HOVER;

		//active
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->button_status = BTN_ACTIVE;
		}
	}

	switch (this->button_status)
	{
	case BTN_IDLE:
		this->body.setFillColor(this->bodyColor_idle);
		this->text.setFillColor(this->textColor_idle);
		break;

	case BTN_HOVER:
		this->body.setFillColor(this->bodyColor_hover);
		this->text.setFillColor(this->textColor_hover);
		break;

	case BTN_ACTIVE:
		this->body.setFillColor(this->bodyColor_active);
		this->text.setFillColor(this->textColor_active);
		break;

	default:
		this->body.setFillColor(sf::Color::Red);
		this->text.setFillColor(sf::Color::Blue);
		break;

	}
}
void Button::SelfPrint(sf::RenderTarget& window)
{
	window.draw(this->body);
	window.draw(this->text);
}