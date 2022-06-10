#pragma once

#include "stdafx.h"

namespace traits 
{
	class Printable
	{
	public:
		Printable();
		Printable(const sf::Texture& texture, const bool FacesRight = true);
		Printable(const std::string fileName, const bool FacesRight = true);
		~Printable();

		sf::Texture& GetTexture() { return this->texture; };
		const sf::Texture& GetConstTexture() { return this->texture; };
		void SetTexture(const sf::Texture& texture) { this->texture = texture; };
		void SetTexture(const std::string& fileName) { this->texture.loadFromFile(fileName); };

		void InvertTextureOrientation();

		virtual void SelfPrint(sf::RenderWindow& window) = 0;

	public:
		sf::Texture texture;
		bool faceRight;
	};
}