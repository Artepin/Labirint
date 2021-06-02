#include "Player.h"
	Player::Player(String F, float x, float y, float w, float h)
	{
		dir = 0;
		speed = 0;
		dx = 0;
		dy = 0;
		speed = 0;
		health = 0;
		life = true;
		image.loadFromFile("images/" + File);
		image.createMaskFromColor(Color(255, 255, 255));
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		sprite.setTextureRect(IntRect(0, 0, w, h));
	}
	float Player::getplayercoordinateX() {
		return x;
	}
	float Player::getplayercoordinateY() {
		return y;
	}