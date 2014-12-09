#include <stdio.h>
#include <math.h>
#include <time.h>
#include "gfx3.h"

#define WIDTH 800
#define HEIGHT 800

void sierpinski(int,int,int,int,int,int);
void squareFract(int,int,int,int);
void spiral(int,int,int,float,int);
void circleLace(int,int,int);
void snowflake(int,int,int);
void tree(int,int,int,float);
void fern(int,int,int,float);

int main(){
	char num;
	time_t t;
	srand((unsigned)time(&t));
	int x1,x2,x3,x4,y1,y2,y3,y4,w,h,dTheta,r;

	gfx_open(WIDTH,HEIGHT,"Fractals");

	while(1){
		num = gfx_wait();
		switch(num){
			case '1':
				x1 = WIDTH*.1,x2=WIDTH*.9,x3=WIDTH*.5;
				y1 = HEIGHT*.1,y2 = y1, y3=HEIGHT*.9;
				gfx_clear();
				gfx_color(0,200,0);
				sierpinski(x1,y1,x2,y2,x3,y3);
				break;
			case '2':
				gfx_clear();
				x1 = WIDTH/4, w = WIDTH/2;
				y1 = HEIGHT/4, h = HEIGHT/2;
				gfx_color(255,255,255);
				squareFract(x1,y1,w,h);
				break;
			case '3':
				gfx_clear();
				x1 = WIDTH*.25, y1=HEIGHT*.75;
				w= WIDTH/10,dTheta = M_PI/6;
				r = WIDTH/4;
				spiral(x1,y1,w,dTheta,r);
				break;
			case '4':
				gfx_clear();
				x1 = WIDTH/2, y1 = HEIGHT/2;
				r = WIDTH/3;
				gfx_color(255,255,255);
				circleLace(x1,y1,r);
				break;
			case '5':
				gfx_clear();
				x1=WIDTH/2, y1 = HEIGHT/2;
				r=WIDTH/4;
				snowflake(x1,y1,r);
				break;
			case '6':
				gfx_clear();
				x1=WIDTH/2,y1=HEIGHT;
				r=225;
				gfx_color(rand()%255,rand()%255,rand()%255);
				tree(x1,y1,r,M_PI/2);
				break;
			case '7':
				gfx_clear();
				x1=WIDTH/2,y1=HEIGHT;
				r=HEIGHT/2;
				gfx_color(rand()%255,rand()%255,rand()%255);
				fern(x1,y1,r,M_PI/2);
				break;
			case 'q':
				return 0;
			default:
				gfx_clear();
				printf("%c",num);
				break;
		}
	}

}

void sierpinski( int x1, int y1, int x2, int y2, int x3, int y3 )
{
   // Base case. 
   if( abs(x2-x1) < 2 ) return;

   // Draw the triangle
   gfx_triangle(x1,y1,x2,y2,x3,y3);

   // Recursive calls(3 total)
   sierpinski( x1, y1, (x1+x2)/2, (y1+y2)/2, (x1+x3)/2, (y1+y3)/2 );
   sierpinski( (x1+x2)/2, (y1+y2)/2, x2, y2, (x2+x3)/2, (y2+y3)/2 );
   sierpinski( (x1+x3)/2, (y1+y3)/2, (x2+x3)/2, (y2+y3)/2, x3, y3 );
}

void squareFract( int x, int y, int w, int h)
{

   // Base case.
   if( w < 7 ) return;

   // Draw the square
   gfx_rectangle(x,y,w,h);

   // Recursive calls(4 total)
	gfx_color(255,0,0);
   squareFract(x-.25*w,(y-.25*h),w/2,h/2 );		//top-left
	gfx_color(0,255,0);
   squareFract(x-.25*w,(y+.75*h),w/2,h/2 );             //bottom-left
	gfx_color(0,0,255);
   squareFract(x+.75*w,(y-.25*h),w/2,h/2 );		//top-right
	gfx_color(255,0,255);
   squareFract(x+.75*w,(y+.75*h),w/2,h/2 );		//bottom-right
}

void spiral(int x,int y, int w, float dTheta, int r){

	// Base Case.
	if( r < 5 ) return;
	
	gfx_color(rand()%255,rand()%255,rand()%255);
	// Draw Square.
	gfx_rectangle(x,y,w,w);

	// Recursive Calls(1 total)
	spiral(x+r*cos(dTheta),y-r*sin(dTheta),w*.9,dTheta+M_PI/5,r*.9);
}

