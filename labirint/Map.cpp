#include <SFML/Graphics.hpp>
#include "Player.h"
const int HEIGHT_MAP = 29;
const int WIDTH_MAP = 56;

sf::String TileMap[HEIGHT_MAP] = {
	"00000000000000000000000000000000000000000000000000000000",
	"0                  ss        ss            ss          0",
	"0  ssssss  ssssss  ss  ssssssssssssssssss      s    s  0",
	"0  ss          ss  ss  ss              ss      ss  ss  0",
	"0  ss  ssssss  ss  s   ss  ssssss  ssssss  ss  ss  ss  0",
	"0  ss  ssf     ss      ssfhss  ssh         ss  ss      0",
	"0  ss  ss  s  fssssss  s   ss  ssssss  ssssss  sssss   0",
	"0  ss      ss      ss      ss              ss  ss      0",
	"0ssss      ssssssssssssss  ssssssssssssssssss  ss  s   0",
	"0      ss      ss  ss  ss          ss          ss  ss  0",
	"0  ssssssssssssss  ss  ssssss   s  ssfhssssssssssssss  0",
	"0              ss  ss      ss  ss  ss      ss  ss      0",
	"0ssssssssssss   s  s    s  ssssss  ssssss  s   ss  ssss0",
	"0          ss          ss              ss              0",
	"0  ssssss  ss  ssssss  ss       sssssssss  s   ssssss  0",
	"0          ss  ss  sshfss      ss          ss  ss      0",
	"0sss   ss  ss  ss  s   ss      ss  ssssssssssssss   sss0",
	"0  ss  ss      ss      ss      ss              ss      0",
	"0  ssssss  ssssssssss  ssssss  ssssssssssssss  s   ss  0",
	"0      ss      ss   f      ss              ss      ss  0",
	"0ssss  ssssssssss  ssssss  ssssss  ssssssssssssss   sss0",
	"0  ss  f           ss  ss     h     f  ss              0",
	"0  ss  ssssss  ssssss  ssssssssssssss  ss  ssssss   sss0",
	"0  ss  ss      ss      ss      h       ss  ss  ss  ss  0",
	"0  ss  ss  ssssss  sf  ssssss  ssssssssss  ss  ss  ss  0",
	"0      ss  ss      ss       f                  ss  ss  0",
	"0    ssss  ssssssssssssssssssssssssssssssssss  ss  ss  0",
	"0      ss    h                 ss              ss      0",
	"00000000000000000000000000000ww0000000000000000000000000",
};

void interactionWithMap()
{

	for (int i = y / 32; i < (y + h) / 32; i++)
		for (int j = x / 32; j < (x + w) / 32; j++)
		{
			if (TileMap[i][j] == '0')
			{
				if (dy > 0)
				{
					y = i * 32 - w;
				}
				if (dy < 0)
				{
					if (y > 32)
					{
						y = i * 32 - h;
					}
					else
					{
						y = 32;
					}
				}
				if (dx > 0)
				{
					x = j * 32 - h;
				}
				if (dx < 0)
				{
					if (x > 32)
					{
						x = j * 32 + 32;
					}
					else
					{
						x = 32;
					}
				}
			}

			if (TileMap[i][j] == 's') {

				if (dy > 0)
				{
					y = i * 32 - w;
					//y = i * 32 - 16;
				}
				if (dy < 0)
				{
					if (y > 32)
					{
						y = i * 32 + h;
						//y = i * 32 + 16;
					}

				}
				if (dx > 0)
				{
					x = j * 32 - h;
					//x = j * 32 - 16;
				}
				if (dx < 0)
				{
					if (x > 32)
					{
						x = j * 32 + 32;
						//x = j * 32 + 16;
					}

				}

			}

			if (TileMap[i][j] == 'f') {
				health -= 40;//если взяли ядовитейший в мире цветок,то переменная health=health-40;
				TileMap[i][j] = ' ';//убрали цветок
			}

			if (TileMap[i][j] == 'h') {
				health += 20;//если взяли сердечко,то переменная health=health+20;
				TileMap[i][j] = ' ';//убрали сердечко
			}
			if (TileMap[i][j] == 'w')
			{

				finish_line = true;
			}
		}
}