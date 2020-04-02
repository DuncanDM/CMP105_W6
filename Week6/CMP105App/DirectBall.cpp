#include "DirectBall.h"

DirectBall::DirectBall()
{
	target = sf::Vector2f(0, 0);
	speed = 50.f;
}

DirectBall::~DirectBall()
{

}

void DirectBall::update(float dt)
{
	target = sf::Vector2f(input->getMouseX(), input->getMouseY());
	direction = target - getPosition();
	direction = Vector::normalise(direction);
	velocity += (direction * speed) * dt;
	setPosition(getPosition() + (velocity * dt));

	if (Vector::magnitude(target - getPosition()) < 10.f)
	{
		setPosition(target);
		velocity = sf::Vector2f(0, 0);
	}
}