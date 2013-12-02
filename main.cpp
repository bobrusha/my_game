#include <vector>
#include <list>

#include "bomb.h"
#include "block.h"
using namespace std;

//global variables------
int wW = 540, wH = 460;
int border = 20;
int maxsteps = ((wW - border)/ step);

unsigned int textures[30];
unsigned int NUM_LVL = 0;
//---------------------
//MENU


//--------------------
//game's objects

screen scrn;

list <enemy> enemies;
list <brick> bricks;
list <bomb> bombs;

hero Main (scrn);
portal lvlup ( 0, 0, 0, 0, scrn);

list <enemy>::iterator pos;

//-----------------------
int calculateCoordinates (int x)
{
		x *= step;
        x += 10;
		return x;
}
//-----------------------

int lvls[2][13][15] =
{
	{
		{ 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 2, 2, 2, 0 },
		{ 4, 0, 0, 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 0, 4 },
		{ 4, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 2, 0, 2, 3, 2, 0, 2, 0, 0, 4 },
		{ 4, 0, 2, 2, 0, 2, 2, 0, 0, 2, 0, 0, 0, 0, 4 },
		{ 4, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 4 },
		{ 4, 2, 0, 0, 2, 0, 2, 0, 2, 2, 0, 0, 2, 2, 4 },
		{ 4, 2, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 4 },
		{ 4, 2, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 3, 2, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0, 4 },
		{ 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4 }
	},
	{
		{ 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4 },
		{ 4, 0, 2, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 4 },
		{ 4, 0, 0, 0, 2, 0, 0, 2, 0, 0, 2, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 2, 0, 0, 2, 0, 0, 2, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 2, 0, 0, 4 },
		{ 4, 0, 0, 0, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 2, 4 },
		{ 4, 0, 0, 2, 0, 0, 3, 2, 0, 0, 2, 2, 0, 0, 4 },
		{ 4, 0, 0, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 2, 2, 0, 0, 0, 2, 2, 2, 0, 0, 3, 4 },
		{ 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4 }
	}
};

void createLevel ()
{
        scrn.clearScreen();
		bricks.clear();
		enemies.clear();

		for (int i = 0; i < 13; i++)
		{
			for (int j = 0; j < 15; j++)
			{
				switch ( lvls[NUM_LVL][i][j])
				{
					case 2:
					{
						bricks.push_back(brick (calculateCoordinates(j - 1), calculateCoordinates(j), calculateCoordinates(i-1), calculateCoordinates(i), scrn));
					}
					break;
					case 3:
					{
						enemies.push_back(enemy (calculateCoordinates(j - 1), calculateCoordinates(j), calculateCoordinates(i-1), calculateCoordinates(i), scrn));
					}
					break;
				}
			}
		}
		cout<<"I created level"<<endl;
		//lvlup = portal (10, 50, 10, 50, scrn);
		Main = hero (scrn);
		cout<<bricks.size();
}

void levelUp()
{
	++NUM_LVL;
	createLevel();
}
/*
void boom (int);
void enemyMotion(int);
*/
//-----------------------------------
void keyboardFunc()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		Main.MoveL(scrn, lvlup);
			
	}
	else
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			std::cout<<"I'm right!"<<std::endl;
			Main.MoveR(scrn, lvlup);
		}
		else 
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				Main.MoveD(scrn, lvlup);
			}
			else 
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				{
					std::cout<<"I'm Down!"<<std::endl;
					Main.MoveU(scrn, lvlup);
		
				}
				else
				{
					//std::cout<<"I'm i last else!!"<<std::endl;
				}
}

