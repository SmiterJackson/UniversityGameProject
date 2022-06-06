#pragma once

#include "../Headers/parallax.h"

#define VIEW_COEFFICIENT 0.2f

#define BACKGROUND_HEIGHT 324
#define BACKGROUND_WIDTH 576

BackGround::BackGround() :
	backGroundViews(), windowRef(nullptr), texture(), views_proportion(1.0f)
{
	Initialize(sf::Vector2f(0.0f, 0.0f));
};
BackGround::BackGround(const std::string& texture_fileName, sf::RenderWindow& window, const sf::Vector2f& views_size, float _proportion) :
	backGroundViews(), windowRef(&window), texture(), views_proportion(_proportion)
{
	this->texture.loadFromFile(texture_fileName);
	Initialize(views_size);
};
BackGround::BackGround(const sf::Texture& _texture, sf::RenderWindow& window, const sf::Vector2f& views_size, float _proportion) :
	backGroundViews(), windowRef(&window), texture(_texture), views_proportion(_proportion)
{
	Initialize(views_size);
};
BackGround::~BackGround()
{};

void BackGround::Initialize(const sf::Vector2f size)
{
	std::vector<std::pair<sf::View, float>>::iterator it;

	for(unsigned int i = 1; i < 6; ++i)
		backGroundViews.emplace_back(std::pair<sf::View, float>(sf::View(sf::Vector2f(0.0f, 0.0f), size), 1.0f - (VIEW_COEFFICIENT * i)));

	for (it = backGroundViews.begin(); it != backGroundViews.end(); ++it)
		it->first.setSize(it->first.getSize() * it->second);
};

void BackGround::UpdateBackGround(const sf::Vector2f& refDeltaPos)
{
	if (this->windowRef != nullptr)
	{
		std::vector<std::pair<sf::View, float>>::iterator it;
		sf::Vector2f position;
		sf::Sprite sprite(this->texture);
		sf::IntRect cut;
		unsigned int i = 0, j = 0;
		bool first = true;
		sprite.setOrigin(sf::Vector2f(BACKGROUND_WIDTH / 2.0f, BACKGROUND_HEIGHT / 2.0f));

		for (it = backGroundViews.begin(); it != backGroundViews.end(); ++it)
		{
			position = it->first.getCenter() / 2.0f;
			position.y -= it->first.getSize().y / 2.0f;

			it->first.setCenter(position);
		}
		//CheckViewsOutBounds();

		for (it = backGroundViews.begin(), i = 0; it != backGroundViews.end(); ++it, ++i)
		{
			cut.top = BACKGROUND_HEIGHT * j;
			cut.left = BACKGROUND_WIDTH * i;
			cut.height = BACKGROUND_HEIGHT;
			cut.width = BACKGROUND_WIDTH;

			sprite.setTextureRect(cut);
			this->windowRef->setView(it->first);
			this->windowRef->draw(sprite);

			if (i == 1)
				i = 0;
			if (i == 0 && !first)
				j++;
			first = false;
		}
		//this->windowRef->display();
	}
};

/*
void BackGround::CheckViewsOutBounds()
{
	std::vector<std::pair<sf::View, float>>::iterator it;
	sf::Vector2f view_size, view_center, window_size(this->windowRef->getSize());
	sf::Vector2f delta_distance;

	for (it = backGroundViews.begin(); it != backGroundViews.end(); ++it)
	{
		view_size = it->first.getSize() / 2.0f;
		view_center = it->first.getCenter();

		delta_distance.x = view_center.x - view_size.x;
		delta_distance.y = view_center.y - view_size.y;

		if (delta_distance.x < 0.0f || delta_distance.y < 0.0f)
		{
			if (delta_distance.x < -400.0f)
				it->first.setCenter(view_center.x + -(delta_distance.x), it->first.getCenter().y);
			if (delta_distance.y < -400.0f)
				it->first.setCenter(it->first.getCenter().x, view_center.y + -(delta_distance.y));
			return;
		}

		delta_distance.x = view_center.x + view_size.x;
		delta_distance.y = view_center.y + view_size.y;


		if (delta_distance.x < window_size.x)
			it->first.setCenter(view_center.x + -(delta_distance.x), it->first.getCenter().y);
		if (delta_distance.y < window_size.y)
			it->first.setCenter(it->first.getCenter().x, view_center.y + -(delta_distance.y));
	}
};
*/