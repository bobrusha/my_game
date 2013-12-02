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
		lvlup = portal (10, 50, 410, 450, scrn);
		Main = hero (scrn);
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

list <list<bomb>::iterator> lst_iter;

void youWin (sf::Text & txt,sf::Font & font)
{
	txt.setFont(font); // font is a sf::Font

				// set the string to display
	txt.setString("You Win");
	txt.setColor(sf::Color::Black);
	txt.setPosition(100,100);
	txt.setCharacterSize(72);
}

int main ( int argc, char** argv)
{

	sf::RenderWindow window(sf::VideoMode(wW, wH), "SFML works!");
	
	sf::Clock clock; // starts the clock
	

	createLevel();

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

	sf::Texture texPortal;
	texPortal.loadFromFile("portal.png");
	sf::Sprite sprPortal;
	sprPortal.setTexture(texPortal);

	sf::Font font;
	if (!font.loadFromFile("font.ttf"))
	{
		return 3;
   	}

	bool lvl_is_completed = false;

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
			//========================================================================================= Keyboard
			case sf::Event::KeyPressed:
				{
					switch (event.key.code)
					{
					case (sf::Keyboard::Left):
						Main.MoveL(scrn, lvlup);
						break;
					case (sf::Keyboard::Right):
						Main.MoveR(scrn, lvlup);
						break;
					case (sf::Keyboard::Up):
						Main.MoveU(scrn, lvlup);
						break;
					case (sf::Keyboard::Down):
						Main.MoveD(scrn, lvlup);
						break;
					case (sf::Keyboard::Space):
						bombs.push_back(bomb (Main.l, Main.r, Main.b, Main.t));
						break;
					case (sf::Keyboard::E):
						{
							scrn.print();
						}
						break;
					case (sf::Keyboard::A):
					{
						//NUM_LVL++;
						enemies.clear();
					}
					break;

					}
					break;
				}
			}//end of switch 
		}
			window.clear(sf::Color::White);

			if (scrn.run == true)
			{
				sprPortal.setPosition(sf::Vector2f(lvlup.l, lvlup.b));
				window.draw(sprPortal);

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

					sf::Time elapsed1 = clock.getElapsedTime();

					if (elapsed1.asSeconds() >= 0.5f)
					{
						for (list<enemy>::iterator i = enemies.begin(); i != enemies.end(); ++i)
						{
							
							i->motion(scrn, Main);
						}
					sf::Time elapsed1 = clock.restart();
					}
					for (list<enemy>::iterator i = enemies.begin(); i != enemies.end(); ++i)
					{	
							sprEnemy.setPosition(sf::Vector2f(i->l, i->b));
							window.draw(sprEnemy);
					}
				}
				if ( !bombs.empty())
				{
					std::cout<<bombs.size()<<endl;
					for (list<bomb>::iterator i = bombs.begin(); i != bombs.end(); ++i)
					{
						sprBomb.setPosition(sf::Vector2f(i->l, i->b));

						if ( (i->clock).getElapsedTime().asSeconds() >= 3.0)
						{
							i->damage();
							lst_iter.push_back(i);
						}
						window.draw(sprBomb);
					}
				}
				sprMainHero.setPosition(sf::Vector2f(Main.l, Main.b));
				window.draw(sprMainHero);

				if ( enemies.empty() && Main.b == lvlup.b && Main.r ==lvlup.r)
				{
					if( NUM_LVL<= 2)
					{
						levelUp();
					}
					else
					{
						std::cout<<"I'm in else "<<std::endl;
						scrn.run = false; 
						std::cout<<scrn.run;
					}
				}
				std::cout<<scrn.run;
			}
			else
			{
				bricks.clear();
				bombs.clear();
				enemies.clear();
				scrn.clearScreen();
				scrn.run = false;

				sf::Text text;

				if(NUM_LVL > 2)
				{
					std::cout<<"NUM_LVL > 2"<<std::endl;
					youWin(text, font);
					window.draw(text);
				}
				else
				{
					text.setFont(font);

					text.setString("You lose");
					text.setColor(sf::Color::Black);
					text.setPosition(100,100);
					text.setCharacterSize(72); // in pixels, not points!
					window.draw(text);
				}
			}

			window.display();
			//std::cout<<bombs.size();
			if ( bombs.size() != 0)
			{ 
				std::cout<<bombs.size();
				for (list<list<bomb>::iterator>::iterator i = lst_iter.begin(); i != lst_iter.end(); ++i)
				{
					bombs.remove( *(*i));
				}
				lst_iter.clear();
			}

    }//while (window.isOpen())

    return 0;
}