#pragma once

#include "../Headers/parallax.h"

#define VIEW_COEFFICIENT 0.25f

#define BACKGROUND_WIDTH 1920
#define BACKGROUND_HEIGHT 1080

BackGround::BackGround(const float _dist_coeffic) :
	view(), texture(), sprite(), dist_coeffic(_dist_coeffic)
{
	Initialize(sf::Vector2f(1920.f, 1080.f));
};
BackGround::BackGround(const sf::Vector2f& _size, const sf::View& _view, const sf::Texture& _texture, const sf::Sprite& _sprite, const float _dist_coeffic) :
	view(_view), texture(_texture), sprite(_sprite), dist_coeffic(_dist_coeffic)
{
	Initialize(_size);
};
BackGround::BackGround(const sf::Vector2f& _size, const sf::View& _view, const std::string& _texture_fileName, const sf::Sprite& _sprite, const float _dist_coeffic) :
	view(_view), texture(), sprite(_sprite), dist_coeffic(_dist_coeffic)
{
	this->texture.loadFromFile(_texture_fileName);
	Initialize(_size);
};
BackGround::~BackGround()
{};

void BackGround::Initialize(const sf::Vector2f& _size)
{
	this->view.setSize(_size);
	this->view.setCenter(_size / 2.0f);

	this->texture.setRepeated(false);
	this->texture.setSmooth(false);

	this->sprite.setTexture(this->texture);
	this->sprite.setScale(3.333f, 3.333f);
	this->sprite.setOrigin(_size / 2.0f);
	this->sprite.setPosition(this->view.getCenter());
};
void BackGround::UpdateBackground(sf::RenderWindow& window, const sf::Vector2f& refDeltaPos, float elapsed_time)
{
	sf::Vector2f nextOffSet(refDeltaPos * dist_coeffic * elapsed_time);
	//sf::Vector2f deltaDis;

	//deltaDis.x = (this->view.getCenter().x - this->view.getSize().x / 2.0f) - nextOffSet.x;
	//deltaDis.y = (this->view.getCenter().y - this->view.getSize().y / 2.0f) - nextOffSet.y;

	// Baseado na nova posição do personagem move-se pelo seu equivalente vezes o coeficiente da distancia 
	// Dessa camada de 'background', tudo em função do tempo elapsado
	this->view.move(nextOffSet);
	this->sprite.setPosition(this->view.getCenter());
};

Parallax::Parallax() :
	backgrounds()
{
	Initialize();
};
Parallax::~Parallax()
{};


void Parallax::Initialize()
{
	std::stringstream ss;
	for (unsigned int i = 1; i < 6; ++i)
	{
		ss.clear();
		ss << "JogoMyVersion\\Resources\\images\\backgrounds\\Background\\" << i << ".png\0";
		this->backgrounds.emplace_back(sf::Vector2f(BACKGROUND_WIDTH, BACKGROUND_HEIGHT), sf::View(), ss, (i - 1) * VIEW_COEFFICIENT);
	}
};
void Parallax::DrawBackground(sf::RenderWindow& window, const sf::Vector2f& refDeltaPos, float elapsed_time)
{
	for (BackGround back : this->backgrounds)
	{
		back.UpdateBackground(window, refDeltaPos, elapsed_time);
		window.setView(back.GetConstView());
		window.draw(back.GetConstSprite());
	}
};

/*BackGround::BackGround(const std::string& _texture, const float& _view_proportion, const float& _acceleration) :
	backGround(), texture(), body(), view_proportion(_view_proportion), acceleration(_acceleration)
{
	this->texture.loadFromFile(_texture);
	Initialize();
};
BackGround::BackGround(const sf::Texture& _texture, const float& _view_proportion, const float& _acceleration) :
	backGround(), texture(_texture), body(), view_proportion(_view_proportion), acceleration(_acceleration)
{
	Initialize();
};
BackGround::~BackGround()
{};

void BackGround::Initialize()
{
	this->sprite.setOrigin(this->body.getSize() / 2.0f);
	this->sprite.setTexture(&this->texture);
	this->sprite.setPosition(sf::Vector2f(0.0f, 0.0f));
	this->backGround.setCenter(sf::Vector2f(0.0f, -(this->body.getSize().y / 4.0f) * 3));
	this->backGround.setSize(sf::Vector2f(BACKGROUND_WIDTH * this->view_proportion, BACKGROUND_HEIGHT * this->view_proportion));
};
void BackGround::DrawBackground(const sf::Vector2f& refDeltaPos, float elapsed_time)
{
	

};*/