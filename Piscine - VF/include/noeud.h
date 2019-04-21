#ifndef NOEUD_H
#define NOEUD_H

#include <vector>


class Noeud
{
	public:
		int index, degree;
		std::vector<int> adj;

		Noeud(int index = 0);
		void adj_list(int adj);
};

#endif
