#pragma once

#include "stdafx.h"
#include "animation.h"

namespace drawable
{
	// Classe base para as demais - Contém um texture e funções virtuais.
	class BaseDrawable
	{
	public:
		BaseDrawable();
		BaseDrawable(sf::Texture& texture, bool FacecRight = true);
		BaseDrawable(std::string fileName, bool FacecRight = true);
		~BaseDrawable();

		const sf::Texture& GetConstTexture() { return this->texture; };
		sf::Texture& GetTexture() { return this->texture; };
		void SetTexture(sf::Texture& texture) { this->texture = texture; };
		void SetTexture(std::string& fileName) { this->texture.loadFromFile(fileName); };

		const bool Get_isLookingRight() { return this->faceRight; };
		void Get_isLookingRight(bool newState) { this->faceRight = newState; };
		void InvertOrientation() { this->faceRight = !this->faceRight; };

		virtual void SelfPrintAll() {};
		virtual void SelfPrintSelected() {};

	public:
		sf::Texture texture;
		bool faceRight;
	};

	// Classe simples para desenhar com um único ou múltiplos sprites, uma única dada estrutura/textura
	class Drawable : protected BaseDrawable {
	public:
		Drawable();
		Drawable(sf::Texture& texture, bool FacecRight = true);
		Drawable(std::string& fileName, bool FacecRight = true);
		Drawable(sf::Texture& texture, std::unordered_map<unsigned int, sf::Sprite>& spriteMap, bool FacecRight = true);
		Drawable(sf::Texture& texture, std::unordered_map<unsigned int, sf::Sprite>::value_type*& spriteValuesPair, bool FacecRight = true);
		Drawable(sf::Texture& texture, std::pair<unsigned int, sf::IntRect>*& spriteCuts, unsigned int Size, bool FacecRight = true);
		Drawable(std::string& fileName, std::pair<unsigned int, sf::IntRect>*& spriteCuts, unsigned int Size, bool FacecRight = true);
		~Drawable();

		// SETS / GETS
		std::unordered_map<unsigned int, sf::Sprite>& GetMap() { return this->intToSprite_map; };
		const std::unordered_map<unsigned int, sf::Sprite>& GetConstMap() { return this->intToSprite_map; };
		void SetMap(std::unordered_map<unsigned int, sf::Sprite>& map) { intToSprite_map = map; };
		void SetMap(std::pair<unsigned int, sf::IntRect>*& map, unsigned int pairsNum) { for (unsigned int i = 0; i < pairsNum; i++)
																							intToSprite_map[map->first] = sf::Sprite(this->texture, map->second);
																					   };

		// OPERATORS OVERLOADS
		void operator+ (std::pair<unsigned int, sf::Sprite>& newItem)
		{
			intToSprite_map.insert(newItem);
		};
		void operator+= (std::unordered_map<unsigned int, sf::Sprite>& extention)
		{
			std::unordered_map<unsigned int, sf::Sprite>::const_iterator c_it;
			for (c_it = extention.cbegin(); c_it != extention.cend(); ++c_it)
				intToSprite_map.insert(*c_it);
		};
		void operator+= (std::pair<unsigned int, sf::Sprite>*& extention)
		{
			unsigned int size = 1 + sizeof(extention);

			for (unsigned int i = 0; i < size; ++i)
				intToSprite_map.insert(extention[i]);
		};

	protected:
		std::unordered_map<unsigned int, sf::Sprite> intToSprite_map;
	};

	/*Classe bem próxima da Drawble, o diferencial seria ter intrinsecamente Animações no lugar de sprites,
	  para ter uma ou múltiplas animações derivadas de uma única estrutura*/
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
		std::unordered_map<unsigned int, Animation>& GetMap() { return this->intToAnimation_map; };
		const std::unordered_map<unsigned int, Animation>& GetConstMap() { return this->intToAnimation_map; };
		void SetMap(std::unordered_map<unsigned int, Animation>& map) { intToAnimation_map = map; };
		void SetMap(std::pair<unsigned int, Animation>*& map, unsigned int pairsNum) { for (unsigned int i = 0; i < pairsNum; i++)
																							intToAnimation_map[map->first] = map->second;
																					 };
		void SetMap(std::pair<unsigned int, AnimationDataType>*& map, unsigned int pairsNum) {	for (unsigned int i = 0; i < pairsNum; i++)
																									intToAnimation_map[map->first] = Animation(map->second);
																							 };

		// OPERATORS OVERLOADS
		void operator+ (std::pair<unsigned int, Animation>& newItem) 
		{
			intToAnimation_map.insert(newItem);
		};
		void operator+= (std::unordered_map<unsigned int, Animation>& extention)
		{
			std::unordered_map<unsigned int, Animation>::const_iterator c_it;
			for (c_it = extention.cbegin(); c_it != extention.cend(); ++c_it)
				intToAnimation_map.insert(*c_it);
		};
		void operator+= (std::pair<unsigned int, Animation>*& extention)
		{
			unsigned int size = 1 + sizeof(extention);

			for (unsigned int i = 0; i < size; ++i)
				intToAnimation_map.insert(extention[i]);
		};

	protected:
		std::unordered_map<unsigned int, Animation> intToAnimation_map;
		unsigned int lastUsedAnimation;
	};
}

/*class SingleSpriteDrawble : public Drawable
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