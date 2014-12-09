#include <stdio.h>
#include <math.h>
#include "gfx3.h"

int main(){
	char m;
	int x, y, r;
	float t, dt, ax, ay, bx, by;

	gfx_open(500, 400, "Symbol.c");

	while(m != 'q') {
	   m = gfx_wait();
	   switch(m){
		case 'c':
			x = gfx_xpos();
			y = gfx_ypos();
			gfx_color(255, 255, 255);
			gfx_circle(x, y, 20);
			gfx_flush;
		break;

		case 't':
			x = gfx_xpos();
                        y = gfx_ypos();
                        gfx_color(0, 255, 0);
                        r = 20;
                        t = 0;
                        for(dt = 0; dt <= 2*M_PI+1; dt += (2*M_PI)/3){
                                ax = x + r*cos(t);
                                ay = y + r*sin(t);
                                bx = x + r*cos(dt);
                                by = y + r*sin(dt);
                                gfx_line(ax, ay, bx, by);
                                t = dt;
                        }

		break;

		case 1:
			x = gfx_xpos();
                        y = gfx_ypos();
                        gfx_color(0, 0, 200);
                        r = 20;
                        t = 0;
                        for(dt = 0; dt <= 2*M_PI+1; dt += (2*M_PI)/4){
                                ax = x + r*cos(t);
                                ay = y + r*sin(t);
                                bx = x + r*cos(dt);
                                by = y + r*sin(dt);
                                gfx_line(ax, ay, bx, by);
                                t = dt;
                        }

		break;

		case '3':
			x = gfx_xpos();
			y = gfx_ypos();
			gfx_color(200, 0, 200);
			r = 20;
			t = 0;
			for(dt = 0; dt <= 2*M_PI+1; dt += (2*M_PI)/3){
				ax = x + r*cos(t);
				ay = y + r*sin(t);
				bx = x + r*cos(dt);
				by = y + r*sin(dt);
				gfx_line(ax, ay, bx, by);
				t = dt;
			}

		break;

		case '4':
			x = gfx_xpos();
                        y = gfx_ypos();
                        gfx_color(255, 0, 255);
                        r = 20;
                        t = 0;
                        for(dt = 0; dt <= 2*M_PI+1; dt += (2*M_PI)/4){
                                ax = x + r*cos(t);
                                ay = y + r*sin(t);
                                bx = x + r*cos(dt);
                                by = y + r*sin(dt);
                                gfx_line(ax, ay, bx, by);
				t = dt;
                        }
		break;

		case '5':
			x = gfx_xpos();
                        y = gfx_ypos();
                        gfx_color(255, 0, 255);
                        r = 20;
                        t = 0;
                        for(dt = 0; dt <= 2*M_PI+1; dt += (2*M_PI)/5){
                                ax = x + r*cos(t);
                                ay = y + r*sin(t);
                                bx = x + r*cos(dt);
                                by = y + r*sin(dt);
                                gfx_line(ax, ay, bx, by);
				t = dt;
                        }
		break;

		case '6':
			x = gfx_xpos();
                        y = gfx_ypos();
                        gfx_color(255, 0, 255);
                        r = 20;
                        t = 0;
                        for(dt = 0; dt <= 2*M_PI+1; dt += (2*M_PI)/6){
                                ax = x + r*cos(t);
                                ay = y + r*sin(t);
                                bx = x + r*cos(dt);
                                by = y + r*sin(dt);
                                gfx_line(ax, ay, bx, by);
				t = dt;
                        }
		break;

		case '7':
			x = gfx_xpos();
                        y = gfx_ypos();
                        gfx_color(255, 0, 255);
                        r = 20;
                        t = 0;
                        for(dt = 0; dt <= 2*M_PI+1; dt += (2*M_PI)/7){
                                ax = x + r*cos(t);
                                ay = y + r*sin(t);
                                bx = x + r*cos(dt);
                                by = y + r*sin(dt);
                                gfx_line(ax, ay, bx, by);
				t = dt;
                        }
		break;

		case '8':
			x = gfx_xpos();
                        y = gfx_ypos();
                        gfx_color(255, 0, 255);
                        r = 20;
                        t = 0;
                        for(dt = 0; dt <= 2*M_PI+1; dt += (2*M_PI)/8){
                                ax = x + r*cos(t);
                                ay = y + r*sin(t);
                                bx = x + r*cos(dt);
                                by = y + r*sin(dt);
                                gfx_line(ax, ay, bx, by);
				t = dt;
                        }
		break;

		case '9':
			x = gfx_xpos();
                        y = gfx_ypos();
                        gfx_color(255, 0, 255);
                        r = 20;
                        t = 0;
                        for(dt = 0; dt <= 2*M_PI+1; dt += (2*M_PI)/9){
                                ax = x + r*cos(t);
                                ay = y + r*sin(t);
                                bx = x + r*cos(dt);
                                by = y + r*sin(dt);
                                gfx_line(ax, ay, bx, by);
				t = dt;
                        }
		break;
	   }	
	}
}
