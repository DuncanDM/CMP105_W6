#include "Ball.h"

Ball::Ball() 
{
	scale = 200.0f;
	gravity = sf::Vector2f(0, 9.8f) * scale;
	jumpVelocity = sf::Vector2f(0, -6.f) * scale;
	jumpAct = false;
}

Ball::~Ball()
{

}

void Ball::handleInput(float dt, float y)
{
	if (input->isKeyDown(sf::Keyboard::Space))
	{
		if (!jumpAct && getPosition().y >= y)
		{
			stepVelocity = jumpVelocity;
			jumpAct = true;
		}
	}

	if (input->isMouseRDown() == true)
	{
		setPosition(input->getMouseX(), input->getMouseY());
	}
}

void Ball::update(float dt, float y)
{
	sf::Vector2f pos = stepVelocity * dt + velocity * dt + 0.5f * gravity * dt * dt;
	stepVelocity += gravity *dt;

	setPosition(getPosition() + pos);
	
	if(getPosition().y >= y)
	{
		setPosition(getPosition().x, y);

		jumpAct = false;
		stepVelocity = (-stepVelocity) / 1.2f;
	}

}