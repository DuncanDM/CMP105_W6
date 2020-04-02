#pragma once

#include "Framework/GameObject.h"
#include "Framework/Vector.h"

class DirectBall :public GameObject
{
public:
	DirectBall();
	~DirectBall();

	void update(float dt);

private:
	sf::Vector2f direction;
	sf::Vector2f target;
	float speed;
};