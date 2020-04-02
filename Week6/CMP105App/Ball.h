#pragma once

#include "Framework/GameObject.h"

class Ball :public GameObject
{
public:
	Ball();
	~Ball();

	void update(float dt, float y);
	void handleInput(float dt, float y);

private:
	float scale;
	bool jumpAct;

	sf::Vector2f gravity;
	sf::Vector2f stepVelocity;
	sf::Vector2f jumpVelocity;
};