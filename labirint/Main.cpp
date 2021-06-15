#include <iostream>
#include <SFML/Graphics.hpp>
#include "Mission.h"
#include "View.h"
#include "Player.h"
#include "Menu.h"
#include "Map.h"
#include "Main.h"




using namespace sf;



bool startGame()
{
	RenderWindow window(VideoMode(1300, 700), "Labirint");
	menu(window);//вызов меню
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
	s_quest.setTextureRect(IntRect(0, 0, 340, 510));  //приведение типов, размеры картинки исходные
	s_quest.setScale(0.6f, 0.6f);//чуть уменьшили картинку, => размер стал меньше

	Player p("images/hero_2.png", 250, 250, 32.0, 32.0);

	bool showMissionText = true;//логическая переменная, отвечающая за появление текста миссии на экране
	bool life = true;

	float currentFrame = 0;
	Clock clock;
	Clock gameTimeClock;//переменная игрового времени, будем здесь хранить время игры 
	int gameTime = 0;//объявили игровое время, инициализировали.

	while (window.isOpen())
	{

		float time = clock.getElapsedTime().asMicroseconds();

		if (p.life) gameTime = gameTimeClock.getElapsedTime().asSeconds(); else { view.move(0.8, 0); }//игровое время в секундах идёт вперед, пока жив игрок, перезагружать как time его не надо. оно не обновляет логику игры
		clock.restart();
		time = time / 800;

		Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == Event::KeyPressed)//событие нажатия клавиши
				if ((event.key.code == Keyboard::Tab)) {//если клавиша ТАБ
					switch (showMissionText) {//переключатель, реагирующий на логическую переменную showMissionText
					case true: {
						std::ostringstream playerHealthString;//строка здоровья игрока
						playerHealthString << p.health; //заносим в строку здоровье 
						std::ostringstream task;//строка текста миссии
						task << getTextMission(getCurrentMission(1));//вызывается функция getTextMission (она возвращает текст миссии), которая принимает в качестве аргумента функцию getCurrentMission(возвращающую номер миссии), а уже эта ф-ция принимает в качестве аргумента функцию p.getplayercoordinateX() (эта ф-ция возвращает Икс координату игрока)
						text.setString("Здоровье: " + playerHealthString.str() + "\n" + task.str());//задаем
						//std::ostringstream 
						text.setPosition(view.getCenter().x + 125, view.getCenter().y - 130);//позиция всего этого текстового блока
						s_quest.setPosition(view.getCenter().x + 115, view.getCenter().y - 130);//позиция фона для блока
						showMissionText = false;//эта строка позволяет убрать все что мы вывели на экране
						break;//выходим , чтобы не выполнить условие "false" (которое ниже)
					}
					case false: {
						text.setString("");//если не нажата клавиша таб, то весь этот текст пустой
						showMissionText = true;// а эта строка позволяет снова нажать клавишу таб и получить вывод на экран
						break;
					}
					}
				}
			if (Keyboard::isKeyPressed(Keyboard::T)) { return true; }
			if (Keyboard::isKeyPressed(Keyboard::Escape)) { return false; }
			if ((event.key.code == Keyboard::E))
			{
				window.close();
			}
			if ((event.key.code == Keyboard::F))
			{
				p.finish_line = true;
			}

		}



		///////////////////////////////////////////Управление персонажем с анимацией////////////////////////////////////////////////////////////////////////
		if (p.life) {
			if (Keyboard::isKeyPressed(Keyboard::Left)) {
				p.dir = 1; p.speed = 0.1;
				currentFrame += 0.005 * time;
				if (currentFrame > 3) currentFrame -= 3;
				p.sprite.setTextureRect(IntRect(32 * int(currentFrame), 32, 32, 32));

			}

			if (Keyboard::isKeyPressed(Keyboard::Right)) {
				p.dir = 0; p.speed = 0.1;
				currentFrame += 0.005 * time;
				if (currentFrame > 3) currentFrame -= 3;
				p.sprite.setTextureRect(IntRect(32 * int(currentFrame), 64, 32, 32));

			}

			if (Keyboard::isKeyPressed(Keyboard::Up)) {
				p.dir = 3; p.speed = 0.1;
				currentFrame += 0.005 * time;
				if (currentFrame > 3) currentFrame -= 3;
				p.sprite.setTextureRect(IntRect(32 * int(currentFrame), 96, 32, 32));

			}

			if (Keyboard::isKeyPressed(Keyboard::Down)) {
				p.dir = 2; p.speed = 0.1;
				currentFrame += 0.005 * time;
				if (currentFrame > 3) currentFrame -= 3;
				p.sprite.setTextureRect(IntRect(32 * int(currentFrame), 0, 32, 32));
			}
			GetPlayerCoordinateForView(p.getplayercoordinateX(), p.getplayercoordinateY());
		}



		if (p.finish_line)
		{
			//window.close();
			finish_menu(window);
			return true;
		}
		if (!p.life)
		{
			return true;
			choose_menu();

		}


		p.update(time);

		window.setView(view);
		window.clear();


		/////////////////////////////Рисуем карту/////////////////////
		for (int i = 0; i < HEIGHT_MAP; i++)
			for (int j = 0; j < WIDTH_MAP; j++)
			{
				if (TileMap[i][j] == ' ')  s_map.setTextureRect(IntRect(0, 0, 32, 32));
				if (TileMap[i][j] == 's')  s_map.setTextureRect(IntRect(32, 0, 32, 32));
				if ((TileMap[i][j] == '0')) s_map.setTextureRect(IntRect(64, 0, 32, 32));
				if ((TileMap[i][j] == 'f')) s_map.setTextureRect(IntRect(96, 0, 32, 32));//добавили цветок
				if ((TileMap[i][j] == 'h')) s_map.setTextureRect(IntRect(128, 0, 32, 32));//и сердечко
				if ((TileMap[i][j] == 'w')) s_map.setTextureRect(IntRect(160, 0, 32, 32));
				s_map.setPosition(j * 32, i * 32);


				window.draw(s_map);

				if (!showMissionText) {
					text.setPosition(view.getCenter().x, view.getCenter().y - 130);//позиция всего этого текстового блока
					s_quest.setPosition(view.getCenter().x, view.getCenter().y - 130);//позиция фона для блока			
					window.draw(s_quest); window.draw(text); //рисуем спрайт свитка (фон для текста миссии). а затем и текст. все это завязано на логическую переменную, которая меняет свое состояние от нажатия клавиши ТАБ
				}
				window.draw(p.sprite);
			}

		window.display();

	}
}

void GameRunning()
{
	if (startGame())
	{
		GameRunning();
	}
}

int main()
{
	GameRunning();
	return 0;
}