#pragma once

#include "ente.h"
#include "../Manegers/Headers/traits.h" 
using namespace traits;

namespace entities
{
	// Estrutura base para uma entidades
	class Entity : public Ente, public Collidable, public Printable
	{
	public:
		Entity();
		Entity(const sf::Texture& _texture, const sf::RectangleShape& _body, const float _weight_ceffic = 1.0f);
		Entity(const std::string _fileName, const sf::RectangleShape& _body, const float _weight_ceffic = 1.0f);
		~Entity();

		sf::RectangleShape& GetBody() { return this->body; };
		const sf::RectangleShape& GetConstBody() { return this->body; };
		void SetBody(const sf::RectangleShape& _body) { this->body = _body; };

		// FUNCTIONS
		virtual void Initialize() = 0;
		virtual void Execute() = 0;
		virtual void SelfPrint(sf::RenderWindow& window) = 0;

	#ifdef _DEBUG
		void debugExecute();
		void stringInfoUptade();
		void PrintInfo(sf::RenderWindow& window);
	#endif 

	protected:
		sf::RectangleShape body;

	#ifdef _DEBUG
		std::string value_as_string;
		sf::Font font;
		sf::Text info_pos;
	#endif 
	};
}