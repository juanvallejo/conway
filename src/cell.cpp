
#include "cell.h"

cell::~cell() {}

bool cell::is_dead() {
	return !this->is_alive;
}

void cell::set_ncells(cell* ctop, cell* cbot, cell* cleft, cell* cright) {
	// this->ncells(ctop, cbot, cleft, cright);
}

void cell::set_ntop(cell *ncell) {

	if(!ncell) { return; }
	if(this->ncells.top) { delete this->ncells.top; }

	this->ncells.top = ncell;
}

void cell::set_nbot(cell *ncell) {

	if(!ncell) { return; }
	if(this->ncells.bottom) { delete this->ncells.bottom; }
	
	this->ncells.bottom = ncell;

}

void cell::set_nleft(cell *ncell) {

	if(!ncell) { return; }
	if(this->ncells.left) { delete this->ncells.left; }
	
	this->ncells.left = ncell;

}

void cell::set_nright(cell *ncell) {

	if(!ncell) { return; }
	if(this->ncells.right) { delete this->ncells.right; }
	
	this->ncells.right = ncell;

}

cell::cell_ncells cell::get_ncells() {
	return this->ncells;
}