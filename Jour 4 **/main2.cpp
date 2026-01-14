#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

bool estAccessible(vector<string>, int, int);
vector<string> ciblerAccessibles(vector<string>);
bool papierAEnlever(vector<string>);
int enleverPapier(vector<string> &);

int main(){

	string rangée;
	vector<string> armoire;
	bool papieraenlever = true;

	ifstream entree;
    entree.open("input.txt");

    while (getline(entree, rangée))
    {
    	armoire.push_back(rangée);
    }

	entree.close();

	int somme = 0;

	armoire = ciblerAccessibles(armoire);
	papieraenlever = papierAEnlever(armoire);
	while (papieraenlever)
	{
		somme += enleverPapier(armoire);
		armoire = ciblerAccessibles(armoire);
		papieraenlever = papierAEnlever(armoire);
	}

	cout << "-----> " << somme << endl;

	return 0;
}

bool estAccessible(vector<string> armoire, int i, int j)
{
	int somme = 0;
    int max_i = armoire.size() - 1; 
    int max_j = (max_i >= 0) ? armoire[i].size() - 1 : 0; 

	if (i > 0) {
        if (j > 0 && armoire[i-1][j-1]=='@') somme++;
        if (armoire[i-1][j]=='@') somme++;
        if (j < max_j && armoire[i-1][j+1]=='@') somme++;
    }

    if (j > 0 && armoire[i][j-1]=='@') somme++;
    if (j < max_j && armoire[i][j+1]=='@') somme++;

    if (i < max_i) { 
        if (j > 0 && armoire[i+1][j-1]=='@') somme++;
        if (armoire[i+1][j]=='@') somme++;
        if (j < max_j && armoire[i+1][j+1]=='@') somme++;
    }

	return(somme<4);
}

vector<string> ciblerAccessibles(vector<string> armoire)
{
	vector<string> sortie = armoire;
	for (int i=0; i<armoire.size(); i++)
	{
		for (int j=0; j<armoire[i].size(); j++)
		{
			if (armoire[i][j]=='@' && estAccessible(armoire,i,j)) sortie[i][j]='x';
		}
	}
	return sortie;
}

bool papierAEnlever(vector<string> armoire)
{
	bool papieraenlever = false;
	int cpt=0;

	while (!papieraenlever && cpt<armoire.size())
	{
		for (char c : armoire[cpt])
		{
			if (c=='x') papieraenlever = true;;
		}
		cpt++;
	}
	return papieraenlever;
}

int enleverPapier(vector<string> &armoire)
{
	int somme = 0;

	for (int i=0; i<armoire.size(); i++)
	{
		for (int j = 0; j<armoire[i].size(); j++)
		{
			if (armoire[i][j]=='x')
			{
				somme++;
				armoire[i][j]='.';
			}
		}
	}

	return somme;	
}