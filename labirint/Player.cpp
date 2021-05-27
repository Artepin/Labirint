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
	
	Player(String F, float x, float y, float w, float h)
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
	float getplayercoordinateX() {
		return x;
	}
	float getplayercoordinateY() {
		return y;
	}

	void update(float time);
	void interactionWithMap();
};