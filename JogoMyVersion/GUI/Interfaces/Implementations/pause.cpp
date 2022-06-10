#include "../Headers/pause.h"

PauseInterface::PauseInterface(const sf::Vector2i& windowSize, int* gameState) :
	background(), buttons(), state_ref(gameState)
{
	this->background.setSize(static_cast<sf::Vector2f>(windowSize));
	Initialize();
};
PauseInterface::~PauseInterface()
{};

void PauseInterface::Initialize()
{
	this->background.setFillColor(sf::Color(18, 18, 18, 79));
	this->background.setPosition(0.f, 0.f);


};
void PauseInterface::Execute(const sf::Vector2f& mousePos)
{
	if (this->state_ref != nullptr)
	{
		unsigned int i = 0;

		for (Button btn : this->buttons)
		{
			btn.update(mousePos);
			//if(btn.isPressed())

		}
	}
	else
		std::cerr << "Nao ha referencia para o stado do jogo." << std::endl;
};
void PauseInterface::selfPrint(sf::RenderWindow& window)
{
	
};