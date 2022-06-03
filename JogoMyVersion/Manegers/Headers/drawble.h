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

		void InvertTextureOrientation() { this->faceRight = !this->faceRight; };

		virtual void SelfPrint(const sf::RenderWindow& window) = 0;

	public:
		sf::Texture texture;
		bool faceRight;
	};

	typedef std::vector<AnimaData> VecAnimaValues;
	class WithAnimation 
	{
	public:
		WithAnimation();
		WithAnimation(const std::vector<Animation>& _animationMap);
		WithAnimation(const VecAnimaValues& _animationMap);
		~WithAnimation();

		const std::vector<Animation>& GetConstAnimationMap() { return this->animationVec; };
		void SetAnimationMap(const std::vector<Animation>& _animationMap) { this->animationVec = _animationMap; };

		void operator+= (const std::vector<Animation>& _animationMap)
		{
			this->animationVec = _animationMap;
		}
		void operator+= (const VecAnimaValues& _animationMap)
		{
			size_t diff = this->animationVec.capacity() - this->animationVec.size();
			this->animationVec.reserve(diff + _animationMap.size());

			for (unsigned int i = 0; i < _animationMap.size(); ++i)
				this->animationVec.emplace_back(_animationMap[i]);
		}
		void operator+= (const AnimaData& _animation)
		{
			this->animationVec.emplace_back(_animation);
		}

	protected:
		std::vector<Animation> animationVec;
	};

	class SingleSpriteDrawable : public BaseDrawable, public WithAnimation
	{
	public:
		SingleSpriteDrawable();
		SingleSpriteDrawable(const sf::Sprite& _sprite, const sf::Texture& texture, const bool FacesRight = true);
		SingleSpriteDrawable(const sf::Sprite& _sprite, const std::string fileName, const bool FacesRight = true);
		~SingleSpriteDrawable();

		sf::Sprite& GetSprite() { return this->sprite; };
		const sf::Sprite& GetConstSprite() { return this->sprite; };
		void SetSprite(const sf::Sprite& _sprite) { this->sprite = _sprite; };

		virtual void SelfPrint(const sf::RenderWindow& window) = 0;

	protected:
		sf::Sprite sprite;
	};

	class MultipleSpriteDrawable : public BaseDrawable, public WithAnimation
	{
	public:
		MultipleSpriteDrawable();
		MultipleSpriteDrawable(const std::vector<sf::Sprite>& _spritesVec, const sf::Texture& texture, const bool FacesRight = true);
		MultipleSpriteDrawable(const std::vector<sf::IntRect>& _spritesVecValues, const std::string texture_fileName, const bool FacesRight = true);
		~MultipleSpriteDrawable();

		std::vector<sf::Sprite>& GetSpriteVec() { return this->spritesVec; };
		const std::vector<sf::Sprite>& GetConstSpriteVec() { return this->spritesVec; };
		void SetSpriteVec(const std::vector<sf::Sprite>& _spritesVec) { this->spritesVec = _spritesVec; };

		virtual void SelfPrint(const sf::RenderWindow& window) = 0;

		void operator+=(const sf::Sprite& sprite)
		{
			spritesVec.push_back(sprite);
		}
		void operator+=(const sf::IntRect& spriteValue)
		{
			spritesVec.emplace_back(spriteValue);
		}

	protected:
		std::vector<sf::Sprite> spritesVec;
	};

	class SingleRectangleDrawable : public BaseDrawable, public WithAnimation
	{
	public:
		SingleRectangleDrawable();
		SingleRectangleDrawable(const sf::RectangleShape& body, const sf::Texture& texture, const bool FacesRight = true);
		SingleRectangleDrawable(const sf::RectangleShape& body, const std::string texture_fileName, const bool FacesRight = true);
		~SingleRectangleDrawable();

		sf::RectangleShape& GetRectShape() { return this->body; };
		const sf::RectangleShape& GetConstRectShape() { return this->body; };
		void SetEntityBody(const sf::RectangleShape& newPosition) { this->body = newPosition; };

		virtual void SelfPrint(const sf::RenderWindow& window) = 0;

	protected:
		sf::RectangleShape body;
	};

	class MultipleRectangleDrawable : public BaseDrawable, public WithAnimation
	{
	public:
		MultipleRectangleDrawable();
		MultipleRectangleDrawable(const std::vector<sf::RectangleShape>& _bodiesVec, const sf::Texture& texture, const bool FacesRight = true);
		~MultipleRectangleDrawable();

		std::vector<sf::RectangleShape>& GetRectShape() { return this->bodiesVec; };
		const std::vector<sf::RectangleShape>& GetConstRectShape() { return this->bodiesVec; };
		void SetEntityBody(const std::vector<sf::RectangleShape>& _bodiesVec) { this->bodiesVec = _bodiesVec; };

		virtual void SelfPrint(const sf::RenderWindow& window) = 0;

		void operator+=(const sf::RectangleShape& sprite)
		{
			bodiesVec.push_back(sprite);
		}

	protected:
		std::vector<sf::RectangleShape> bodiesVec;
	};
}