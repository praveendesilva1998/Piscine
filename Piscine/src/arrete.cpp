#include "arrete.h"

#include <iostream>


Arrete::Arrete(int index)
{
    m_index = m_index;
    m_sommet1 = 0;
	m_sommet2 = 0;
	m_poids = 0;
}

void Arrete::arrete_set(int sommet1, int sommet2, int poids)
{
	m_sommet1 = sommet1;
	m_sommet2 = sommet2;
	m_poids = poids;
}
