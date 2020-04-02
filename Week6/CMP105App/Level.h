#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string.h>
#include <iostream>
#include "Ball.h"
#include "DirectBall.h"
#include "LaunchBall.h"

class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;

	// More level variables
	Ball ball;
	sf::Texture ballTexture;

	DirectBall dirBall;
	sf::Texture dirBallTexture;

	LaunchBall lBall;
	sf::Texture lBallTexture;

	sf::Vector2u winSize;
};