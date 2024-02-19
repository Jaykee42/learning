#include <ncurses.h>

int main() {
	initsc();
	mvaddch(22, 10, '@');
	getch();
	endwin();
	return 0;
}