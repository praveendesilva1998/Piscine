#ifndef GRAPHE_H
#define GRAPHE_H

#include "sommet.h"
#include "arrete.h"

#include <iostream>
#include <vector>


class Graphe
{
	public:
		Graphe(int sommet_count = 0, int arrete_count = 0);
		void set_data(int index, int arrete1, int arrete2, int poids);
		void prim();
		void display() const;

    private:
        int m_sommet_count, m_arrete_count;
		std::vector<Arrete> m_arretes;
		std::vector<Sommet> m_sommets;
};

#endif
