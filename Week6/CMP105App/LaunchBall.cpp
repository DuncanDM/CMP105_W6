#include "LaunchBall.h"

LaunchBall::LaunchBall()
{
	speed = 0;
	firstClick = false;
	launched = false;
	scale = 200.0f;
	gravity = sf::Vector2f(0, 9.8f) * scale;
	//airRes = sf::Vector2f(1.f, 0) * scale;
}

LaunchBall::~LaunchBall()
{

}

void LaunchBall::handleInput(float dt)
{
	if (input->isMouseLDown() == true)
	{
		if (!firstClick)
		{
			startPoint = sf::Vector2f(input->getMouseX(), input->getMouseY());
			firstClick = true;
		}
		else
		{
			endPoint = sf::Vector2f(input->getMouseX(), input->getMouseY());
		}
	}
	else if (firstClick)
	{
		launched = true;
		firstClick = false;
	}
}

void LaunchBall::update(float dt, float y)
{
	if (launched)
	{
		direction = startPoint - endPoint;
		speed = Vector::magnitude(direction) * 10.f;
		direction = Vector::normalise(direction);
		velocity += (direction * speed) * dt * scale;
		launched = false;
		speed = 0;
	}

	//if (velocity.x > 0 && getPosition().y < y)
	//{
	//	airRes = sf::Vector2f(-1.f, 0) * scale;
	//}
	//else if (velocity.x < 0 && getPosition().y < y)
	//{
	//	airRes = sf::Vector2f(1.f, 0) * scale;
	//}
	
	velocity += gravity * dt;

	setPosition(getPosition() + (velocity * dt));

	if (getPosition().y >= y)
	{
		setPosition(getPosition().x, y);
		velocity.y = 0;

		if (velocity.x > 0)
		{
			velocity.x -= velocity.x * 0.25f;

			if (velocity.x < 0)
			{
				velocity.x = 0;
			}
		}
		else if (velocity.x < 0)
		{
			velocity.x += velocity.x * 0.25f;

			if (velocity.x > 0)
			{
				velocity.x = 0;
			}
		}
	}
}