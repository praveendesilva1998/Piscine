#include "noeud.h"

#include <iostream>


Noeud::Noeud( int index ) {
	this->index = index;
	degree = 0;
}

void Noeud::adj_list( int adj ) {
	this->adj.push_back(adj);
}
