#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void initBoard(char[][40]);
void testFunction();
void dispBoard(char[][40]);
void newBoard(char[][40],char[][40]);
void addCell(char[][40],char[][40],int, int);
void killCell(char [][40], char[][40],int,int);
void survival(int[][40],char[][40]);
void next(char[][40],char[][40]);
void infinity(char[][40],char[][40]);

int main(int argc, char *argv[]){
	FILE *ifp;
	char board[40][40], c;
	char nextBoard[40][40];
	int x,y,result = 0;
	initBoard(board);
	newBoard(nextBoard, board);
//	testFunction(board);
	if(argc == 1){
		printf("Please select from the following options:\n");
		printf("a: add a live cell.\n");
		printf("r: remove a live cell.\n");
		printf("d: display the current board.\n");
		printf("n: advance one generation.\n");
		printf("p: run infinitely long (Ctrl + C to escape).\n");
		printf("q: quit.\n");
		while(1){
			scanf(" %c",&c);
			switch(c){
				case 'a':
					addCell(board,nextBoard,x,y);
					break;
				case 'r':
					killCell(board,nextBoard,x,y);
					break;
				case 'd':
					dispBoard(board);
					break;
				case 'n':
					next(board,nextBoard);
					break;
				case 'p':
					infinity(board,nextBoard);
					break;
				case 'q':
					return 0;
				default:
					printf("invalid option, try again.\n");
					break;
			}
		}
	}
	if(argc == 2){
		ifp = fopen(argv[1], "r");
		while(1){
			fscanf(ifp,"%c", &c);
			switch(c){
				case 'a':
					addCell(board,nextBoard,x,y);
					break;
				case 'p':
					infinity(board,nextBoard);
					break;
			}
		}
		fclose(ifp);
	}
	return 0;
}

	void initBoard(char board [][40]){
	int i,j;
	for (j=0;j<40;j++){
		for (i=0;i<40;i++){
			board[i][j] = ' ';
		}
	}
	
}

void newBoard(char board[][40], char newBoard[][40]){
	int i,j;
	for (j=0;j<40;j++){
		for(i=0;i<40;i++){
			board[i][j] = newBoard[i][j];
		}
	}
}
void dispBoard(char board [][40]){
	int x,y;
	printf("\033[H");
	printf("0---------------------------------------\n");
	for (y=0;y<40;y++){
		printf("|");
		for(x=0;x<40;x++){
			printf("%c",board[x][y]);
		}
	printf("\n");
	}
}

void addCell(char board[][40], char nextBoard[][40], int x, int y){
	printf("\nEnter x Coordinate to add: ");
	scanf("%d", &x);
	printf("\nEnter y Coordinate to add: ");
	scanf("%d", &y);
	if (x < 0 || y < 0 || x > 40 || y > 40){
		printf("invalid location, try again\n");
		addCell(board,nextBoard,x,y);
	}
	else{
		board[x][y] = 'X';
		dispBoard(board);
		newBoard(nextBoard,board);
	}
}

void killCell(char board[][40], char nextBoard[][40], int m, int n){
        printf("\nEnter x Coordinate to remove: ");
        scanf("%d", &m);
	printf("\nEnter y Coordinate to remove: ");
	scanf("%d", &n);
        if (m < 0 || n < 0 || m > 40 || n > 40){
                printf("invalid location, try again\n");
                addCell(board,nextBoard,m,n);
        }
        else{
                board[m][n] = ' ';
                dispBoard(board);
                newBoard(nextBoard,board);
        }
}


void infinity(char board[][40], char nextBoard[][40]){
	next(board,nextBoard);
	usleep(1000000 / 7);
	infinity(board, nextBoard);
	system("clear");	
}

void survival(int lives[][40], char board[][40]){
	int m,n;
	for(n = 0;n<40;n++){
		for(m = 0;m<40;m++){
			if((lives[m][n] == 3 && board[m][n] == 'X') || (lives[m][n] == 4 && board[m][n]=='X')){
				board[m][n] = 'X';
			}
			else if(lives[m][n] == 3 && board[m][n] == ' '){
				board[m][n] = 'X';
			}
			else{
				board[m][n] = ' ';
			}
		}
	}
	dispBoard(board);
}

void next(char board[][40],char nextBoard[][40]){
	int m,n,i,j,k,l,life;
	int lives [40][40];
	newBoard(nextBoard,board);
	for (n = 0; n < 40;n++){
		for(m=0;m<40;m++){
			i = m-1, k= m+1, life = 0;
			for(i; i<=k; i++){
				j=n-1, l = n+1;
				for(j; j<=l;j++){
					if(nextBoard[i][j] == 'X' && i >= 0 && j>= 0 && i<40 && j<40){
						life = life + 1;
					}
				} 	
			}
			lives[m][n] = life;
		}
	}
	survival(lives,board);
}

void testFunction(char board [][40]){
	initBoard(board);
}
