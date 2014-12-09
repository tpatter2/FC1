#include <stdio.h>
#include <math.h>
#include "gfx3.h"

char *num2str(int);
void xAxis();
void yAxis();
double Taylor(double, int);
float fact(int);
void plot(int);

int main(){
	
	char c;
	int width = 500, height = 500, num = 1;
	double x = 1;
	gfx_open(width, height, "Taylor Series Graph");
	while(c != 'q'){
		gfx_clear();
		xAxis();
		yAxis();
		plot(num);
		c = gfx_wait();
		switch(c){
			case '=':
				num++;
			break;
			case '-':
				num--;
			break;
		}
	}
}

char *num2str(int n)
{
  static char a[4]; 
  sprintf(a, "%d", n);
  return (char *) a;
}

void xAxis(){
	int i,j;
	gfx_color(0,0,255);
	gfx_line(0,250,500,250);
	for(i=0,j=-10;i <= 500,j<=10; i+=25,j++){
		gfx_line(i,240,i,260);
		gfx_color(255,255,255);
		gfx_text(i,275, num2str(j));
	}
}

void yAxis(){
	int i,j;
	gfx_color(0,0,255);
	gfx_line(250,0,250,500);
	for(i=0,j=-10;i<=500,j<=10;i+=25,j++){
		gfx_line(240,i,260,i);
		gfx_color(255,255,255);
		gfx_text(225,i, num2str(j));
	}
}

double Taylor(double x, int num){
	double val = 0,total;
	int i;
	for(i=1; i<=num; i++){
		if (i%2==1){
			total = pow(x,2*i-1)/fact(2*i-1);
			val += total;
		}
		else{
			total = pow(x,2*i-1)/fact(2*i-1);
			val -=total;
		}
	}
	return val;
}

float fact(int a){
	int n=1;
	float result = 1;
	while(n <= a){
		result *= n;
		n++;
	}
	return result;
}

void plot(int num){
	double i;
	gfx_color(255,0,255);
	for(i = -10; i<= 10; i+=.005){
		gfx_point((i*25)+250,(Taylor(i,num)*-25)+250);		
	}
}
