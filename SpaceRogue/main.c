#include <ncurses.h>


void printPlayField() {
	
	for (int x = 0; x < 10; x++) {
		printw("\n#");
		for (int y = 0; y < 20; y++) {
			printw("#");
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
	raw();
	keypad(stdscr, TRUE);
	noecho();
	
	printPlayField();
	
	ch = getch();
	
	refresh(); //print it on to the real screen
	getch();
	endwin(); //end curses mode
	
	return 0;
}


