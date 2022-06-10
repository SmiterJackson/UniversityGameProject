#include "../Headers/collider.h"

#define TIME_VERIFICATION 0.015f

Collider::MapBounds::MapBounds() :
	leftBound(300.f), topBound(300.f), rightBound(300.f), bottomBound(300.f)
{};
Collider::MapBounds::MapBounds(float _leftBound, float _topBound, float _rightBound, float _bottomBound) :
	leftBound(_leftBound), topBound(_topBound), rightBound(_rightBound), bottomBound(_bottomBound)
{};
Collider::MapBounds::~MapBounds()
{};


Collider::Collider() :
	mapLimits(), livingEntities(), obstacles(), timer(0.0f)
{};
Collider::Collider(const MapBounds& _mapLimits) :
	mapLimits(_mapLimits), livingEntities(), obstacles(), timer(0.0f)
{};
Collider::Collider(const MapBounds& _mapLimits, const std::vector<LivingEntity*>& _livingEntities, std::vector<BaseObstacle*> _obstacles) :
	mapLimits(_mapLimits), livingEntities(_livingEntities), obstacles(_obstacles), timer(0.0f)
{};
Collider::~Collider()
{};

void Collider::UpdateCollisions(float _elapsed_time)
{
	this->timer += _elapsed_time;

	if (this->timer > TIME_VERIFICATION)
	{
		unsigned int i = 0, j = 0;
		bool colision;
		this->timer -= TIME_VERIFICATION;
		

		for (i = 0; i < this->livingEntities.size(); ++i)
		{
			colision = false;
			for (j = 0; j < this->obstacles.size(); ++j)
			{
				if (CheckCollisionObstacles(*livingEntities[i], *obstacles[j])) // Verifica colisão de criaturas com obstáculos
				{
					livingEntities[i]->SetHaveGround(true);
					colision = true;
				}
			}
			if (!colision)
				livingEntities[i]->SetHaveGround(false);
		}
	}
};

// Função Adaptada da original, pelo canal Hilze Vonck
bool Collider::CheckCollisionObstacles(LivingEntity& entity, BaseObstacle& obst)
{
	sf::RectangleShape& entity_body = entity.GetBody();
	sf::RectangleShape& obst_body = obst.GetBody();
	sf::Vector2f entity_pos = entity.GetBody().getPosition();
	float diff;
	bool colision = false;

	sf::Vector2f delta_dist(entity_pos.x - obst_body.getPosition().x, entity_pos.y - obst_body.getPosition().y);
	sf::Vector2f intersection(fabs(delta_dist.x) - (entity_body.getSize().x / 2.0f + obst_body.getSize().x / 2.0f), fabs(delta_dist.y) - 0.00001f -(entity_body.getSize().y / 2.0f + obst_body.getSize().y / 2.0f));

	// Caso a diferença das distâncias x e y seja maior que a soma do tamanho de cada objeto, será então, denotado um contato entre os objetos
	if (intersection.x < 0.0f && intersection.y < 0.0f)
	{
		intersection.y += 0.0001f;
		if (intersection.x > intersection.y)
		{
			if (delta_dist.x > 0.0f)
			{
				entity_body.move(-intersection.x * obst.GetWeightCoefficient(), 0.0f);
				obst_body.move(intersection.x * (1.0f - obst.GetWeightCoefficient()), 0.0f);
			}
			else
			{
				entity_body.move(intersection.x * obst.GetWeightCoefficient(), 0.0f);
				obst_body.move(-intersection.x * (1.0f - obst.GetWeightCoefficient()), 0.0f);
			}
		}
		else
		{
			if (delta_dist.y > 0.0f)
			{
				entity_body.move(0.0f, -intersection.y * obst.GetWeightCoefficient());
				obst_body.move(0.0f, intersection.y * (1.0f - obst.GetWeightCoefficient()));
			}
			else
			{
				entity_body.move(0.0f, intersection.y * obst.GetWeightCoefficient());
				obst_body.move(0.0f, -intersection.y * (1.0f - obst.GetWeightCoefficient()));
			}
			colision = true;
		}
	}
	if (entity_pos.x - entity.GetBody().getOrigin().x < this->mapLimits.leftBound)
	{
		diff = fabs(entity_pos.x - entity.GetBody().getOrigin().x - this->mapLimits.leftBound);
		entity.GetBody().move(diff, 0.f);
	}
	if (entity_pos.x + entity.GetBody().getOrigin().x > this->mapLimits.rightBound)
	{
		diff = -(fabs(entity_pos.x) + entity.GetBody().getOrigin().x - this->mapLimits.rightBound);
		entity.GetBody().move(diff, 0.f);
	}
	if (entity_pos.y - entity.GetBody().getOrigin().y < this->mapLimits.topBound)
	{
		diff = fabs(entity_pos.y - entity.GetBody().getOrigin().y - this->mapLimits.leftBound);
		entity.GetBody().move(0.f, diff);
	}
	if (entity_pos.y + entity.GetBody().getOrigin().y + 0.1f > this->mapLimits.bottomBound)
	{
		diff = -(fabs(entity_pos.y) + entity.GetBody().getOrigin().y - this->mapLimits.bottomBound - 0.1f);
		entity.GetBody().move(0.f, diff);
		colision = true;
	}

	return colision;
};