#include <ncurses.h>

int playerX;
int playerY;
bool GameOver = true;
int screenRows;
int screenColumns;


void printPlayField() {
	
	
	char gameField[screenRows][screenColumns];
	int x,y;
	
	for (x = 0; x < screenColumns; x++) {
		for (y = 0; y < screenRows; y++) {
			mvaddch(y, x, '#');
			
		}
	}
	
	for (x = 2; x < screenColumns/3; x++) {
		for (y = 1; y < screenRows/3; y++) {
			mvaddch(y, x, ' ');
		}
	}
	
	mvaddch(playerY, playerX, '@');
}


void playerMovement() {
	
	int inputPlayerMove;
	
	
	inputPlayerMove = getch();
	
	switch (inputPlayerMove) {
		
		case KEY_UP:
			playerY--;
			break;
		
		case KEY_DOWN:
			playerY++;
			break;
		case KEY_LEFT:
			playerX--;
			break;
		case KEY_RIGHT:
			playerX++;
			break;
		case '0':
			GameOver = false;
			break;
	}
	
}

int gameInitialisation() {
	
	initscr(); // init ncurses
	getmaxyx(stdscr, screenRows, screenColumns);
	playerX = screenColumns/2;
	playerY = screenRows/2;
	keypad(stdscr, TRUE);
	noecho();
	curs_set(0);
}
int main () {
	
	gameInitialisation();
	
	while(GameOver) {
		
		printPlayField();
		playerMovement();
		
	}
	
	
	refresh(); //print it on to the real screen
	endwin(); //end curses mode
	
	return 0;
}


