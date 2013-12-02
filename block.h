#ifndef _BLOCK_H_
#define _BLOCK_H_
#include "screen.h"

class brick
{
public:
	int l, r, b, t;
	sf::Sprite sprite;

	brick (int _l,int _r, int _b, int _t, screen& scrn): l(_l), r(_r), b(_b), t(_t)
	{
		sf::Texture texture;
		texture.loadFromFile("brick.png");
		sprite.setTexture(texture);
		sprite.setPosition(sf::Vector2f(l, b));

		scrn.arr[calculateIndex(b)][calculateIndex (l)] = 2;
    }
};

bool operator == (const brick& b1, const brick& b2)
{
        if ( b1.b == b2.b && b1.l == b2.l && b1.t == b2.t && b1.r == b2.r)
                return true;
        else 
                return false;
}
class portal
{
public:
	int l, r, b, t;
	bool up;
	portal(): l(0), r(0), b(0), t(0), up(false){}
	portal (int _l, int _r, int _b, int _t, screen& scrn):l(_l), r(_r), b(_b), t(_t), up(false)
	{
		//scrn.arr[calculateIndex(b)][calculateIndex(l)] = 6;
	}
};

class beaton
{
        int l, r, b, t;
public:
	beaton (int _l,int _r, int _b, int _t, screen& scrn): l(_l), r(_r), b(_b), t(_t)
	{
		scrn.arr[calculateIndex (l)][calculateIndex(b)] = 4;
	}
};

#endif