#ifndef ARRETE_H
#define ARRETE_H
#include <vector>
#include "sommet.h"
using namespace std;
class Arrete
{
	public:
	    Arrete(double, double);
            Arrete(int m_index1 = 0);
            vector<float> m_poids;
	    double m_sommet1, m_sommet2;
            Sommet* s1; Sommet* s2;
            int m_index1;
    private:





};

#endif
