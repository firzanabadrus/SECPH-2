// ? EXERCISE 5: POLYMORPHISM

// Programming Technique II
// Semester 2, 2023/2024

// Section: 01
// Member 1's Name: LUBNA AL HAANI BINTI RADZUAN       Location: UTM (i.e. where are you currently located)
// Member 2's Name: NUR FIRZANA BINTI BADRUS HISHAM    Location: UTM

// Log the time(s) your pair programming sessions
//  Date         Time (From)   To             Duration (in minutes)
//  23/06/2024    21:27		   21:40          13.11


// Video link:
//  https://drive.google.com/file/d/1fucnCddka887xRei3jkzgF8GK4LeQ5SL/view?usp=sharing 



#include <graphics.h>
#include <cmath>
#include <stdlib.h>
#include <time.h>

#include "shape.hpp"
#include "circle.hpp"
#include "rect.hpp"

using namespace std;

// ? Notes: Choose the debug mode "Multi-File Graphic Project" to run this program.

// You may change the max size of the list
#define COUNT 5


Shape *shapes[COUNT];
Shape *selectedShape = nullptr;

void generateListOfShapes( int width, int height)
{
	for(int i = 0; i < COUNT; i++)
	{
		int side = rand() % 2;
		int x = 1 + rand() % width;
		int y = 1 + rand() % height;

		if (side == 0)
		{	
			int r = 50 + rand() % 300;
			shapes[i] = new Circle(x, y, r);
		}
		else
		{	
			int w = 50 + rand() % 200;
			int h = 50 + rand() % 200;
			shapes[i] = new Rect(x, y, w, h);
		}
	}
}

void processMouseClick()
{
	int mx, my;

	if (ismouseclick(WM_LBUTTONDOWN))
	{
		// capture the mouse location (mx,my)
		getmouseclick(WM_LBUTTONDOWN, mx, my);

		// test the location (mx,my) all over the shapes
		// find to which shape the mouse clicks on (s)
		for(int i = 0; i < COUNT; i++)
		{
			if( shapes[i]->isMouseClick(mx,my) ){

				if (selectedShape != nullptr)
					selectedShape->toggleSelected();
				
				selectedShape = (selectedShape == shapes[i]) ? nullptr : shapes[i];

				if(selectedShape)
					selectedShape->toggleSelected();
				break;
			}

		}

		// selected = s
	}
}

int main()
{
	int width = getmaxwidth();
	int height = getmaxheight();
	initwindow(width, height, "Exercise 5");

	/* initialize random seed: */
	srand(time(NULL));
	generateListOfShapes(width, height);

	for(int i = 0; i < COUNT; i++)
	{
		shapes[i]->draw();
	}

	char ch = 0;

	while (ch != 27)  // 27 is ESC key
	{
		if (kbhit())
		{
			ch = getch();
			switch (toupper(ch))
			{
			case '+':
				if(selectedShape)
					selectedShape->resize(1.1); 
				break;

			case '-': 
				if(selectedShape)
					selectedShape->resize(0.9);
				break;

			case KEY_LEFT:
				if(selectedShape) //if(selectedShape != nullptr)
					selectedShape->move(-10, 0);
				break;

			case KEY_RIGHT:
				if(selectedShape)
					selectedShape->move(10,0);
				break;

			case KEY_UP:
				if(selectedShape)
					selectedShape->move(0,-10);
				break;

			case KEY_DOWN:
				if(selectedShape)
					selectedShape-> move(0, 10);
				break;
			}
		}

		processMouseClick();
		
	}

	system("pause");
	return 0;
}
