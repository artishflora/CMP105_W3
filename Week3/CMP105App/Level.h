#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string.h>
#include <iostream>


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	sf::CircleShape circle;
	float speed;
	bool toright;
	sf::RectangleShape rect;
	float rectspeed;
	sf::CircleShape bouncer;
	float bouncerspeed;
	bool lefttop;
	bool topright;
	bool rightbot;
	bool botleft;

	sf::Vector2u _winsize;
	sf::Vector2f _circlepos;
	sf::Vector2f _rectpos;
	sf::Vector2f _bouncerpos;

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
};