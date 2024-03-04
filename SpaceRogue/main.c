#include <ncurses.h>


int main () {
	int ch;
	
	initscr(); // init ncurses
	raw();
	keypad(stdscr, TRUE);
	noecho();
	
	printw("Here the first line of input!\n");
	ch = getch();
	
	refresh(); //print it on to the real screen
	getch();
	endwin(); //end curses mode
	
	return 0;
}