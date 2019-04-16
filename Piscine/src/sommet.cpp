#include "sommet.h"

#include <iostream>


Sommet::Sommet(int index)
{
	m_index = index;
}

void Sommet::adj_list(int adj)
{
	m_adj.push_back(adj);
}
