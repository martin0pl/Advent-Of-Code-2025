#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm> // Nécessaire pour std::max

using namespace std;

// Déclarations inchangées
bool estPresentEntre(long long valeur, long long debut, long long fin);
void lireDoubleVecteur(const vector<vector<long long>>& v);
void trieParInsertion(vector<vector<long long>>& v);

int main(){

    ifstream entree;
    vector<vector<long long>> intervalles; 

    entree.open("input.txt");
    string ligne;

    while (getline(entree, ligne))
    {
        if (ligne.empty()) break;
        
        vector<long long> intervalle;
        string debut = "";
        string fin = "";
        bool barrePassée = false;

        for (char c : ligne)
        {
            if (c=='-') barrePassée = true;
            else if (!barrePassée) debut.push_back(c);
            else fin.push_back(c);
        }

        if (!debut.empty() && !fin.empty()) {
            intervalle.push_back(stoll(debut));
            intervalle.push_back(stoll(fin));
            intervalles.push_back(intervalle);
        }
    }

    entree.close();

    if (intervalles.empty()) {
        cout << "-----> 0" << endl;
        return 0;
    }

    trieParInsertion(intervalles);

    vector<vector<long long>> intervallesFusionnes;
    intervallesFusionnes.push_back(intervalles[0]);

    for (size_t i = 1; i < intervalles.size(); ++i) {
        vector<long long>& dernierFusionne = intervallesFusionnes.back();
        const vector<long long>& courant = intervalles[i];

        if (courant[0] <= dernierFusionne[1]) {
            dernierFusionne[1] = max(dernierFusionne[1], courant[1]);
        } 
        else 
        {
            intervallesFusionnes.push_back(courant);
        }
    }

    long long somme = 0;
    for (const auto& intervalle : intervallesFusionnes)
    {
        somme += intervalle[1] - intervalle[0] + 1;
    }

    cout << "-----> " << somme << endl;

    return 0;
}

bool estPresentEntre(long long valeur, long long debut, long long fin)
{
    return(debut<=valeur && valeur<=fin);
}

void lireDoubleVecteur(const vector<vector<long long>>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        for (size_t j = 0; j < v[i].size(); ++j) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

void trieParInsertion(vector<vector<long long>>& v)
{
    for (size_t i = 1; i < v.size(); i++)
    {
        vector<long long> intervalleCible = v[i];
        long long debutCible = intervalleCible[0];
        long long j = i - 1; 

        while (j >= 0 && v[j][0] > debutCible)
        {
            v[j + 1] = v[j];
            j--;
        }

        v[j + 1] = intervalleCible;
    }
}