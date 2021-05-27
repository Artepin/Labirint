#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
const int HEIGHT_MAP = 29;
const int WIDTH_MAP = 56;


sf::String TileMap[HEIGHT_MAP];
void Player::interactionWithMap();