void bomb::damage()
{
	if (scrn.arr[calculateIndex(b)][calculateIndex(l)+1] != 4)
	{
		for (int i=0; i <= dst; ++i)
		{
			if (scrn.arr[calculateIndex(b)][calculateIndex(l)+i] == 2)
			{
				bricks.remove(brick(l+i*step, r+(i*step), b, t, scrn));
				scrn.arr[calculateIndex(b)][calculateIndex(l)+i] = 0;
				break;
			}
			if (scrn.arr[calculateIndex(b)][calculateIndex(l)+i] == 3)
			{
				enemies.remove( enemy ( l + i*step, r + i*step, b, t, scrn) );
				scrn.arr[calculateIndex(b)][calculateIndex(l)+i] = 0;
			}
		}
	}
	if (scrn.arr[calculateIndex(b)][calculateIndex(l)-1] != 4)
	{
		for (int i=0; i <= dst; ++i)
		{
			if (scrn.arr[calculateIndex(b)][calculateIndex(l) - i] == 2)
			{
				std::cout<<calculateIndex(l) - i<<" "<<r - i*step<<std::endl;

				bricks.remove(brick( l - i*step, r - i*step, b, t, scrn));
				scrn.arr[calculateIndex(b)][calculateIndex(l) - i] = 0;
				break;
			}
			if (scrn.arr[calculateIndex(b)][calculateIndex(l)-i - 1] == 3)
			{
				enemies.remove( enemy (l-i*step, r-i*step, b, t, scrn) );
				scrn.arr[calculateIndex(b)][calculateIndex(l)- i - 1] = 0;
			}
		}
	}
	if (scrn.arr[calculateIndex(b)+1][calculateIndex(l)] != 4)
	{
		for (int i=0; i <= dst; ++i)
		{
			if (scrn.arr[calculateIndex(b)+i][calculateIndex(l)] == 2)
			{
				bricks.remove(brick(l, r, b+i*step, t+i*step, scrn));
				scrn.arr[calculateIndex(b)+i][calculateIndex(l)] = 0;
				break;
			}
			if (scrn.arr[calculateIndex(b)+i][calculateIndex(l)] == 3)
			{
				enemies.remove( enemy (l, r, b+i*step, t+i*step, scrn) );
				scrn.arr[calculateIndex(b)+i][calculateIndex(l)] = 0;
			}
		}
	}
	if (scrn.arr[calculateIndex(b)-1][calculateIndex(l)] != 4)
	{
		for (int i = 0; i <= dst; i++)
		{
			if (scrn.arr[calculateIndex(b)-i][calculateIndex(l)] == 2)
			{
				bricks.remove(brick (l, r, b-i*step, t-i*step, scrn));
				scrn.arr[calculateIndex(b)-i][calculateIndex(l)] = 0;
				break;
			}
			if (scrn.arr[calculateIndex(b)-i][calculateIndex(l)] == 3)
			{
				enemies.remove(enemy (l, r, b-i*step, t-i*step, scrn));
				scrn.arr[calculateIndex(b)-i][calculateIndex(l)] = 0;
			}
		}
	}
}
int main ( int argc, char** argv)
{

	sf::RenderWindow window(sf::VideoMode(wW, wH), "SFML works!");
	
	sf::Clock clock; // starts the clock
	

	createLevel();
	NUM_LVL=0;

	sf::Texture texMainHero;
	texMainHero.loadFromFile("main_hero.png");
	sf::Sprite sprMainHero;
	sprMainHero.setTexture(texMainHero);

	sf::Texture texBrick;
	texBrick.loadFromFile("brick.png");
	sf::Sprite sprBrick;
	sprBrick.setTexture(texBrick);

	sf::Texture texEnemy;
	texEnemy.loadFromFile("enemy.png");
	sf::Sprite sprEnemy;
	sprEnemy.setTexture(texEnemy);

	sf::Texture texBomb;
	texBomb.loadFromFile("bomb.png");
	sf::Sprite sprBomb;
	sprBomb.setTexture(texBomb);

	while (true/*window.isOpen()*/)
    {
     
		sf::Event event;

        while (window.pollEvent(event))
        {
			switch(event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				{
					std::cout<<"i'm here!"<<std::endl;
					switch (event.key.code)
					{
					case (sf::Keyboard::Left):
						Main.MoveL(scrn, lvlup);
						break;
					case (sf::Keyboard::Right):
						Main.MoveR(scrn, lvlup);
						std::cout<<"i'm in right!"<<endl;
						break;
					case (sf::Keyboard::Up):
						Main.MoveU(scrn, lvlup);
						break;
					case (sf::Keyboard::Down):
						Main.MoveD(scrn, lvlup);
						break;
					}
				break;
				}
			}
			//------------------------------
		
        }
			window.clear(sf::Color::White);
			if (scrn.run)
			{
				if (! bricks.empty())
				{
					for (list<brick>::iterator i = bricks.begin(); i != bricks.end(); ++i)
					{
						sprBrick.setPosition(sf::Vector2f(i->l, i->b));
						window.draw(sprBrick);
					}
				}
				if (! enemies.empty())
				{
					for (list<enemy>::iterator i = enemies.begin(); i != enemies.end(); ++i)
					{
						sprEnemy.setPosition(sf::Vector2f(i->l, i->b));
						window.draw(sprEnemy);
					}
				}
				if ( !bombs.empty())
				{
					for (list<bomb>::iterator i = bombs.begin(); i != bombs.end(); ++i)
					{
						sprBomb.setPosition(sf::Vector2f(i->l, i->b));
						window.draw(sprBomb);
					}
				}
	
				if ( enemies.empty() && Main.b == lvlup.b && Main.r ==lvlup.r)
				{
					levelUp();
				}
			}
			else
			{
				bricks.clear();
				bombs.clear();
				enemies.clear();
				scrn.clearScreen();
			}

			sprMainHero.setPosition(sf::Vector2f(Main.l, Main.b));
			window.draw(sprMainHero);
			window.display();
    }//while (window.isOpen())

    return 0;

}