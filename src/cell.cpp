#include <iostream>
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

std::vector<cell *> cell::get_ncells() {
	return this->ncells;
}