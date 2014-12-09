#include <stdio.h>
#include <math.h>
#include <time.h>
#include "gfx3.h"

void background();
void bucket(int, int);

int main(){
	
	char c;
	int velocity, xc, yc;
	int r = 200;
	float dTime, dTheta, dPhi=M_PI/4, ax, ay, bx, by, omega ,dOmega;
	int width = 700, height = 600;
	time_t t;
	srand((unsigned)time(&t));

	gfx_open(width, height, "Rotate.c");
	xc = (width/2);
	yc = (height/2);
	dTime = .01;
	velocity = .5;
	omega = velocity/r;
	dOmega = omega*dTime;
	gfx_color(rand()%255,rand()%255,rand()%255);

	printf("This is my Ferris Wheel program. Press w to increase the speed and press s to decrease your speed.\n");
	printf("Please keep your hands and feet inside the ride at all times, enjoy!\n");

	while(c != 'q'){
		gfx_clear();
		background();
		for (dTheta = dPhi; dTheta <= (2*M_PI)+dPhi; dTheta += M_PI/4){
			ax = xc;
			ay = yc;
			bx = xc + 200*cos(dTheta);
			by = yc + 200*sin(dTheta);
			gfx_line(ax, ay, bx, by);
			bucket(bx, by);
		}
		dPhi += .017453*dOmega;
		gfx_flush;
		usleep(15000);
		if(gfx_event_waiting()){
			c = gfx_wait();
			switch(c){
				case 'w':
					dOmega+= .017453;
				break;
				
				case 's':
					dOmega-= .017453;
				break;
	
			}
		}
	}



}


void background(){

        int width = 700, height = 600;
        int xc, yc;
        xc = (width/2);
        yc = (height/2);
//        gfx_color(rand()%255,rand()%255,rand()%255);

	gfx_circle((width/2), (height/2), 200);
        gfx_line(xc,yc, (width/2)+50, 600);
        gfx_line(xc,yc, (width/2)-50, 600);
        gfx_line(0,600, 700, 600);

}

void bucket(int xStart, int yStart){
	int width = 700, height = 600;

	gfx_line(xStart,yStart,xStart-15,yStart+25);
	gfx_line(xStart-15,yStart+25,xStart+15,yStart+25);
	gfx_line(xStart+15,yStart+25,xStart,yStart);
	gfx_line(xStart-15,yStart+25,xStart-15,yStart+55);
	gfx_line(xStart-15,yStart+55,xStart+15,yStart+55);
	gfx_line(xStart+15,yStart+55,xStart+15,yStart+25);
}
