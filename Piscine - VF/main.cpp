#include "sommet.h"
#include "graphe.h"
#include "arrete.h"
#include "svgfile.h"
#include "couleur.h"
#include "util.h"



using namespace std;

#include <iostream>
#include <fstream>
#include <vector>


int main()
{

    //Graphe G("./files/broadway.txt","./files/broadway_weights_0.txt");
    //Graphe G("./files/cubetown.txt","./files/cubetown_weights_0.txt");
    Graphe G("./files/manhattan.txt","./files/manhattan_weights_0.txt");
    //Graphe G("./files/triville.txt","./files/triville_weights_0.txt");

    G.afficher();
    G.executekruskal(NULL);


	return 0;
}
