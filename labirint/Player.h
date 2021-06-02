#include <SFML\Graphics.hpp>

using namespace sf;

class Player
{
private:

	String File;
	Image image;
	Texture texture;

public:
	Sprite sprite;
	static int dir;
	float x, y, w, h, speed, dx, dy;
	int health;
	bool life;
	void update(float time);
	bool finish_line = false;

	Player(String F, float x, float y, float w, float h);
	float getplayercoordinateX();
	float getplayercoordinateY();
	void update(float time);
	void interactionWithMap();
};