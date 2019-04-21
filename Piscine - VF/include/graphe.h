#ifndef GRAPHE_H
#define GRAPHE_H

#include "sommet.h"
#include "arrete.h"

#include <iostream>
#include <vector>
#include "svgfile.h"

class Graphe
{
	public:
	    Graphe(std::string,std::string);
	    void afficher();
            int executekruskal(Svgfile * file);


    private:
            double m_x, m_y;
            std::vector<Arrete*> m_arretes;
            std::vector<Sommet*> m_sommets;
};

#endif
