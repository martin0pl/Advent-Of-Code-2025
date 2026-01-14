#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

class Point
{
private:
    long long _x;
    long long _y;
    long long _z;

public:

    Point(long long x, long long y, long long z);

    Point(string);

    long long distance(Point) const;

    long long aire(Point) const;
};

class Liaison 
{
private:
    long long _distance;
    int _indexA;
    int _indexB;

public:
    Liaison(long long distance, int a, int b);

    long long getDistance() const { return _distance; } 
    int getIndexA() const { return _indexA; }
    int getIndexB() const { return _indexB; }

    bool operator<(const Liaison& autre) const {
        return _distance < autre._distance;
    }
};

void triInsertionLiaisons(vector<Liaison> &liaisons);
int estConnecte(const vector<vector<int>> &connexions, int indiceCherche); //renvoit l'indice du vecteur où il est

int main(){

    vector<Point> points;

    string ligne;

    ifstream entree;
    entree.open("input.txt");

    while (getline(entree, ligne))
    {
        if (!ligne.empty()) points.push_back(Point(ligne));
    }

    entree.close();

    vector<Liaison> liaisons;

    vector<vector<int>> connexions;

    for (int i=0; i<points.size(); i++)
    {
        for (int j=i+1; j<points.size(); j++)
        {
            liaisons.push_back(Liaison(points[i].distance(points[j]),i,j));
        }
    }

    sort(liaisons.begin(),liaisons.end());

    const int nbPairesAFaire = 1000;

    for (int i=0; i<nbPairesAFaire; i++)
    {
        int indiceConnexionA = estConnecte(connexions,liaisons[i].getIndexA());
        int indiceConnexionB = estConnecte(connexions,liaisons[i].getIndexB());

        // si les deux ne sont pas dans la liste des connexions
        // création d'une nouvelle liaison
        if (indiceConnexionA==-1 && indiceConnexionB==-1)
        {
            vector<int> v;
            v.push_back(liaisons[i].getIndexA());
            v.push_back(liaisons[i].getIndexB());
            connexions.push_back(v);
        }
        // si A est connecté et B n'est pas connecté
        // ajout de B dans la laison de A
        else if (indiceConnexionA!=-1 && indiceConnexionB==-1)
        {
            int indiceConnexionA = estConnecte(connexions,liaisons[i].getIndexA());
            connexions[indiceConnexionA].push_back(liaisons[i].getIndexB());
        }
        // si B est connecté et A n'est pas connecté
        // ajout de A dans la laison de B
        else if (indiceConnexionA==-1 && indiceConnexionB!=-1)
        {
            int indiceConnexionB = estConnecte(connexions,liaisons[i].getIndexB());
            connexions[indiceConnexionB].push_back(liaisons[i].getIndexA());
        }
        // si A est connecté et B est connecté
        // fusion des deux liaisons
        else 
        {
            if (indiceConnexionA != indiceConnexionB)
            {
                connexions[indiceConnexionA].insert(connexions[indiceConnexionA].end(), connexions[indiceConnexionB].begin(), connexions[indiceConnexionB].end()
                );
                
                connexions.erase(connexions.begin() + indiceConnexionB);
            }
        }
    }

    // comptage des trois plus grandes tailles
    long long maxa = 0, indicea;
    long long maxb = 0, indiceb;
    long long maxc = 0, indicec;
    for (int i=0;i<3; i++)
    {
        for (int j=0; j<connexions.size(); j++)
        {
            if (i==0 && connexions[j].size()>maxa)
            {
                maxa = connexions[j].size();
                indicea = j;
            }
            else if (i==1 && connexions[j].size()>maxb && j!=indicea)
            {
                maxb = connexions[j].size();
                indiceb = j;
            }
            else if (i==2 && connexions[j].size()>maxc && j!=indicea && j!=indiceb)
            {
                maxc = connexions[j].size();
                indicec = j;
            }
        }
    }

    /*
    // affichage des liaisons
    for (int i=0; i<connexions.size(); i++)
    {
        for (int j=0; j<connexions[i].size(); j++)
        {
            cout << connexions[i][j] << " ";
        }
        cout << endl;
    }
    */

    cout << "----> " << maxa * maxb * maxc << endl;

	return 0;
}

Point::Point(long long x, long long y, long long z)
{
    _x = x;
    _y = y;
    _z = z;
}

Point::Point(string ligne)
{
    string xs;
    string ys;
    string zs;

    int virgulePassee = 0;

    for (char c : ligne)
    {
        if (c==',') virgulePassee++;
        else if (virgulePassee==0) xs.push_back(c);
        else if (virgulePassee==1) ys.push_back(c);
        else zs.push_back(c);
    }

    if (!xs.empty()) _x = stoll(xs);
    if (!ys.empty()) _y = stoll(ys);
    if (!zs.empty()) _z = stoll(zs);
}

long long Point::distance(Point autre) const
{
    return(sqrt(pow((autre._x-_x),2)+pow((autre._y-_y),2)+pow((autre._z-_z),2)));
}

Liaison::Liaison(long long distance, int a, int b)
{
    _distance = distance;
    _indexA = a;
    _indexB = b;
}

void triInsertionLiaisons(vector<Liaison> &liaisons)
{
    int n = liaisons.size();

    for (int i = 1; i < n; i++)
    {
        Liaison cle = liaisons[i];
        int j = i - 1;

        while (j >= 0 && liaisons[j].getDistance() > cle.getDistance())
        {
            liaisons[j + 1] = liaisons[j];
            j = j - 1;
        }

        liaisons[j + 1] = cle;
    }
}

int estConnecte(const vector<vector<int>> &connexions, int indiceCherche)
{
    int indice = -1;
    bool trouve = false;

    if (indiceCherche!=-1)
    {
        for (int i=0; !trouve && i<connexions.size(); i++)
        {
            for (int j=0; !trouve && j<connexions[i].size(); j++)
            {
                if (connexions[i][j]==indiceCherche)
                {
                    trouve = true;
                    indice = i;
                }
            }
        }
    }   

    return(indice);
}