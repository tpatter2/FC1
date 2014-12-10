#include<stdio.h>
#include<string.h>
#include<math.h>

#define WIDTH 600
#define HEIGHT 600

void drawSnake();
int boundaries();
void place_food();
void UP(int, int);
void DOWN(int, int);
void LEFT(int, int);
void RIGHT(int, int);
void change_food();
void place_food();
int head_posx(char []);
int head_posy(char []);
int food_posx();
int_foodposy();
void change_food();

int main(){
	
	int x, y, vx, vy,t;
	char snake[100];
	time_t t;
	srand((unsigned)time(&t));
	
	//Head of snake
	snake[0] = 'H';

	//Initial size (lenght) of snake
	for(i=1;i<=4;i++){
		snake[i] = 'x';
	}
	
	//Opens Graphics window
	gfx_open(WIDTH, HEIGHT, "Snake");
	

	
	

}


void drawSnake(){
	
}

int boundaries(){
	//Function returns whether the snake has reach a boundary
}

void UP(){
	//Moves Snake up
}

void DOWN(){
	//Moves snake down
}

void LEFT(){
	//Moves snake left
}

void RIGHT(){
	//Moves snake right
}

void place_food(){
	int x,y;

	x = rand()%600;
	y = rand()%600;
	gfx_txt(x,y,num2str(0);
}

int head_posx(char snake[]){
	
}

int head_posy(char snake[]){

}

int food_posx(){

}

int food_posy(){
	
}



void change_food(){
	//Add new food once snake has eaten prev
	if(food_posx==head_posx && food_posy==head_posy)
		placefood();
}
