#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

bool estPresentEntre(long long, int, vector<vector<long long>> &);

int main(){

    ifstream entree;
    entree.open("input.txt");

    vector<string> intervallesString;
    vector<long long> ingrédients;
    vector<long long> produitsFrais;

    string ligne;

    bool espacePassé = false;

    // Récupération des données en les séparants entre intervalles et ingrédients
    while (getline(entree, ligne))
    {
        if (ligne=="") espacePassé = true;
    	else if (!espacePassé) intervallesString.push_back(ligne);
    	else ingrédients.push_back(stoll(ligne));
    }

	entree.close();

    // Transformation des intervalles en deux valeurs long long
    vector<vector<long long>> intervalles;

    for (string s : intervallesString)
    {
        vector<long long> intervalle;

        string debut = "";
        string fin = "";

        bool barrePassée = false;

        for (char c : s)
        {
            if (c=='-') barrePassée = true;
            else if (!barrePassée) debut.push_back(c);
            else fin.push_back(c);
        }

        intervalle.push_back(stoll(debut));
        intervalle.push_back(stoll(fin));

        intervalles.push_back(intervalle);
    }

    // Vérification si chacun des ingrédients est présent dans un intervalle
    for (int i=0; i<ingrédients.size(); i++)
    {
        bool estFrais = false;
        long long valeur = ingrédients[i];
        int j = 0;

        while (!estFrais && j<intervalles.size())
        {
            estFrais = estPresentEntre(valeur, j, intervalles);
            j++;
        }
        if (estFrais) produitsFrais.push_back(valeur);

    }

    cout << "-----> " << produitsFrais.size() << endl;

	return 0;
}

bool estPresentEntre(long long valeur, int indice, vector<vector<long long>> &intervalles)
{
    return(intervalles[indice][0]<=valeur && valeur<=intervalles[indice][1]);
}
