#ifndef GRID_H
 #define GRID_H

/**
 * Cell grid. Dimensions set by grid_dims struct
 * @author juanvallejo
 */

class grid {

public:
	struct grid_dims {
		int width;
		int height;
	};

private:
	std::vector<cell *> cells;
	grid::grid_dims dims;

public:
	grid(int, int);
	~grid();

	std::vector<cell *> get_cells();

	// Retrieve cell by its position in a matrix
	cell* get_cell(int);

	void add_cell(cell *);
	int get_cell_count();

	int get_width();
	int get_height();
	grid_dims get_size();

};

#endif