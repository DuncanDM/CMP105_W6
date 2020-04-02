#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	ball.setInput(input);
	dirBall.setInput(input);
	lBall.setInput(input);

	ballTexture.loadFromFile("gfx/Beach_Ball.png");
	ball.setSize(sf::Vector2f(50, 50));
	ball.setPosition(100, 100);
	ball.setTexture(&ballTexture);

	dirBallTexture.loadFromFile("gfx/Beach_Ball.png");
	dirBall.setSize(sf::Vector2f(50, 50));
	dirBall.setPosition(50, 50);
	dirBall.setTexture(&ballTexture);

	lBallTexture.loadFromFile("gfx/Beach_Ball.png");
	lBall.setSize(sf::Vector2f(50, 50));
	lBall.setPosition(50, 500);
	lBall.setTexture(&ballTexture);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	ball.handleInput(dt, winSize.y - 50);
	lBall.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	winSize = window->getSize();

	ball.update(dt, (winSize.y - 50));
	dirBall.update(dt);
	lBall.update(dt, (winSize.y - 50));
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(ball);
	window->draw(dirBall);
	window->draw(lBall);

	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}