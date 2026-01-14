#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

bool estPresentEntre(long long, long long, long long);

int main(){

    ifstream entree;
    entree.open("inputtest.txt");

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

    vector<vector<long long>> intervallesNew;

    //cout << intervalles.size() << endl;

    // Vérification si un intervalle est compris dans un autre
    for (int i=0; i<intervalles.size(); i++) 
    {
        bool estContenuDansUnAutre = false;

        long long debutCible = intervalles[i][0];
        long long finCible = intervalles[i][1];

        for (int j=0; j<intervalles.size(); j++)
        {
            if (i == j) continue;

            long long debutConteneur = intervalles[j][0];
            long long finConteneur = intervalles[j][1];

            if (estPresentEntre(debutCible, debutConteneur, finConteneur) && estPresentEntre(finCible, debutConteneur, finConteneur))
            {
                estContenuDansUnAutre = true;
                break;
            }
        }

        if (!estContenuDansUnAutre) {
            intervallesNew.push_back(intervalles[i]);
        }
    }

    intervalles = intervallesNew;
    //cout << intervalles.size() << endl;

    // Ajustement des intervalles
    for (int i=0; i<intervalles.size(); i++)
    {
        for (int j=0; j<intervalles.size(); j++)
        {
            if (intervalles[i][1]>intervalles[j][0] && intervalles[i][0]>intervalles[j][0])
            {
                intervalles[i][1] = intervalles[j][0] - 1;
            }
            else
            {
                intervalles[i][0] = -1;
                intervalles[i][1] = -1;
            }
        }
    }

    // Comptage du nombre d'ingrédients frais possibles
    long long nb = 0;

    for (vector<long long> v : intervalles)
    {
        if (v[0]!=-1 && v[1]!=-1) nb += v[1]-v[0];
    }

    cout << nb << endl;
    cout << "----> " << (nb==14) << endl;

	return 0;
}

bool estPresentEntre(long long valeur, long long debut, long long fin)
{
    return(debut<=valeur && valeur<=fin);
}