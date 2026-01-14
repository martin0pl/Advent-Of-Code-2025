#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

string trouverPlusGrandLigne(string ligne);

int main(){

	string bank;
	vector<string> banks;

	ifstream entree;
    entree.open("input.txt");

    while (getline(entree, bank))
    {
    	banks.push_back(bank);
	}

	entree.close();

	for (int i=0; i<banks.size(); i++)
	{
		banks[i]= trouverPlusGrandLigne(banks[i]);
	}

	long long somme = 0;

	for (int i=0; i<banks.size(); i++)
	{
		somme += stoll(banks[i]);
	}

	cout << "---> " << somme << endl;

	return 0;
}

string trouverPlusGrandLigne(string ligne)
{
    const int K = 12;
    int a_supprimer = ligne.size() - K;
    
    string resultat = ""; 
    
    for (char chiffre : ligne)
    {
        while (!resultat.empty() && a_supprimer > 0 && chiffre > resultat.back())
        {
            resultat.pop_back();
            a_supprimer--;
        }
        
        resultat.push_back(chiffre); 
    }
    
    while (a_supprimer > 0)
    {
        resultat.pop_back();
        a_supprimer--;
    }

    return resultat.substr(0, K);
}