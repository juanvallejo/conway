#ifndef CELL_H
 #define CELL_H

/**
 * Cell class. Contains pointers to adjacent cells
 * @author juanvallejo
 */

class cell {

public:
	// adjacent neighboors
	struct cell_ncells {
		cell* top;
		cell* bottom;
		cell* left;
		cell* right;

		cell_ncells(cell* c_top = 0, cell* c_bot = 0,
			cell* c_left = 0, cell* c_right = 0) : 
			top(c_top), bottom(c_bot), left(c_left), right(c_right) {}
	};

private:
	bool is_alive;
	cell::cell_ncells ncells;

public:
	inline cell(bool dead) : ncells() { is_alive = !dead; };
	~cell();

	bool is_dead();

	void set_dead();
	void set_alive();

	// set adjacent neighbors -> top, bottom, left, right
	void set_ncells(cell*, cell*, cell*, cell*);
	void set_ntop(cell *);
	void set_nbot(cell *);
	void set_nleft(cell *);
	void set_nright(cell *);

	// retrieve adjacent neighbors
	cell_ncells get_ncells();

};

#endif