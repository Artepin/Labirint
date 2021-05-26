#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Map.h"
#include "Menu.h"
#include "View.h"

using namespace sf;

void Player::update(float time)
{
	switch (dir)
	{
	case 0: dx = speed; dy = 0; break;
	case 1: dx = -speed; dy = 0; break;
	case 2: dx = 0; dy = speed; break;
	case 3: dx = 0; dy = -speed; break;

	}

	x += dx * time;
	y += dy * time;
	speed = 0;
	sprite.setPosition(x, y);
	interactionWithMap();
	if (health <= 0) { life = false; death = true; }//если жизней меньше либо равно 0, то умираем 

}

float getplayercoordinateX() {
	return x;
}
float getplayercoordinateY() {
	return y;
}

bool startGame()
{
	RenderWindow window(VideoMode(1300, 700), "Labirint");
	menu(window);//вызов меню
	view.reset(FloatRect(0, 0, 640, 480));
}