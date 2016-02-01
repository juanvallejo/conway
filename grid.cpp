
#include <iostream>
#include <vector>
#include <ctime>
#include "cell.h"
#include "grid.h"

grid::grid(int width, int height) {

	std::srand(std::time(0));

	int w = width;
	int h = height;

	bool c_dead;

	this->dims.width = width;
	this->dims.height = height;

	cell* cell_mat[w][h];

	for(int x = 0; x < w; x++) {
		for(int y = 0; y < h; y++) {
			c_dead = true;
			if(std::rand() % 10 < 6) { c_dead = false; }
			cell_mat[x][y] = new cell(c_dead);
		}
	}

	// allocate neghbors to each cell
	// and save matrix as vector<cells *>
	for(int x = 0; x < w; x++) {
		for(int y = 0; y < h; y++) {

			if(y - 1 >= 0) {
				cell_mat[x][y]->set_ntop(cell_mat[x][y - 1]);
			}

			if(y + 1 < h) {
				cell_mat[x][y]->set_nbot(cell_mat[x][y + 1]);
			}

			if(x - 1 >= 0) {
				cell_mat[x][y]->set_nleft(cell_mat[x - 1][y]);
			}

			if(x + 1 < w) {
				cell_mat[x][y]->set_nright(cell_mat[x + 1][y]);
			}

			this->cells.push_back(cell_mat[x][y]);

		}
	}

}

grid::~grid() {}

std::vector<cell *> grid::get_cells() {
	return this->cells;
}

cell* grid::get_cell(int c_index) {
	if(this->cells.size() <= c_index || c_index < 0) { return 0; }
	return this->cells.at(c_index);
}

// TODO: add collision check
void grid::add_cell(cell* new_cell) {
	this->cells.push_back(new_cell);
}

int grid::get_cell_count() {
	return this->cells.size();
}

int grid::get_width() {
	return this->dims.width;
}

int grid::get_height() {
	return this->dims.height;
}

grid::grid_dims grid::get_size() {
	return this->dims;
}