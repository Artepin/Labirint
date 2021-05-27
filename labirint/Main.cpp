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
	if (health <= 0) { life = false;}//���� ������ ������ ���� ����� 0, �� ������� 

}

bool startGame()
{
	RenderWindow window(VideoMode(1300, 700), "Labirint");
	menu(window);//����� ����
	view.reset(FloatRect(0, 0, 640, 480));

	Font font;
	font.loadFromFile("CyrilicOld.ttf");
	Text text("", font, 20);
	text.setFillColor(Color::Red);
	text.setStyle(Text::Bold);

	Image map_image;
	map_image.loadFromFile("images/map_1.png");
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);

	Image quest_image;
	quest_image.loadFromFile("images/missionbg.jpg");
	quest_image.createMaskFromColor(Color(0, 0, 0));
	Texture quest_texture;
	quest_texture.loadFromImage(quest_image);
	Sprite s_quest;
	s_quest.setTexture(quest_texture);
	s_quest.setTextureRect(IntRect(0, 0, 340, 510));  //���������� �����, ������� �������� ��������
	s_quest.setScale(0.6f, 0.6f);//���� ��������� ��������, => ������ ���� ������

	Player p("images/hero_2.png", 250, 250, 32.0, 32.0);

	bool showMissionText = true;//���������� ����������, ���������� �� ��������� ������ ������ �� ������
	bool life = true;
}