
using namespace sf;

class Player
{
private:
	float x, y, w, h, speed, dx, dy;
	int health;
	
	bool life;
	String File;
	Image image;
	Texture texture;
	Sprite sprite;
public:
	static int dir;
	Player(float x, float y, float w, float h, float speed, int dir, float dx, float dy);
	void update(float time);
	void interactionWithMap();
};