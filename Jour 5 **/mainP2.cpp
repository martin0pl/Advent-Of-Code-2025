#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

bool estPresent(long long, vector<long long> &);

int main(){

    ifstream entree;
    entree.open("input.txt");

    vector<string> intervallesString;
    vector<long long> produitsFrais;

    string ligne;

    bool espacePassé = false;

    // Récupération des données en les séparants entre intervalles et ingrédients
    while (getline(entree, ligne))
    {
        if (ligne=="") espacePassé = true;
    	else if (!espacePassé) intervallesString.push_back(ligne);
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

    for (int i=0; i<intervalles.size(); i++)
    {
        for (int j=intervalles[i][0]; j<=intervalles[i][1]; j++)
        {
            if (!estPresent(j,produitsFrais)) produitsFrais.push_back(j);
        }
    }

    cout << "-----> " << produitsFrais.size() << endl;

	return 0;
}

bool estPresent(long long cible, vector<long long> &valeurs)
{
    bool estpresent = false;
    int i=0;

    while (!estpresent && i<valeurs.size())
    {
        estpresent = cible==valeurs[i];
        i++;
    }
    return estpresent;
}