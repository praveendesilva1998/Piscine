#include "sommet.h"
#include "graphe.h"
#include "arrete.h"

using namespace std;

#include <iostream>
#include <fstream>
#include <vector>


int main()
{
    ifstream graphe_file("graphe.txt");
    if(!graphe_file.good())
    {
        cout <<"Error opening file, Program ended";
        exit(1);
    }

    int sommet_count, arrete_count;
    vector<int> graphe_data;
    graphe_file >> sommet_count >> arrete_count;

    Graphe G(sommet_count, arrete_count);
    int arrete1, arrete2, poids;
    for (int i=0; i<arrete_count; i++)
    {
        graphe_file >> arrete1 >> arrete2 >> poids;
        G.set_data(i, arrete1, arrete2, poids);
    }

    G.display();
    G.prim();
    graphe_file.close();

	return 0;
}
