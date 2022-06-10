#pragma once

#include "../GUI/Buttons/Headers/button.h"

namespace 
{
	class PauseInterface
	{
	public:
		PauseInterface(const sf::Vector2i& windowSize = sf::Vector2i(1920, 1080), int* gameState = nullptr);
		~PauseInterface();

		void Initialize();
		void Execute(const sf::Vector2f& mousePos);
		void selfPrint(sf::RenderWindow& window);

	private:
		sf::RectangleShape background;
		std::vector<Button> buttons;

		int* state_ref;
	};
}