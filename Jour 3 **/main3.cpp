#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int trouverPlusGrand(string);
string trouverPlusGrandLigne(string);

int main(){

	string bank;
	vector<string> banks;

	ifstream entree;
    entree.open("inputtest.txt");

    while (getline(entree, bank))
    {
    	banks.push_back(bank);
	}

	entree.close();

	for (int i=0; i<banks.size(); i++)
	{
		banks[i] = trouverPlusGrandLigne(banks[i]);
	}

	long long somme = 0;

	for (string s : banks) cout << s << endl;

	for (string s : banks) somme += stoll(s);

	if (somme==3121910778619) cout << "Ça marche !!!!" << endl;
	else cout << "Ça marche pas encore" << endl;

	return 0;
}

int trouverPlusGrand(string s)
{
	int plusGrand = 0;
	int indiceMax = -1;
	string valeurString = "0";
	int valeur;

	for (int i=0; i<s.size(); i++)
	{
		if (s[i]!='.')
		{
			valeurString = "0";
			valeurString.push_back(s[i]);
			valeur = stoi(valeurString);

			if (plusGrand <= valeur)
			{
				indiceMax = i;
				plusGrand = valeur;
			}
		}
	}

	return indiceMax;
}

string trouverPlusGrandLigne(string ligne)
{
	string ligneTravail = ligne;
	string resultat = "";

	for (int i=0; i<12; i++)
	{
		ligneTravail[trouverPlusGrand(ligneTravail)] = '.';
	}

	for (int i=0; i<ligne.size(); i++)
	{
		if (ligneTravail[i]=='.') resultat.push_back(ligne[i]);
	}

	return resultat;
}