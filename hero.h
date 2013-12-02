#ifndef _HERO_H
#define _HERO_H
#include "block.h"

class hero
{
public:
	int l, r, b, t, lives;
	bool inportal;
	sf::Sprite sprite;

	hero (screen &scrn): l (10), r(50), b(370), t(410), lives (2), inportal(false) 
	{	
		scrn.arr[calculateIndex(b)][calculateIndex (l)] = 1;
	}

	void Damaged()
	{
		lives --;
	}
	void MoveL (screen &scrn, portal& quit)
	{
		
		if ( scrn.arr[calculateIndex(b)][calculateIndex (l - step)] == 3 )
		{
			youLose(scrn);
			Damaged();
		}
		else
			if ( scrn.arr[calculateIndex(b)][calculateIndex (l - step)] == 0 )
			{
				scrn.arr[calculateIndex(b)][calculateIndex (l)] = 0;
				l -= step;
				r -= step;
				scrn.arr[calculateIndex(b)][calculateIndex (l)] = 1; 
			}
			else 
				if (scrn.arr[calculateIndex(b)][calculateIndex (l - step)] == 6 && quit.up == true)
				{
					inportal = true;
				}
	}
	void MoveR (screen &scrn, portal& quit)
	{
		if ( scrn.arr[calculateIndex(b)][calculateIndex (l + step)] == 3 )
		{
			youLose(scrn);
			Damaged();
		}
		else
		{
			if (scrn.arr[calculateIndex(b)][calculateIndex (l + step)] == 0)
			{
				scrn.arr[calculateIndex(b)][calculateIndex (l)] = 0;
				l += step;
				r += step;
				scrn.arr[calculateIndex(b)][calculateIndex (l)] = 1; 
			}
			else 
				if (scrn.arr[calculateIndex(b)][calculateIndex (l + step)] == 6 && quit.up==true)
				{
					inportal = true;
				}
		}
	}
	void MoveU (screen &scrn, portal& quit)
	{
		if ( scrn.arr[calculateIndex(b - step)][calculateIndex (l)] == 3 )
		{
			youLose(scrn);
			Damaged();
		}
		else
		{
			if (scrn.arr[calculateIndex(b - step)][calculateIndex (l)] == 0 )
			{
				scrn.arr[calculateIndex(b)][calculateIndex (l)] = 0;
				b -= step;
				t -= step;
				scrn.arr[calculateIndex(b)][calculateIndex (l)] = 1; 
			}
			else 
				if (scrn.arr[calculateIndex(b -step)][calculateIndex (l)] == 6 && quit.up==true)
				{
					inportal = true;
				}
		}
	}
	void MoveD (screen &scrn, portal& quit)
	{
		if ( scrn.arr[calculateIndex(b + step)][calculateIndex (l)] == 3 )
		{
			youLose(scrn);
			Damaged();
		}
		else
		{
			if (scrn.arr[calculateIndex(b + step)][calculateIndex (l)] == 0)
			{
				scrn.arr[calculateIndex(b)][calculateIndex (l)] = 0;
				b += step;
				t += step;
				scrn.arr[calculateIndex(b)][calculateIndex (l)] = 1; 
			}
			else 
				if (scrn.arr[calculateIndex(b + step)][calculateIndex (l)] == 6 && quit.up==true)
				{
					inportal = true;
				}
		}
	}

};

#endif