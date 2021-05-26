#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Map.h"
#include "Menu.h"
#include "View.h"

using namespace sf;

bool startGame()
{
	RenderWindow window(VideoMode(1300, 700), "Labirint");
	menu(window);//вызов меню
	view.reset(FloatRect(0, 0, 640, 480));
}