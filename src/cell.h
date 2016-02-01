#ifndef CELL_H
 #define CELL_H

/**
 * Cell class. Contains pointers to adjacent cells
 * @author juanvallejo
 */

class cell {

private:
	bool is_alive;
	std::vector<cell *> ncells;

public:
	inline cell(bool dead) { is_alive = !dead; };
	~cell();

	bool is_dead();

	void set_dead();
	void set_alive();

	void add_ncell(cell *);

	// retrieve adjacent neighbors
	std::vector<cell *> get_ncells();

};

#endif