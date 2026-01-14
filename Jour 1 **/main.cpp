#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void reset(int &i){
	if (i==100) i=0;
	else if (i==-1) i=99;
}

int main(){

	int valeurTotal = 50;
	int valeurPrécédente;
	int nbzero = 0;
	int valeur;
	int cpt;
	string ligne;
	char operation;

	ifstream entree;
    entree.open("input.txt");

    while (getline(entree, ligne)) 
    {
        operation = ligne[0];

        ligne = ligne.substr(1);
        valeur = stoi(ligne);

        if (operation=='R')
        {
        	for (int i=0; i<valeur; i++)
        	{
        		valeurTotal++;
        		reset(valeurTotal);
        		if (valeurTotal==0) nbzero++;
        	}
        }
        else if (operation=='L')
        {
        	for (int i=0; i<valeur; i++)
        	{
        		valeurTotal--;
        		reset(valeurTotal);
        		if (valeurTotal==0) nbzero++;
        	}
        }
    }

    entree.close();

    cout << "-----> " << nbzero << endl;

	return 0;
}