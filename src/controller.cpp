/**
 * Conway's game of life test
 */

#include <iostream>
#include <vector>
#include <ncurses.h>
#include <signal.h>
#include "cell.h"
#include "grid.h"

void sigint_handler(int sig) {
	endwin();
	exit(0);
}

void draw(grid *conway) {

	const char LINEB[] = "\n";

	// TODO: traverse cell tree
	mvprintw(conway->get_height() / 2, 0, "Created new grid of dimensions %d x %d", conway->get_width(), conway->get_height());
	refresh();

	usleep(1e6);

	while(true) {

		clear();
		refresh();

		for(int i = 0; i < conway->get_cell_count(); i++) {
			
			bool lineb = false;

			if((i + 1) % conway->get_width() == 0) {
				lineb = true;
			}

			if(conway->get_cell(i)->is_dead()) {

				int n_count = 0;

				for(int x = 0; x < conway->get_cell(i)->get_ncells().size(); x++) {
					if(conway->get_cell(i)->get_ncells().at(x) && conway->get_cell(i)->get_ncells().at(x)->is_dead() == false) {
						n_count++;
					}
				}

				if(n_count == 3) {
					conway->get_cell(i)->set_alive();
				}

				printw("%3s%s", "   ", lineb ? LINEB : "");
			} else {

				int n_count = 0;

				for(int x = 0; x < conway->get_cell(i)->get_ncells().size(); x++) {
					if(conway->get_cell(i)->get_ncells().at(x) && conway->get_cell(i)->get_ncells().at(x)->is_dead() == false) {
						n_count++;
					}
				}

				if(n_count < 2 || n_count > 3) {
					conway->get_cell(i)->set_dead();
				}

				printw("%3s%s", " x ", lineb ? LINEB : "");
			}

			refresh();
		}

		usleep(1e3);
	}

}

void init(int width, int height) {

	int scr_width;
	int scr_height;

	// ncurses init
	signal(SIGINT, sigint_handler);
	initscr();
	getmaxyx(stdscr, scr_width, scr_height);

	if(width > scr_width) { width = scr_width; }
	if(height > scr_height) { height = scr_height; }

	grid* conway = new grid(width, height);

	draw(conway);
	endwin();

}

int main() {
	init(30, 20);
	return 0;
}