#include "graphe.h"
#include "sommet.h"
#include "arrete.h"

using namespace std;

#include <iostream>
#include <vector>


Graphe::Graphe(int sommet_count, int arrete_count)
{
	m_arrete_count = arrete_count;
	m_sommet_count = sommet_count;

	for (int a = 0, s = 0; s < sommet_count; a++, s++)
    {
		m_sommets.push_back(Sommet(s));
		m_arretes.push_back(Arrete(a));
	}
}

void Graphe::set_data(int index, int sommet1, int sommet2, int poids)
{
	m_arretes[index].arrete_set(sommet1, sommet2, poids);
	m_sommets[sommet1].m_adj.push_back(sommet2);
	m_sommets[sommet2].m_adj.push_back(sommet1);
}

void Graphe::display() const
{
	cout << "\nSommets: " << m_sommet_count << "\nArretes: " << m_arrete_count << endl << endl;
	for (int i = 0; i < m_sommet_count; i++)
        {
		cout << "Sommet " << m_sommets[i].m_index << " est adjacent aux sommets: ";
		for (int j = 0; j < m_sommets[i].m_adj.size(); j++)
			cout << m_sommets[i].m_adj[j] << ", ";
		cout << endl;
    	}

	cout << "\nLes Arretes :\n{ ";
	for (int i = 0; i < m_arrete_count; i++)
    {
        cout << "(" << m_arretes[i].m_sommet1 << ", " << m_arretes[i].m_sommet2 << "), ";
        cout << "}" << endl << endl;
    }


	for (int i = 0; i < m_arrete_count; i++)
    {
        cout << "Arrete " << i+1 << " est connecte aux sommets " << m_arretes[i].m_sommet1 << " et "
        << m_arretes[i].m_sommet2 << " avec un cout : " << m_arretes[i].m_poids << endl;
        cout << endl;
    }

}

void Graphe::prim()
{
    /////A CODER ///////
}
