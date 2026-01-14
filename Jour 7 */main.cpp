#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void affichage(vector<string> &);

int main(){

    vector<string> sapin;
    string ligne;

    ifstream entree;
    entree.open("input.txt");

    while (getline(entree, ligne))
    {
        sapin.push_back(ligne);
    }

    entree.close();

    //affichage(sapin);

    // Premire descente depuis le sommet
    int i=0;
    while (sapin[0][i]!='S')
    {
        i++;
    }
    sapin[1][i]='|';

    //affichage(sapin);

    int nbSeparations = 0;

    for (int i=0; i<sapin.size(); i++)
    {
        for (int j=0; j<sapin[i].size(); j++)
        {
            if (sapin[i][j]=='|' && sapin[i+1][j]=='.')
            {
                sapin[i+1][j]='|';
            }
            else if(sapin[i][j]=='|' && sapin[i+1][j]=='^')
            {
                if (j>0) sapin[i+1][j-1]='|';
                if (j<sapin[i].size()-1) sapin[i+1][j+1]='|';
                nbSeparations++;
            }
        }
        //affichage(sapin);
    }

    cout << "-----> " << nbSeparations << endl;

	return 0;
}

void affichage(vector<string> &sapin)
{
    for (string s : sapin) cout << s << endl;
    cout << endl;
}