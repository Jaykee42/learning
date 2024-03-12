#include <ncurses.h>
int playerX = 11;
int playerY = 11;
bool GameOver = true;

void printPlayField() {
	int x,y;
	for (x = 0; x < 100; x++) {
		for (y = 0; y < 50; y++) {
			mvaddch(y, x, '#');
			
		}
	}
	
	for (x = 10; x < 50; x++) {
		for (y = 10; y < 25; y++) {
			mvaddch(y, x, ' ');
			if (playerX == x && playerY == y) {
				mvaddch(y, x, '@');
			}
		}
	}
	
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
int main () {
	int ch;
	
	initscr(); // init ncurses
	keypad(stdscr, TRUE);
	noecho();
	curs_set(0);
	
	while(GameOver) {
		
		printPlayField();
		playerMovement();
	
	}
	
	
	refresh(); //print it on to the real screen
	getch();
	endwin(); //end curses mode
	
	return 0;
}


