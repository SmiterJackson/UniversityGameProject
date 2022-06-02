#pragma once

#include "stdafx.h"
#include "animation.h"
using namespace std;

namespace drawable
{
	// Classe base para as demais - Contém um texture e funções virtuais.
	class BaseDrawable
	{
	public:
		BaseDrawable();
		BaseDrawable(const sf::Texture& texture, const bool FacesRight = true);
		BaseDrawable(const std::string fileName, const bool FacesRight = true);
		~BaseDrawable();

		sf::Texture& GetTexture() { return this->texture; };
		const sf::Texture& GetConstTexture() { return this->texture; };
		void SetTexture(const sf::Texture& texture) { this->texture = texture; };
		void SetTexture(const std::string& fileName) { this->texture.loadFromFile(fileName); };

		const bool Get_isLookingRight() { return this->faceRight; };
		void Get_isLookingRight(const bool newState) { this->faceRight = newState; };
		void InvertOrientation() { this->faceRight = !this->faceRight; };

		virtual void SelfPrintAll() = 0;
		virtual void SelfPrintSelected() = 0;

	public:
		sf::Texture texture;
		bool faceRight;
	};

	typedef const std::vector<std::pair<unsigned int, sf::IntRect>> VecOfPair_key_cutOfSprite;
	typedef const std::vector<std::pair<unsigned int, AnimationDataType>> VecOfPair_key_AnimationDataType;
	// Classe para definir uma textura, recortes da textura, ou ela como um todo, para imprimilas, e/ou definir animações para os mesmo recortes.
	class Printable : protected BaseDrawable {
	public:
		Printable();
		Printable(const sf::Texture& texture, const bool FacesRight = true);
		Printable(const std::string& fileName, const bool FacesRight = true);
		Printable(const sf::Texture& texture, VecOfPair_key_cutOfSprite& spriteMap, VecOfPair_key_AnimationDataType& animationMap, const bool FacesRight = true);
		Printable(const std::string& fileName, VecOfPair_key_cutOfSprite& spriteMap, VecOfPair_key_AnimationDataType& animationMap, const bool FacesRight = true);
		Printable(const sf::Texture& texture, const std::unordered_map<unsigned int, sf::Sprite>& spriteMap, const std::unordered_map<unsigned int, Animation>& animationMap, const bool FacesRight = true);
		Printable(const std::string& fileName, const std::unordered_map<unsigned int, sf::Sprite>& spriteMap, const std::unordered_map<unsigned int, Animation>& animationMap, const bool FacesRight = true);
		~Printable();

		// FUNCTIONS
		virtual void SelfPrintAll() = 0;
		virtual void SelfPrintSelected() = 0;

		// SETS / GETS
		std::unordered_map<unsigned int, sf::Sprite>& GetSpritesMap();
		const std::unordered_map<unsigned int, sf::Sprite>& GetConstSpritesMap();

		std::unordered_map<unsigned int, Animation>& GetAnimationsMap();
		const std::unordered_map<unsigned int, Animation>& GetConsAnimationstMap();
		
		// Os sets aceitam os prórpios tipos de estrutura já preenchidos bem como um vector com os valores do tipo base
		void SetSpritesMap(const std::unordered_map<unsigned int, sf::Sprite>& map);
		void SetSpritesMap(const VecOfPair_key_cutOfSprite& mapValues);

		void SetAnimationsMap(const std::unordered_map<unsigned int, Animation>& map);
		void SetAnimationsMap(const std::vector<std::pair<unsigned int, Animation>>& mapValues);
		void SetAnimationsMap(const VecOfPair_key_AnimationDataType& mapValues);

		// OPERATORS OVERLOADS
		void operator+ (const std::pair<unsigned int, sf::Sprite>& newItem)
		{
			intToSprite_map.insert(newItem);
		};
		void operator+= (const std::unordered_map<unsigned int, sf::Sprite>& extention)
		{
			std::unordered_map<unsigned int, sf::Sprite>::const_iterator c_it;
			for (c_it = extention.cbegin(); c_it != extention.cend(); ++c_it)
				intToSprite_map.insert(*c_it);
		};
		void operator+= (const VecOfPair_key_cutOfSprite& extention)
		{
			for (unsigned int i = 0; i < extention.size(); ++i)
				intToSprite_map[extention[i].first] = sf::Sprite(this->texture, extention[i].second);
		};

		void operator+ (const std::pair<unsigned int, Animation>& newItem)
		{
			intToAnimation_map.insert(newItem);
		};
		void operator+= (const std::unordered_map<unsigned int, Animation>& extention)
		{
			std::unordered_map<unsigned int, Animation>::const_iterator c_it;
			for (c_it = extention.cbegin(); c_it != extention.cend(); ++c_it)
				intToAnimation_map.insert(*c_it);
		};
		void operator+= (const VecOfPair_key_AnimationDataType& extention)
		{
			for (unsigned int i = 0; i < extention.size(); ++i)
				intToAnimation_map[extention[i].first] = Animation(extention[i].second);
		};

	protected:
		std::unordered_map<unsigned int, sf::Sprite> intToSprite_map;
		std::unordered_map<unsigned int, Animation> intToAnimation_map;
		unsigned int lastUsedAnimation;
	};
}