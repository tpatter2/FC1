#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include "gfx3.h"

int width = 800, height = 800;
float phi = M_PI/2, dPhi = M_PI/2, dP;
void draw_slider(int, int, float);
int draw_pendulum(int, int, float);
int circle_rotation(float, float);
void rotation2 (float,float);

int main(){
	char c;
	int dx = 5, angle = 90;
	int x = width/2;
	int y = 80;
	int max_X = width*.9, min_X = width*.1;
	float theta = 0;
	gfx_open(width, height, "Carnival.c");
	while(c != 'q'){
		while(1){
			gfx_clear();
			usleep(60000);		//slows animation enough to see
			draw_slider(x, y, theta);
			x+= dx;
			theta += (M_PI/(angle));
			gfx_flush();
			if(theta >= (M_PI) || theta <= 0){
				angle *= -1;	//if the pendulum reaches 							//either end, then cause the 							//pendulum to switch direction
			}
			if(x>= max_X || x <= min_X){
				dx *=-1;	//change slider direction
			}
			if(gfx_event_waiting()){
				c = gfx_wait();
			}
			if(c == 'q'){
				return 0;
			}
		}
	}
}

void draw_slider(int x,int y, float theta){
	int xMin = width*.1, xMax = width *.9, r = 5;
	gfx_color (255,0,0);
	gfx_line(xMin, y, xMax, y);		//draws line for slider
	gfx_color (255,255,0);
	gfx_circle(x, y, r);			//circle indicating slider 							//movement

	draw_pendulum(x, y, theta);		//calls pendulum fxn
}

int draw_pendulum (int x, int y, float theta){
	float bx, by;
	bx = x + 400*cos(theta);
	by = y + 400*sin(theta);
	gfx_color(0,255,0);
	gfx_line(x, y, bx, by);			//draws pendulum line
	circle_rotation (bx, by);		//calls rotation fxn
}

int circle_rotation (float x, float y){
	float bx, by;
	for (phi = dPhi; phi < 2*M_PI+dPhi; phi += M_PI/4){
		bx = x + 100*cos(phi);
		by = y + 100*sin(phi);
		gfx_color(0,0,255);
		gfx_line(x,y, bx, by);		//fxn for rotating arms
		phi += M_PI/4;
		gfx_color(225,0,225);
		gfx_circle (bx, by, 30);
		rotation2(bx,by);
	}
	dPhi += M_PI/10;
//	rotation2(bx,by);
}

void rotation2(float x, float y){
	float ax,ay,bx, by;
	float a,b,c,d;
	float del = M_PI/4;
	a = x+30*cos(phi);
	b = y+30*sin(phi);
	c = x+100*cos(phi);
	d = y+100*sin(phi);
	gfx_line (a, b, c, d);
	for(dP = M_PI/4; dP <= 2*M_PI+1; dP += (2*M_PI)/4){
		ax = c;
		ay = d; 
		bx = c + 30*cos(dP);
		by = d + 30*sin(dP);		//rotates objects around 							//circles
		gfx_line(ax, ay, bx, by);
		phi = dP;
	}
}
