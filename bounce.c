#include <stdio.h>
#include <math.h>
#include <time.h>
#include "gfx3.h"

int main(){

	/*************definition of variables************/

	char c=1;
	int vx, vy;
	int xc, yc, r, dx, dy;
	float dt;
	int width = 700, height = 500;
	time_t t;
	srand((unsigned)time(&t));

	/*************initialization of parameters*******/

	gfx_open(width, height, "Bounce.c");
	vx = rand()%10-5;		//sets random velocity from -5 to 5 units
	vy = rand()%10-5;		//set velocity to random number from -5 to 5.
	dt = .01;			//change in time
	dx = vx*dt;			//x direction displacement
	dy = vy*dt;			//y direction displacement
	r = 20;
	xc = rand()%700; yc = rand()%500;	//sets circle to random part of screen

	gfx_color(0, 255,255);

	while(c != 'q'){
		gfx_clear();
		gfx_circle(xc+dx,yc+dy, r);
		gfx_flush;
		dx+= vx;		//updates dx by vx units
		dy+= vy;		//updates dy by vy units
		usleep(10000);
		if(gfx_event_waiting()){
			c = gfx_wait();
			if (c == 1) {
				vx = rand()%10-5;	//sets new random velocty on click
				vy = rand()%10-5;	//sets new random velocity on click
				xc = gfx_xpos();	//gets x pos. to draw new circle
				yc = gfx_ypos();	//gets y pos. to draw new circle
				dx = 0; dy = 0;		//resets dx and dy (keeps from offset on redraw)
			}
		}
		if(xc + dx > width - r){
			vx *= -1;			//detects right edge
		}
		if(xc + dx < r){
			vx *= -1;			//detects left edge
		}
		if(yc + dy > r){
			vy *= -1;			//detects bottom edge
		}
		if(yc + dy < height - r){
			vy *= -1;			//detects top edge
		}
	}
}
