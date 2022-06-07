#include "../Headers/collider.h"

#define TIME_VERIFICATION 0.015f

Collider::Collider() :
	livingEntities(), obstacles(), elapsed_time(0.0f), timer(0.0f)
{};
Collider::Collider(const std::vector<LivingEntity*>& _livingEntities, std::vector<BaseObstacle*> _obstacles) :
	livingEntities(_livingEntities), obstacles(_obstacles), elapsed_time(0.0f), timer(0.0f)
{};
Collider::~Collider()
{};

void Collider::UpdateCollisions()
{
	this->timer += this->elapsed_time;

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
				if (CheckCollision(*livingEntities[i], *obstacles[j])) // Verifica colisão de criaturas com obstáculos
				{
					livingEntities[i]->SetHaveGround(true);
					colision = true;
				}
			}
			if (!colision)
				livingEntities[i]->SetHaveGround(false);
		}
	}
	/*if (this->timer > TIME_VERIFICATION)
		this->timer -= TIME_VERIFICATION;*/
};

bool Collider::CheckCollision(LivingEntity& entity, BaseObstacle& obst)
{
	sf::RectangleShape& entity_body = entity.GetBody();
	sf::RectangleShape& obst_body = obst.GetBody();

	sf::Vector2f delta_distance(entity_body.getPosition().x - obst_body.getPosition().x, entity_body.getPosition().y - obst_body.getPosition().y);
	sf::Vector2f intersection( fabs(delta_distance.x) - (entity_body.getSize().x / 2.0f + obst_body.getSize().x / 2.0f), fabs(delta_distance.y) - (entity_body.getSize().y / 2.0f + obst_body.getSize().y / 2.0f));

	// Caso a diferença das distâncias x e y seja maior que a soma do tamanho de cada objeto, será então, denotado um contato entre os objetos

	if (intersection.x < 0.0f && intersection.y < 0.0f)
	{
		if (intersection.x > intersection.y)
		{
			if (delta_distance.x > 0.0f)
			{
				entity_body.move(-intersection.x * obst.GetWeightCoefficient(), 0.0f);
				obst_body.move(intersection.x * (1.0f - obst.GetWeightCoefficient()), 0.0f);
			}
			else
			{
				entity_body.move(intersection.x * obst.GetWeightCoefficient(), 0.0f);
				obst_body.move(-intersection.x * (1.0f - obst.GetWeightCoefficient()), 0.0f);
			}
		#ifdef _DEBUG
			std::cout << "Collided 'x' asix" << std::endl;
		#endif
		}
		else
		{
			if (delta_distance.y > 0.0f)
			{
				entity_body.move(0.0f, -intersection.y * obst.GetWeightCoefficient());
				obst_body.move(0.0f, intersection.y * (1.0f - obst.GetWeightCoefficient()));
			}
			else
			{
				entity_body.move(0.0f, intersection.y * obst.GetWeightCoefficient());
				obst_body.move(0.0f, -intersection.y * (1.0f - obst.GetWeightCoefficient()));
			}
		#ifdef _DEBUG
			std::cout << "Collided 'y' asix" << std::endl;
		#endif
		}
		return true;
	}

	return false;
};

bool Collider::CheckNext(LivingEntity& entity, BaseObstacle& obst)
{
	if (this->timer > TIME_VERIFICATION)
	{
		sf::RectangleShape& entity_body = entity.GetBody();
		sf::RectangleShape& obst_body = obst.GetBody();

		sf::Vector2f delta_distance(entity_body.getPosition().x * entity.GetHorizontalAcc() - obst_body.getPosition().x, entity_body.getPosition().y - obst_body.getPosition().y + 2);
		sf::Vector2f intersection(fabs(delta_distance.x) - (entity_body.getSize().x / 2.0f + obst_body.getSize().x / 2.0f), fabs(delta_distance.y) - (entity_body.getSize().y / 2.0f + obst_body.getSize().y / 2.0f));

		// Caso a diferença das distâncias x e y seja maior que a soma do tamanho de cada objeto, será então, denotado um contato entre os objetos
		if (intersection.x < 0.0f && intersection.y < 0.0f)
		{
		#ifdef _DEBUG
			std::cout << "Tem colisao futura em eixo 'y'" << std::endl;
		#endif
			return true;
		}
	}
	return false;
};