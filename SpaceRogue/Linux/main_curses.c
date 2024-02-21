#include <ncurses.h>

int main() {
	int c;
	int y = 11, x = 11;
	
	
	initscr();
	noecho();
	keypad(stdscr, 1); //allow arrows
	curs_set(0);
	
	
	do {
		clear();
		if (c == KEY_UP) y--;
		else if (c == KEY_DOWN) y++;
		else if (c == KEY_LEFT) x--;
		else if (c == KEY_RIGHT) x++;
		mvaddch(y, x, '@');
	} while ((c = getch()) != 27); // 27 - ESC
		
	
	getch();
	endwin();
	return 0;
}