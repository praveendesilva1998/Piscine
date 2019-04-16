#ifndef SOMMET_H
#define SOMMET_H

#include <vector>


class Sommet
{
	public:
	    int m_index;
		std::vector<int> m_adj;
		Sommet(int index = 0);
		void adj_list(int adj);

    private :


};

#endif
