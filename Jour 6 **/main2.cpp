#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

int comptagesNbOpérations(string);
void lireDoubleVecteur(const vector<vector<long long>>& v);

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

    int nbOperation = comptagesNbOpérations(lignes[0]);

    vector<vector<long long>> operations (nbOperation);

    for (int i=0; i<lignes.size()-1; i++)
    {
        stringstream ss(lignes[i]);
        string mot;
        int ope = 0;

        while (ss >> mot) {
            operations[ope].push_back(stoll(mot));
            ope ++;
        }
    }

    //lireDoubleVecteur(operations);

    vector<char> operateurs;

    stringstream ss(lignes[lignes.size()-1]);
    char o;

    while (ss >> o) {
        operateurs.push_back(o);
    }    

    long long somme = 0;
    long long sommePlus;
    long long multiplication;

    for (int i=0; i<operations.size(); i++)
    {
        switch(operateurs[i])
        {
        case('+'):
            sommePlus = 0;
            for (int j=0; j<operations[i].size(); j++)
            {
                sommePlus += operations[i][j];
            }
            somme += sommePlus;
            break;

        case('*'):
            multiplication = 1;
            for (int j=0; j<operations[i].size(); j++)
            {
                multiplication *= operations[i][j];
            }
            somme += multiplication;
            break;

        default:
            cout << "Caractère non reconnu" << endl;
        }
    }

    cout << "-----> " << somme << endl;

	return 0;
}

int comptagesNbOpérations(string entree)
{
    int nbOperations = 0;

    stringstream ss(entree);
    string mot;
    string resultat = "";

    while (ss >> mot) {
        nbOperations++;
    }

    return(nbOperations);
}

void lireDoubleVecteur(const vector<vector<long long>>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        for (size_t j = 0; j < v[i].size(); ++j) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}