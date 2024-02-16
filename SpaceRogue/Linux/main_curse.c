#include <ncurses.h>

int main () {
	initscr();
	printw("Hello World!");
	endwin();
	
	return 0;
}