#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

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

	int indice;
	int plusPetit;

	for (string &b : banks)
	{
		for (int i=0; i<b.size()-12; i++)
		{
			plusPetit = 10;
			indice = -1;
			for (int j=0; j<b.size(); j++)
			{
				if (b[j]!='-' && (b[j]-'0')<=plusPetit)
				{
					plusPetit = (b[j]-'0');
					indice = j;
				}
			}
			b[indice]='-';
		}
	}

	vector<string> banksBis;
	string bankBis;

	for (int i=0; i<banks.size(); i++)
	{
		bankBis = "";
		for (int j=0; j<banks[i].size(); j++)
		{
			if (banks[i][j]!='-') bankBis.push_back(banks[i][j]);
		}
		banksBis.push_back(bankBis);
	}

	long long somme = 0;
	
	for (string b : banksBis)
	{
		cout << b << endl;
		somme += stoll(b);
	}

	cout << "----> " << (somme==3121910778619) << endl;

	return 0;
}