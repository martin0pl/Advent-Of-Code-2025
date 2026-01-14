#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

bool estAccessible(vector<string>, int, int);

int main(){

	string rangée;
	vector<string> armoire;
	vector<string> armoireResultat;

	ifstream entree;
    entree.open("input.txt");

    while (getline(entree, rangée))
    {
    	armoire.push_back(rangée);
    	armoireResultat.push_back(rangée);
    }

	entree.close();

	for (int i=0; i<armoire.size(); i++)
	{
		for (int j=0; j<armoire[i].size(); j++)
		{
			if (armoire[i][j]=='@' && estAccessible(armoire,i,j)) armoireResultat[i][j]='x';
		}
	}

	int somme = 0;

	for (string r : armoireResultat)
	{
		for (char c : r)
		{
			if (c=='x') somme++;
		}
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