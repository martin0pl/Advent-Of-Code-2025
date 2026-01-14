#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int comptagesNbOpérations(string);
string traitementLigne(string); // Supprime tous les doubles espaces

int main(){

    vector<string> lignes;

    ifstream entree;
    entree.open("inputtest.txt");

    string ligne;
    int cpt=0;

    int nbOperation;

    while (getline(entree, ligne))
    {
        ligne = traitementLigne(ligne);
        if (cpt==0) nbOperation = comptagesNbOpérations(ligne);
        cpt++;
        lignes.push_back(ligne);
    }

	entree.close();

    //for (string s : lignes) cout << s << endl;

    vector<vector<long long>> operations (nbOperation);
    string nombre = "";
    int nbEspaces = 0;

    for (int i=0; i<lignes.size()-1; i++)
    {
        nbEspaces = 0;
        nombre = "";
        cout << lignes[i] << endl;
        for (int j=0; j<lignes[i].size(); j++)
        {
            if (lignes[i][j]!=' ') nombre.push_back(lignes[i][j]);
            else if (lignes[i][j]!='\n' && !nombre.empty())
            {
                operations[nbEspaces].push_back(stoll(nombre));
                nombre = "";
                nbEspaces++;
            }
        }
        if () operations[nbEspaces].push_back(stoll(nombre));
    }

	return 0;
}

int comptagesNbOpérations(string entree)
{
    int nbOperations = 0;

    entree = traitementLigne(entree);

    for (char c : entree)
    {
        if (c==' ') nbOperations++;
    }

    return(nbOperations);
}

string traitementLigne(string ligne)
{
    string newLigne = ligne;

    for (int i=1; i<ligne.size(); i++)
    {
        if (i==1 && ligne[0]==' ') newLigne[0] = 'a';
        if (ligne[i-1]==' ' && ligne[i]== ' ') newLigne[i] = 'a';
    }

    string newLigne2;

    for (char c : newLigne)
    {
        if (c!='a')
        {
            newLigne2.push_back(c);
        }
    }

    while (newLigne2[newLigne2.size()-1]==' ')
    {
        newLigne2.pop_back();
    }

    return(newLigne2);
}