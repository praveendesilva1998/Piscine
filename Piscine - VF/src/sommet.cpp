#include "sommet.h"

#include <iostream>


Sommet::Sommet(int index2 ,double x, double y)
{
	m_index2 = index2;
	m_x=x;
	m_y=y;
}

void Sommet::adj_list(int adj)
{
	m_adj.push_back(adj);
}
