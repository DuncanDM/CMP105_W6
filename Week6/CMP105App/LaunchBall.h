#pragma once

#include "Framework/GameObject.h"
#include "Framework/Vector.h"

class LaunchBall :public GameObject
{
public:
	LaunchBall();
	~LaunchBall();

	void update(float dt, float y);
	void handleInput(float dt);

private:
	bool firstClick;
	bool launched;
	float speed;
	float scale;

	sf::Vector2f startPoint;
	sf::Vector2f endPoint;
	sf::Vector2f direction;
	sf::Vector2f gravity;
	sf::Vector2f airRes;
};