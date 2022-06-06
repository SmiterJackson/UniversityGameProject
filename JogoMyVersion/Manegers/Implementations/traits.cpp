#pragma once

#include "../Headers/traits.h"
using namespace traits;

//////////////////////////////////////////////////////////////////////////////////////
float Movable::global_gravity = 1.0f;

Movable::Movable(const bool _have_ground, const float _horizontal_acc, const float _vertical_acc) :
	horizontal_acc(_horizontal_acc), vertical_acc(_vertical_acc), have_ground(_have_ground), walk_right(false), walk_left(false), jumping(false)
{};
Movable::~Movable()
{};
//////////////////////////////////////////////////////////////////////////////////////
Slipery::Slipery(const float _coefficient) :
	friction_coefficient(_coefficient)
{};
Slipery::~Slipery()
{};
//////////////////////////////////////////////////////////////////////////////////////
ForcesAtDirect::ForcesAtDirect(const float _surface_acceler, const bool dir_is_right) :
	surface_acceler(_surface_acceler), dir_is_right(dir_is_right)
{};
ForcesAtDirect::~ForcesAtDirect()
{};

void ForcesAtDirect::InvertDirection()
{
	this->dir_is_right = !this->dir_is_right;
};
//////////////////////////////////////////////////////////////////////////////////////
Alive::Alive(const unsigned int _life_count) :
	life_count(_life_count), alive(true)
{};
Alive::~Alive()
{};

void Alive::InvertLifeState()
{
	this->alive = !this->alive;
};
//////////////////////////////////////////////////////////////////////////////////////
Printable::Printable() :
	texture(), faceRight(true)
{};
Printable::Printable(const sf::Texture& texture, const bool FacesRight) :
	texture(texture), faceRight(FacesRight)
{};
Printable::Printable(const std::string fileName, const bool FacesRight) :
	texture(), faceRight(FacesRight)
{
	this->texture.loadFromFile(fileName);
};
Printable::~Printable()
{};

void Printable::InvertTextureOrientation()
{
	this->faceRight = !this->faceRight;
};
//////////////////////////////////////////////////////////////////////////////////////
Collidable::Collidable(sf::RectangleShape& _body, const float _weight_ceffic) :
	rect(_body), weight_coeffic(std::min(std::max(_weight_ceffic, 0.0f), 1.0f))
{};
Collidable::~Collidable()
{};

/*bool Collidable::CheckCollision(BaseObstacle& item_2)
{
	sf::RectangleShape& body_1 = item_2.GetBodyRef();
	sf::RectangleShape& body_2 = item_2.GetBody();

	sf::Vector2f pos_1(body_1.getPosition());
	sf::Vector2f pos_2(body_2.getPosition());

	sf::Vector2f MinDistance(body_1.getOrigin() + body_2.getOrigin());
	sf::Vector2f distanceBetween(abs(pos_1.x - pos_2.x), abs(pos_1.y - pos_2.y));

	sf::Vector2f diff(distanceBetween.x - MinDistance.x, distanceBetween.y - MinDistance.y);

	// Caso a diferença das distâncias x e y seja maior que a soma do tamanho de cada objeto, será então, denotado um contato entre os objetos
	if (diff.x < 0.0f && diff.y < 0.0f)
	{
		if (diff.x < diff.y)
		{
			body_1.move(diff.x * item_2.GetWeightCoefficient(), 0.0f);
			body_2.move(-diff.x * (1.0f - item_2.GetWeightCoefficient()), 0.0f);
		}
		else
		{
			body_1.move(0.0f, diff.y * item_2.GetWeightCoefficient());
			body_2.move(0.0f, -diff.y * (1.0f - item_2.GetWeightCoefficient()));
			item_1.InvertHaveGround();
		}

		return true;
	}

	return false;
};*/

/*bool Collidable::CheckCollision(sf::RectangleShape& _body)
{
	sf::Vector2f other_pos(_body.getPosition());
	sf::Vector2f this_pos(this->rect.getPosition());

	sf::Vector2f MinDistance(_body.getOrigin() + this->rect.getOrigin());
	sf::Vector2f distanceBetween(abs(this_pos.x - other_pos.x), abs(this_pos.y - other_pos.y));

	sf::Vector2f diff(distanceBetween.x - MinDistance.x, distanceBetween.y - MinDistance.y);

	// Caso a diferença das distâncias x e y seja maior que a soma do tamanho de cada objeto, será então, denotado um contato entre os objetos
	if(diff.x < 0.0f && diff.y < 0.0f)
	{
		// Caso a sobreposição dos objetos em 'x' seja maior ou igual que em 'y', move-se os valores pelo eixo 'x'
		// Cada objeto é deslocado porporcionalmente ao seu valor interno de 'peso', 
		// com seus respectivos valores inversos do total da sobrepoosição
		if (diff.x >= diff.y)
		{
			// inverte os sinais dependendo dos valores de cada objeto
			if (distanceBetween.x < 0.0f) 
			{
				this->rect.move(diff.x * (1.0f - weight_coeffic), 0.0f);
				_body.move(-diff.x * weight_coeffic, 0.0f);
			}
			else 
			{
				this->rect.move(-diff.x * (1.0f - weight_coeffic), 0.0f);
				_body.move(diff.x * weight_coeffic, 0.0f);
			}
		}
		else
		{
			if (distanceBetween.y < 0.0f)
			{
				this->rect.move(0.0f, diff.y * (1.0f - weight_coeffic));
				_body.move(0.0f, -diff.y * (1.0f - weight_coeffic));
			}
			else
			{
				this->rect.move(0.0f, -diff.y * (1.0f - weight_coeffic));
				_body.move(0.0f, diff.y * (1.0f - weight_coeffic));
			}
		}

		return true;
	}

	return false;
};*/
//////////////////////////////////////////////////////////////////////////////////////
Animated::Animated() :
	animationVec(), next_ani(0), lastUsedAni(0), elapsed_time(0.0f)
{};
Animated::Animated(const std::vector<Animation>& _animationVec) :
	animationVec(_animationVec), next_ani(0), lastUsedAni(0), elapsed_time(0.0f)
{};
Animated::Animated(const VecAnimaValues& _animationVec) :
	animationVec(), next_ani(0), lastUsedAni(0), elapsed_time(0.0f)
{
	size_t diff = this->animationVec.capacity() - this->animationVec.size();
	this->animationVec.reserve(diff + _animationVec.size());

	for (unsigned int i = 0; i < _animationVec.size(); ++i)
		this->animationVec.emplace_back(_animationVec[i]);
};
Animated::~Animated()
{};