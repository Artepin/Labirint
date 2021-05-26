#include <SFML\Graphics.hpp>

using namespace sf;

void Message()
{
Image quest_image;
quest_image.loadFromFile("images/missionbg.jpg");
quest_image.createMaskFromColor(Color(0, 0, 0));
Texture quest_texture;
quest_texture.loadFromImage(quest_image);
Sprite s_quest;
s_quest.setTexture(quest_texture);
s_quest.setTextureRect(IntRect(0, 0, 340, 510));  //приведение типов, размеры картинки исходные
s_quest.setScale(0.6f, 0.6f);//чуть уменьшили картинку, => размер стал меньше

}