void circleLace(int x, int y, int r){

	//Base Case.
	if( r <=1 ) return;

	//Draw Circle
	gfx_circle(x,y,r);

	//Recursive Calls(6 total)
	gfx_color(255,0,0);
	circleLace(x-r*cos(M_PI/3),y-r*sin(M_PI/3),r*.33);	
	gfx_color(0,255,0);
	circleLace(x+r*cos(M_PI/3),y-r*sin(M_PI/3),r*.33);	
	gfx_color(0,0,255);
	circleLace(x-r*cos(M_PI/3),y+r*sin(M_PI/3),r*.33);	
	gfx_color(255,255,0);
	circleLace(x+r*cos(M_PI/3),y+r*sin(M_PI/3),r*.33);	
	gfx_color(0,255,0);
	circleLace(x+r*cos(M_PI),y-r*sin(M_PI),r*.33);		
	gfx_color(255,0,255);
	circleLace(x+r*cos(0),y+r*sin(0),r*.33);		

}

void snowflake(int x1, int y1, int r){
	
	int dTheta = 2*M_PI/5;

	//Base Case
	if( r < 2 ) return;
	//Draw "Spokes"
	gfx_line(x1,y1,x1+r*cos(M_PI/2+dTheta),y1+r*sin(M_PI/2-dTheta));
	gfx_line(x1,y1,x1+r*cos(M_PI/2-dTheta),y1+r*sin(-M_PI/2-dTheta));
	gfx_line(x1,y1,x1+r*cos(M_PI/2-dTheta),y1+r*sin(M_PI/2+dTheta));
	gfx_line(x1,y1,x1+r*cos(M_PI/2+dTheta),y1+r*sin(-M_PI/2+dTheta));
	gfx_line(x1,y1,x1+r*cos(-M_PI/2),y1+r*sin(-M_PI/2));



	//Recursive Calls (5 total)
	snowflake(x1+r*cos(M_PI/2+dTheta),y1+r*sin(M_PI/2-dTheta),r*.35);
	snowflake(x1-r*cos(M_PI/2-dTheta),y1+r*sin(-M_PI/2-dTheta),r*.35);	//top-left
	snowflake(x1+r*cos(M_PI/2-dTheta),y1-r*sin(M_PI/2-dTheta),r*.35);	//top-right
	snowflake(x1-r*cos(M_PI/2+dTheta),y1-r*sin(-M_PI/2+dTheta),r*.35);	//bottom-right
	snowflake(x1+r*cos(-M_PI/2),y1+r*sin(-M_PI/2),r*.35);			//top


}

void tree(int x1, int y1, int r,float theta){
	int x2,y2;
	float phi = M_PI/6;
	//Base case
	if(r < 3) return;
	
	//Draw Branches
	gfx_line(x1,y1,x1+r*cos(theta),y1-r*sin(theta));
	x2=x1+r*cos(theta),y2=y1-r*sin(theta);

	//Recursive Calls(2)
	tree(x2,y2,r*.75,theta+phi);	//right side
	tree(x2,y2,r*.75,theta-phi);	//left side

}

void fern(int x1, int y1, int r, float theta){
	int x2,y2;
	float phi = M_PI/6;

	//Base case
	if(r < 20) return;

	//Draw Stem
	gfx_line(x1,y1,x1+r*cos(theta),y1-r*sin(theta));
	x2=x1+r*cos(theta),y2=y1-r*sin(theta);
	
	//Recursive Calls (8)
	fern(x2,y2,r*.5,theta+phi);
	fern(x2,y2,r*.5,theta-phi);
	fern(x1+(r*.5)*cos(theta),y1-(r*.5)*sin(theta),r*.5,theta+phi);
	fern(x1+(r*.5)*cos(theta),y1-(r*.5)*sin(theta),r*.5,theta-phi);
	fern(x1+(r*.25)*cos(theta),y1-(r*.25)*sin(theta),r*.5,theta+phi);
	fern(x1+(r*.25)*cos(theta),y1-(r*.25)*sin(theta),r*.5,theta-phi);
	fern(x1+(r*.75)*cos(theta),y1-(r*.75)*sin(theta),r*.5,theta+phi);
	fern(x1+(r*.75)*cos(theta),y1-(r*.75)*sin(theta),r*.5,theta-phi);
}
