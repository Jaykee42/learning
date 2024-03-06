#include <ncurses.h>


void printPlayField() {
	
	for (int x = 0; x < 100; x++) {
		for (int y = 0; y < 50; y++) {
			mvaddch(y, x, '#');
		}
	}
	
	for (int x = 10; x < 50; x++) {
		for (int y = 10; y < 25; y++) {
			mvaddch(y, x, ' ');
		}
	}
}


void playerMovement() {
	
	char inputPlayerMove;
	
	inputPlayerMove = getch();
	
	switch (inputPlayerMove) {
		
		case 'w':
		printw("@");
		break;
	}
	
}
int main () {
	int ch;
	
	initscr(); // init ncurses
	keypad(stdscr, TRUE);
	noecho();
	
	printPlayField();
	playerMovement();
	
	ch = getch();
	
	refresh(); //print it on to the real screen
	getch();
	endwin(); //end curses mode
	
	return 0;
}


