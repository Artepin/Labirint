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
		image.loadFromFile("images/" + F);
		image.createMaskFromColor(Color(255, 255, 255));
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		sprite.setTextureRect(IntRect(0, 0, w, h));
	}
	void Player::update(float time)
	{
		switch (Player::dir)
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
		if (health <= 0) { life = false; }//если жизней меньше либо равно 0, то умираем 

	}
	float Player::getplayercoordinateX() {
		return x;
	}
	float Player::getplayercoordinateY() {
		return y;
	}