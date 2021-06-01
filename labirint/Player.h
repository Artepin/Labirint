
using namespace sf;

class Player
{
private:
	
	String File;
	Image image;
	Texture texture;
	
public:
	Sprite sprite;
	float x, y, w, h, speed, dx, dy;
	int health;
	bool life;
	bool finish_line = false;
	static int dir;
	Player(String F, float x, float y, float w, float h);
	void update(float time);
	void interactionWithMap();
	float getplayercoordinateX();
	float getplayercoordinateY();
};