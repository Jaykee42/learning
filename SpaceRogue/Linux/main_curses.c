#include <ncurses.h>


int SCREEN_X;	
int SCREEN_Y;
int c;
int y = 11, x = 11;

int map[1000][1000];


int initialization() {
	
	initscr();
	noecho();
	keypad(stdscr, 1); //allow arrows
	curs_set(0);
	getmaxyx(stdscr, SCREEN_X, SCREEN_Y);
	return map[SCREEN_Y][SCREEN_X];
}


int main() {
	initialization();
	printf("%d\n", *map[6]);
}
	/*
	int c;
	int y = 11, x = 11;
	int cols, rows;
	
	do {
		for (int yy = 0; yy <= rows; yy++) {
			for (int xx = 0; xx <= cols; xx++) {
				map[yy][xx] = '#';
				mvaddch(yy, xx, '#'); 
			} 
		}
		
		for (int yy = 11; yy <= rows /2; yy++) {
			for (int xx = 11; xx <= cols /2; xx++) {
				map[yy][xx] = ' ';
				mvaddch(yy, xx, ' '); 
			}
		}
			
		if (c == KEY_UP && map[y-1][x]) y--;
		else if (c == KEY_DOWN) y++;
		else if (c == KEY_LEFT) x--;
		else if (c == KEY_RIGHT) x++;
		mvaddch(y, x, '@');
	} while ((c = getch()) != 27); // 27 - ESC
		
	
	getch();
	endwin();
	return 0;
} */