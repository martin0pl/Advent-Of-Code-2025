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
    entree.open("input.txt");

    getline(entree, contenu);

    entree.close();

    string cible;
  	int cpt = 0;
  	// Séparation des intervalles (même code, OK)
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
    // Ajout du dernier intervalle
    if (!cible.empty()) {
        intervalles.push_back(cible);
    }

  	string debut;
  	string fin;
    long long debutInt;
  	long long finInt;
  	bool barrePassée = false;
  	
  	string valeurstring;
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

  		for (long long i = debutInt; i<=finInt; i++)
  		{
            valeurstring = to_string(i);
            bool seRepete = false; 

  			for (long long longueur = 1; longueur <= valeurstring.length() / 2; longueur++)
  			{
  				if (valeurstring.length() % longueur == 0)
  				{
	  				motif = valeurstring.substr(0, longueur);
                    seRepete = true; // On part du principe qu'il se répète

                    for (long long cpt2 = 1; cpt2 < valeurstring.length() / longueur; cpt2++)
                    {
                        if (valeurstring.substr(cpt2 * longueur, longueur) != motif)
                        {
                            seRepete = false; // Non, ce n'est pas un motif répétitif
                            break;
                        }
                    }

                    if (seRepete)
                    {
                        invalides.push_back(valeurstring);
                        break; 
                    }
  				}
  			}
  		}
  	}

  	long long somme = 0;

  	for (string s : invalides)
  	{
  		somme += stoll(s);
  	}

    // Le résultat attendu pour cette entrée est 4174379250
  	cout << "-----> " << somme << endl;

	return 0;
}