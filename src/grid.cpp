
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

	cell* cell_mat[h][w];

	for(int y = 0; y < h; y++) {
		for(int x = 0; x < w; x++) {
			c_dead = true;
			if(std::rand() % 100 < 2) { c_dead = false; }
			cell_mat[y][x] = new cell(c_dead);
		}
	}

	// allocate neghbors to each cell
	// and save matrix as vector<cells *>
	for(int y = 0; y < h; y++) {
		for(int x = 0; x < w; x++) {

			if(x + 1 < w) {
				cell_mat[y][x]->add_ncell(cell_mat[y][x + 1]);
			}

			if(y + 1 < h) {
				cell_mat[y][x]->add_ncell(cell_mat[y + 1][x]);

				if(x + 1 < w) {
					cell_mat[y][x]->add_ncell(cell_mat[y + 1][x + 1]);
				}

				if(x - 1 >= 0) {
					cell_mat[y][x]->add_ncell(cell_mat[y + 1][x - 1]);
				}
			}

			if(x - 1 >= 0) {
				cell_mat[y][x]->add_ncell(cell_mat[y][x - 1]);
			}

			if(y - 1 >= 0) {
				cell_mat[y][x]->add_ncell(cell_mat[y - 1][x]);

				if(x + 1 < w) {
					cell_mat[y][x]->add_ncell(cell_mat[y - 1][x + 1]);
				}

				if(x - 1 >= 0) {
					cell_mat[y][x]->add_ncell(cell_mat[y - 1][x - 1]);
				}
			}

			this->cells.push_back(cell_mat[y][x]);

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