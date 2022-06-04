#pragma once

#include "stdafx.h"
#include "../Entities/Headers/entity.h"

class CollisionManager {
public:
	CollisionManager();
	//CollisionManager(std::vector<entities::DrawableEntity*>& _entities);
	~CollisionManager();

	void VerifyColisions();

protected:
	//std::vector<entities::DrawableEntity*> entities;
};