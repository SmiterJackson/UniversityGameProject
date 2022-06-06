#include "../Headers/collider.h"

Collider::Collider() :
	livingEntities(), obstacles()
{};
Collider::Collider(const std::vector<LivingEntity*>& _livingEntities, std::vector<BaseObstacle*> _obstacles) :
	livingEntities(_livingEntities), obstacles(_obstacles)
{};
Collider::~Collider()
{};

void Collider::UpdateCollisions()
{
	unsigned int i = 0, j = 0;
	bool no_colision = true;
	for (i = 0; i < this->livingEntities.size(); ++i)
	{
		for (j = 0; j < this->obstacles.size(); ++j)
		{
			if(CheckCollision(*livingEntities[i], *obstacles[j])) // Verifica colisão de criaturas com obstáculos
				livingEntities[i]->InvertHaveGround();

			/*if (CheckNext(*livingEntities[i], *obstacles[j])) // Verifica se há colisão na futura posição entre uma criatura com obstáculos, denotando uma futura queda
				no_colision = false;
			if (no_colision)
				livingEntities[i]->InvertHaveGround();*/
		}
		
	}	
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
			std::cout << "Collided 'x' asix" << std::endl;
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
			std::cout << "Collided 'y' asix" << std::endl;
		}
		return true;
	}

	return false;
};

bool Collider::CheckNext(LivingEntity& entity, BaseObstacle& obst)
{
	sf::RectangleShape& entity_body = entity.GetBody();
	sf::RectangleShape& obst_body = obst.GetBody();

	float delta_distance = entity_body.getPosition().y - obst_body.getPosition().y + 1;
	float intersection = fabs(delta_distance) - (entity_body.getSize().y / 2.0f + obst_body.getSize().y / 2.0f);

	// Caso a diferença das distâncias x e y seja maior que a soma do tamanho de cada objeto, será então, denotado um contato entre os objetos
	if (intersection < 0.0f)
	{
		std::cout << "Tem colisao futura em eixo 'y'" << std::endl;
		return true;
	}

	return false;
};