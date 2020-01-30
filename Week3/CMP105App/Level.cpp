#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	circle.setFillColor(sf::Color::Yellow);
	circle.setOutlineColor(sf::Color::White);
	circle.setOutlineThickness(10.f);
	circle.setRadius(30.f);
	circle.setPosition(sf::Vector2f(250.f, 300.f));
	speed = 200.f;

	rect.setFillColor(sf::Color::Black);
	rect.setOutlineColor(sf::Color::Cyan);
	rect.setOutlineThickness(3.f);
	rect.setSize(sf::Vector2f(30.f, 22.f));
	rect.setPosition(sf::Vector2f(300.f, 300.f));
	rectspeed = 100.f;

	bouncer.setFillColor(sf::Color::Magenta);
	bouncer.setOutlineColor(sf::Color::Black);
	bouncer.setOutlineThickness(1.f);
	bouncer.setRadius(50.f);
	bouncer.setPosition(sf::Vector2f(0.f, 300.f));
	bouncerspeed = 75.f;

	_winsize = window->getSize();
	toright = true;
	lefttop = true;
	topright = false;
	rightbot = false;
	botleft = false;
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{

}

// Update game objects
void Level::update(float dt)
{
	_circlepos = circle.getPosition();
	_rectpos = rect.getPosition();
	_bouncerpos = bouncer.getPosition();
	_winsize = window->getSize();

	if (toright)
	{
		if (_circlepos.x < _winsize.x-circle.getRadius()*2-circle.getOutlineThickness()) circle.move(speed * dt, 0);
		else toright = false;
	}
	else if (!toright)
	{
		if (_circlepos.x > 0) circle.move(-(speed * dt), 0);
		else toright = true;
	}

	if (input->isKeyDown(sf::Keyboard::Left))
	{
		if(_rectpos.x > 0) rect.move(-(rectspeed * dt), 0);
	}
	if (input->isKeyDown(sf::Keyboard::Right))
	{
		if (_rectpos.x < _winsize.x) rect.move((rectspeed * dt), 0);
	}
	if (input->isKeyDown(sf::Keyboard::Up))
	{
		if (_rectpos.y > 0) rect.move(0, -(rectspeed * dt));
	}
	if (input->isKeyDown(sf::Keyboard::Down))
	{
		if (_rectpos.y < _winsize.y) rect.move(0, (rectspeed * dt));
	}

	if (lefttop)
	{
		if (_bouncerpos.y > 0) bouncer.move(bouncerspeed * dt, -(bouncerspeed / 1.75f * dt));
		else
		{
			lefttop = false;
			topright = true;
		}
	}
	else if (topright)
	{
		if (_bouncerpos.x < _winsize.x - bouncer.getRadius()*2) bouncer.move(bouncerspeed * dt, bouncerspeed / 2 * dt);
		else
		{
			topright = false;
			rightbot = true;
		}

	}
	else if (rightbot)
	{
		if (_bouncerpos.y < _winsize.y-bouncer.getRadius()*2) bouncer.move(-(bouncerspeed * dt), bouncerspeed / 2 * dt);
		else
		{
			rightbot = false;
			botleft = true;
		}
	}
	else if (botleft)
	{
		if (_bouncerpos.x > 0) bouncer.move(-(bouncerspeed * dt), -(bouncerspeed / 2 * dt));
		else
		{
			botleft = false;
			lefttop = true;
		}

	}
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(circle);
	window->draw(rect);
	window->draw(bouncer);

	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}