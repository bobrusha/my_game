#ifndef _SCREEN_H_
#define _SCREEN_H_
#include <list>
//#include "bomb.h"
#include "texture.h"

using namespace std;

int step = 40;
int calculateIndex (int x)
{
	x += (step - 10);
	x /= step;
	return x;
}

class screen
{
public:
	
	int arr [13][15];
	bool run;
	//int w, h;
	// 0 - free
	// 1 - hero
	// 2 - obj
	// 3 - enemy
	// 4 - beaton
	// 5 - bonus
	// 6 - exit


	void clearScreen()
	{
		for (int i = 2; i < 12; i++)
			for ( int j=0; j<14; j++)
				arr[i][j] = 0;
		
		for (int i = 0; i < 12; i++)
			arr[i][0] = 4;
		
		for (int i = 0; i < 12; i++)
			arr[i][14] = 4;
		
		for (int i = 0; i < 12; i++)
			arr[0][i] = 4;
		for (int i = 0; i < 12; i++)
			arr[12][i] = 4;
		run = true;
	}

	screen ()
	{
		clearScreen();
	}

	void Draw(int w, int h, unsigned int texture)
	{
	}
};
#endif