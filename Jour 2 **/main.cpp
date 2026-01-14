#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int main(){

	vector<string> invalides;

	string contenu;

	vector<string> intervalles;

	ifstream entree;
    entree.open("inputtest.txt");

    getline(entree, contenu);

    entree.close();

    string cible;
  	int cpt = 0;
  	while (cpt<contenu.length())
  	{
  		if (contenu[cpt]!=',')
  		{
  			cible.push_back(contenu[cpt]);
  		}
  		else
  		{
  			intervalles.push_back(cible);
  			cible = "";
  		}
  		cpt++;
  	}

  	string debut;
  	string fin;
    long long debutInt;
  	long long finInt;
  	bool barrePassée = false;
  	bool invalid = false;
  	bool seRepete = false;
  	string valeurstring;
  	long long cpt2 = 0;
  	string motif;

  	for (string i : intervalles)
  	{
  		debut = "";
  		fin = "";
  		barrePassée = false;

  		for (char c : i)
  		{
  			if (!barrePassée && c!='-')
  			{
  				debut.push_back(c);
  			} 
  			else if (c=='-')
  			{
  				barrePassée = true;
  			}
  			else
  			{
  				fin.push_back(c);
  			}
  		}

  		debutInt = stoll(debut);
  		finInt = stoll(fin);

  		string valeurstring = "";

  		for (long long i = debutInt; i<=finInt; i++)
  		{
  			invalid = true;

  			valeurstring = to_string(i);
  			//if (valeurstring.length()%2==0  &&  valeurstring.substr(0,valeurstring.length()/2) == valeurstring.substr(valeurstring.length()/2,valeurstring.length()/2)) invalid = true;

  			//test de tous les motifs qui peuvent se répéter, donc jusqu'à la moitié de taille
  			for (long long longueur = 1; longueur<valeurstring.length()/2; longueur++)
  			{
  				if (valeurstring.length()%longueur==0)
  				{
	  				motif = valeurstring.substr(0,longueur);
	  				cpt2 = 0;
	  				while (cpt2 < valeurstring.length()%longueur && invalid)
	  				{
	  					invalid = valeurstring.substr(cpt2*longueur,longueur) == motif;
	  					cpt2++;
	  				}
  				}
  				else
  				{
  					invalid = false;
  				}
  			}

  			if (invalid) invalides.push_back(valeurstring);
  		}
  	}

  	long long somme = 0;

  	for (string s : invalides)
  	{
  		somme += stoll(s);
  	}

  	cout << "-----> " << (somme==4174379265) << endl;

	return 0;
}