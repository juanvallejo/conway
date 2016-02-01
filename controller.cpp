/**
 * Conway's game of life test
 */

#include <iostream>
#include <vector>
#include "cell.h"
#include "grid.h"

void init() {
	
	grid* conway = new grid(5, 4);
	std::cout << "Created new grid of dimensions " << conway->get_width() << " x " << conway->get_height() << std::endl;
	std::cout << "Count " << conway->get_cell_count() << " cells" << std::endl;

}

int main() {
	init();
	return 0;
}