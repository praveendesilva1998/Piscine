#include "graphe.h"
#include "sommet.h"
#include "arrete.h"
#include "svgfile.h"

using namespace std;

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

Graphe::Graphe(std::string nomFichier,std::string nomFichierPoids)
{
    std::ifstream ifs{nomFichier};
    if (!ifs)throw std::runtime_error("Impossible d'ouvrir en lecture " + nomFichier);
    int ordre;
    ifs >> ordre;
    if ( ifs.fail() )throw std::runtime_error("Probleme lecture ordre du graphe");
    int index;
    double x,y;
    double sommet1, sommet2;
    //lecture des sommets
    for (int i=0; i<ordre; ++i)
    {
        ifs>>index; if(ifs.fail()) throw std::runtime_error("Probleme lecture donnees sommet");
        ifs>>x; if(ifs.fail()) throw std::runtime_error("Probleme lecture donnees sommet");
        ifs>>y; if(ifs.fail()) throw std::runtime_error("Probleme lecture donnees sommet");
        Sommet*S = new Sommet{index,x,y};
        m_sommets.push_back(S);
    }
    int taille;
    ifs >> taille;
    if ( ifs.fail() )throw std::runtime_error("Probleme lecture taille du graphe");
    std::string id_voisin;
    //lecture des arretes
    for (int i=0; i<taille; ++i)
    {
        //lecture des ids des deux extremites
        ifs>>index; if(ifs.fail()) throw std::runtime_error("Probleme lecture donnees sommet");
        ifs>>sommet1; if(ifs.fail()) throw std::runtime_error("Probleme lecture donnees sommet");
        ifs>>sommet2; if(ifs.fail()) throw std::runtime_error("Probleme lecture donnees sommet");
        Arrete* a = new Arrete(index); //crée l'arrete lue depuis le fichier
        a->m_sommet1 = sommet1;
        a->m_sommet2 = sommet2;

        for(Sommet * som : m_sommets)
        {
            if(som->m_index2 == sommet1)
            {
                a->s1 = som;
            }
            if(som->m_index2 == sommet2)
            {
                a->s2 = som;
            }
        }


        m_arretes.push_back(a); //ajoute l'arrete au tableau d'aretes du graph
    }

    //GESTION DES POIDS

    std::ifstream ifs2{nomFichierPoids}; //ouvre le fichier des poids
    if (!ifs2)throw std::runtime_error("Impossible d'ouvrir en lecture " + nomFichierPoids);
    int nbligne, nbpoids;
    ifs2 >> nbligne; ifs2 >> nbpoids; //lecture de la premiere ligne du fichier

    for(int i = 0;i<nbligne;i++) //pour chaque ligne suivante dans le fichier
    {
        //lecture de chaque ligne
        int arreteId;
        float poids1, poids2;
        ifs2 >>arreteId;
        ifs2 >>poids1;
        ifs2 >>poids2;

        for(Arrete* A : m_arretes) //parcours toutes les arretes pour trouver celle qui a le meme id que la ligne de poids
        {
            if(A->m_index1 == arreteId)
            {
                A->m_poids.push_back(poids1); //ajouts des poids a l'arete trouvée
                A->m_poids.push_back(poids2);
                break;//passe au poids suivant
            }



        }
    }
}


class subset
{
    public:
    int sommet;
    int subsetID;
};

int find(struct subset subsets[], int i)
{
    // trouver racine et faire raccine comme le parent de i
    if (subsets[i].sommet != i)
        subsets[i].sommet = find(subsets, subsets[i].sommet);

    return subsets[i].sommet;
}


void Union(struct subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    //on attache l'arbre de rang inferieur sous la racine de l'arbre de rang superieur
    if (subsets[xroot].subsetID < subsets[yroot].subsetID)
        subsets[xroot].sommet = yroot;
    else if (subsets[xroot].subsetID > subsets[yroot].subsetID)
        subsets[yroot].sommet = xroot;

    //si les rangs sont identiques, on augmente le racine par un
    else
    {
        subsets[yroot].sommet = xroot;
        subsets[xroot].subsetID++;
    }
}
void Graphe::afficher()
{
    Svgfile* svgout = new Svgfile("svgout.svg",1000,800);
    svgout->addGrid();
    
    
    for (Sommet* som : m_sommets)
    {
        //affichage des sommets
        svgout->addCircle(som->m_x,som->m_y,15,3,"red");
        //affichage des indexs des sommets
        svgout->addText(som->m_x,som->m_y,som->m_index2,"black");
    }

    for(Arrete *arr : m_arretes)
    {
        svgout->addLine(arr->s1->m_x,arr->s1->m_y,arr->s2->m_x,arr->s2->m_y,"yellow");
    }

    this->executekruskal(svgout);
    
    for (int i=0; i<=1000; ++i)
    {
        for (int j=0; j<=800; ++j)
        {
            //courbe pareo
            svgout->addLine(500,100,500,500,"black");//axes
            svgout->addLine(500,100,900,100,"black");
            svgout->addText(950,100,"Poids 1","black");
            svgout->addText(500,550,"Poids 2","black");
        }
    }
    
   

    delete svgout;
}

bool comparaison (Arrete* a, Arrete* b)
{
    return a->m_poids < b->m_poids;
}

int Graphe::executekruskal(Svgfile * file = NULL)
{
    int V = m_sommets.size();
    int e = 0;
    int i = 0;
    std::vector <Arrete*> result;
    std::vector <Arrete*> allEdges;

    for(Arrete* z : m_arretes)
    {
        allEdges.push_back(z);
    }


    std::sort(allEdges.begin(), allEdges.end(), comparaison);
    subset* subsets = (subset*) malloc( V * sizeof(subset) );
    // Creer un subset V avec 1 seul element
    for (int v = 0; v < V; ++v)
    {
        subsets[v].sommet = v;
        subsets[v].subsetID = 0;
    }

    while (e < V - 1)
    {
        Arrete* next_edge = allEdges[i++];
        int x = find(subsets, next_edge->m_sommet1);
        int y = find(subsets, next_edge->m_sommet2);
        if (x != y)
        {
            e++;
            result.push_back(next_edge);
            Union(subsets, x, y);
        }
    }

    //afficher le contenu du resultat
    cout <<endl<< "Le parcours de l'algorithme Kruskal : " <<endl;
    double poids0 = 0;
    double poids1 = 0;
    for(Arrete* r : result)
    {
        if(file!=NULL)
        {
            file->addLine(r->s1->m_x+2, r->s1->m_y+2, r->s2->m_x+2,r->s2->m_y+2,"blue");
            file->addCircle(r->s1->m_x+500+poids0,r->s2->m_y+poids1, 5, 5, "blue");
            
        }
        cout << r->m_sommet1 <<" , " << r->m_sommet2 <<" :: " << r->m_poids.at(0) << " , " << r->m_poids.at(1) << std::endl;
        poids0 = poids0 + r->m_poids.at(0);
        poids1 = poids1 + r->m_poids.at(1);
    }
    cout << endl << "Poids Kruskal : "<< endl <<"Poids 1 :  "<< poids0 << endl << "Poids 2 : " << poids1;
    
    return 0;
    

}




