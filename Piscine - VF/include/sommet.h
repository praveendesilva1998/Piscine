#ifndef SOMMET_H
#define SOMMET_H

#include <vector>


class Sommet
{
    public:
        int x , y ; //coordonn� du sommet pour le dessin allegro
        Sommet(int, double, double);
	void adj_list(int adj);
        double m_x,m_y;
        int m_index2;
        
    private :
        std::vector<int> m_adj;



};

#endif
