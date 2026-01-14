#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

void supprimerEspacesDeTete(vector<string>& vecteur_de_chaines);

int main(){

    vector<string> lignes;

    ifstream entree;
    entree.open("input.txt");

    string ligne;

    while (getline(entree, ligne))
    {
        lignes.push_back(ligne);
    }

    entree.close();

    vector<string> valeurs (lignes[0].size(),"");

    // Extraction des valeurs verticales
    for (int i = 0; i < lignes[0].size(); i++) 
    {
        for (int j = 0; j < lignes.size() - 1; j++) 
        {
            char caractere = lignes[j][i];
            
            valeurs[i].push_back(caractere);
        }
    }

    vector<char> signesOperation;

    // Récupérer les lignes des opérations sans supprimer la ligne
    for (char c : lignes[lignes.size()-1])
    {
        if (c=='*' || c=='+')
        {
            signesOperation.push_back(c);
        }
    }

    supprimerEspacesDeTete(valeurs);

    long long numOperation = 0;

    long long sommeTotale = 0;

    long long multiplication = 1;
    long long somme = 0;

    //for (string s : valeurs) cout << s << endl;

    for (string s : valeurs)
    {
        if (s=="")
        {
            if (signesOperation[numOperation]=='*')
            {
                sommeTotale+=multiplication;
            }
            else
            {
                sommeTotale+=somme;
            }
            numOperation++;
            multiplication = 1;
            somme = 0;
        }
        else if (signesOperation[numOperation]=='*')
        {
            multiplication *= stoll(s);
        }
        else if (signesOperation[numOperation]=='+')
        {
            somme += stoll(s);
        }
    }

        if (signesOperation[numOperation]=='*')
        {
            sommeTotale+=multiplication;
        }
        else
        {
            sommeTotale+=somme;
        }

    cout << "----> " << sommeTotale << endl;

	return 0;
}

void supprimerEspacesDeTete(vector<string>& vecteur_de_chaines) {
    for (string& s : vecteur_de_chaines) {

        auto premier_non_espace = find_if(s.begin(), s.end(), [](unsigned char c){ return !isspace(c); });

        s.erase(s.begin(), premier_non_espace);
    }
}