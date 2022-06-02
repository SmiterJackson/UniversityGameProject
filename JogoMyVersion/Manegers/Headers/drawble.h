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
		BaseDrawable(const sf::Texture& texture, bool FacecRight = true);
		BaseDrawable(const std::string fileName, bool FacecRight = true);
		~BaseDrawable();

		sf::Texture& GetTexture() { return this->texture; };
		const sf::Texture& GetConstTexture() { return this->texture; };
		void SetTexture(const sf::Texture& texture) { this->texture = texture; };
		void SetTexture(const std::string& fileName) { this->texture.loadFromFile(fileName); };

		const bool Get_isLookingRight() { return this->faceRight; };
		void Get_isLookingRight(bool newState) { this->faceRight = newState; };
		void InvertOrientation() { this->faceRight = !this->faceRight; };

		virtual void SelfPrintAll() = 0;
		virtual void SelfPrintSelected() = 0;

	public:
		sf::Texture texture;
		bool faceRight;
	};

	// Classe para definir uma textura, recortes da textura, ou ela como um todo, para imprimilas, e/ou definir animações para os mesmo recortes.
	class Printable : protected BaseDrawable {
	public:
		Printable();
		Printable(const sf::Texture& texture, const bool FacecRight = true);
		Printable(const std::string& fileName, const bool FacecRight = true);
		Printable(const sf::Texture& texture, const std::unordered_map<unsigned int, sf::Sprite>& spriteMap, const std::unordered_map<unsigned int, Animation>& animationMap, bool FacecRight = true);
		Printable(const std::string& fileName, const std::unordered_map<unsigned int, sf::Sprite>& spriteMap, const std::unordered_map<unsigned int, Animation>& animationMap, bool FacecRight = true);
		Printable(const sf::Texture& texture, const std::vector<std::pair<unsigned int, sf::IntRect>>& spriteMap, std::vector<std::pair<unsigned int, AnimationDataType>>& animationMap, bool FacecRight = true);
		Printable(const std::string& fileName, const std::vector<std::pair<unsigned int, sf::IntRect>>& spriteMap, std::vector<std::pair<unsigned int, AnimationDataType>>& animationMap, bool FacecRight = true);
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
		void SetSpritesMap(const std::vector<std::pair<unsigned int, sf::IntRect>>& mapValues);
		void SetAnimationsMap(const std::unordered_map<unsigned int, Animation>& map);
		void SetAnimationsMap(const std::vector<std::pair<unsigned int, Animation>>& mapValues);
		void SetAnimationsMap(const std::vector<std::pair<unsigned int, AnimationDataType>>& mapValues);

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
		void operator+= (const std::vector<std::pair<unsigned int, sf::IntRect>>& extention)
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
		void operator+= (const std::vector<std::pair<unsigned int, AnimationDataType>>& extention)
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

/*
Classe bem próxima da Drawble, o diferencial seria ter intrinsecamente Animações no lugar de sprites,
	  para ter uma ou múltiplas animações derivadas de uma única estrutura
class Animated : protected BaseDrawable {
public:
	Animated();
	Animated(sf::Texture& texture, bool FacecRight = true);
	Animated(std::string& fileName, bool FacecRight = true);
	Animated(sf::Texture& texture, std::unordered_map<unsigned int, Animation>& animationMap, bool FacecRight = true);
	Animated(sf::Texture& texture, std::unordered_map<unsigned int, Animation>::value_type*& animationValuesPair, bool FacecRight = true);
	Animated(sf::Texture& texture, std::pair<unsigned int, AnimationDataType>*& animationConstructorMap, unsigned int Size, bool FacecRight = true);
	Animated(std::string& fileName, std::pair<unsigned int, AnimationDataType>*& animationConstructorMap, unsigned int Size, bool FacecRight = true);
	~Animated();

	// SETS / GETS


	// OPERATORS OVERLOADS


protected:

};



class SingleSpriteDrawble : public Drawable
{
public:
	SingleSpriteDrawble();
	SingleSpriteDrawble(sf::Texture& texture);
	SingleSpriteDrawble(std::string fileName);
	SingleSpriteDrawble(sf::Texture& texture, sf::Sprite& sprite);
	SingleSpriteDrawble(std::string fileName, sf::Sprite& sprite);
	~SingleSpriteDrawble();

	sf::Sprite& GetSprite() { return sprite; };
	const sf::Sprite& GetConstSprite() { return sprite; };
	void SetSprite(sf::Sprite& newSprite) { sprite = newSprite; };

	void SelfPrint(sf::RenderWindow& Window);

protected:
	sf::Sprite sprite;
};

typedef std::unordered_map<int, sf::Sprite> IntToSpriteMap;
typedef std::unordered_map<int, sf::IntRect> IntToSpritesCutsMap;
class MultipleSpriteDrawble : public Drawable
{
public:
	MultipleSpriteDrawble();
	MultipleSpriteDrawble(sf::Texture& Texture, IntToSpriteMap& sprites);
	MultipleSpriteDrawble(std::string FileName, IntToSpriteMap& sprites);
	MultipleSpriteDrawble(sf::Texture& Texture, IntToSpritesCutsMap::value_type* multiPairs);
	MultipleSpriteDrawble(std::string FileName, IntToSpritesCutsMap::value_type* multiPairs);
	MultipleSpriteDrawble(sf::Texture& Texture, IntToSpriteMap::value_type* multiPairs, sf::IntRect* spritesCuts);
	MultipleSpriteDrawble(std::string FileName, IntToSpriteMap::value_type* multiPairs, sf::IntRect* spritesCuts);
	
	~MultipleSpriteDrawble();
	
	IntToSpriteMap& GetSpritesMap() { return sprites; };
	const IntToSpriteMap& GetConstSpritesMap() { return sprites; };
	void SetSpritesMap(IntToSpriteMap& newSprite) { sprites = newSprite; };

	void SelfPrint(sf::RenderWindow& Window);
	void SelfPrint(sf::RenderWindow& Window, int*& spritesKeys);

protected:
	IntToSpriteMap sprites;
};*/