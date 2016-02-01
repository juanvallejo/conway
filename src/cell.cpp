#include <vector>
#include "cell.h"

cell::~cell() {}

bool cell::is_dead() {
	return !this->is_alive;
}

void cell::set_dead() {
	this->is_alive = false;
}

void cell::set_alive() {
	this->is_alive = true;
}

void cell::add_ncell(cell *ncell) {
	this->ncells.push_back(ncell);
}

void cell::set_ntop(cell *ncell) {

	if(!ncell) { return; }
	if(this->ncell_struct.top) { delete this->ncell_struct.top; }

	this->ncell_struct.top = ncell;
}

void cell::set_nbot(cell *ncell) {

	if(!ncell) { return; }
	if(this->ncell_struct.bottom) { delete this->ncell_struct.bottom; }
	
	this->ncell_struct.bottom = ncell;

}

void cell::set_nleft(cell *ncell) {

	if(!ncell) { return; }
	if(this->ncell_struct.left) { delete this->ncell_struct.left; }
	
	this->ncell_struct.left = ncell;

}

void cell::set_nright(cell *ncell) {

	if(!ncell) { return; }
	if(this->ncell_struct.right) { delete this->ncell_struct.right; }
	
	this->ncell_struct.right = ncell;

}

void cell::set_ncell_struct(cell* ctop, cell* cbot, cell* cleft, cell* cright) {
	this->set_ntop(ctop);
	this->set_nbot(cbot);
	this->set_nleft(cleft);
	this->set_nright(cright);
}

std::vector<cell *> cell::get_ncells() {
	return this->ncells;
}