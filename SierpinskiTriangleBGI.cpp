#include "graphics.h"
#include "conio.h"
#include "math.h"

#define screenY 480
#define screenX 640

//Draws an inverted triangle
void triangle(float x, float y, float h, int clr){
    setcolor(clr%16+1);
	int tri[]={
		x,				y+2*h/3,
		x-h/sqrt(3),	y-h/3, 
		x+h/sqrt(3),	y-h/3,
		x,				y+2*h/3
	};
	
    drawpoly(4, tri);
}

//Draws the frame triangle
void frame(){
	int tri[]={
		screenX/2,			0,
		screenX/16,			screenY, 
		15*screenX/16,		screenY,
		screenX/2,			0,
	};
	
    drawpoly(4, tri);
}

int draw(float x, float y, float h, int clr){
	//If the triangle is too small, it stops drawing
	if (h < 5) {return 0;}
	
	//Draw a triangle if x and y are inside the screen
    if (x > 0 && y > 0 && x < screenX && y < screenY) {triangle(x, y, h, clr);}
  
    draw(x, y-2 * h/3, h/2, clr+1); //Top triangle
    draw(x-h/sqrt(3), y+h /3, h/2, clr+1); //Left triangle
    draw(x+h/sqrt(3), y+h/3, h/2, clr+1); //Right triangle
  
    return 0;
}

int main(void){
	int gdriver = DETECT, gmode;
	initgraph(&gdriver, &gmode, "..\\BGI");
	
	frame();
    draw(screenX/2, 2*screenY/3, screenY/2, 0);
	
	getch();
	closegraph();
	return 0;
}
