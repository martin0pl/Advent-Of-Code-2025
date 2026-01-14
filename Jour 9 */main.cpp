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

public:

    Point(long long, long long);

    Point(string);

    long long distance(Point) const;

    long long aire(Point) const;
};

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

    long long aireMax = 0;

    for (int i=0; i<points.size(); i++)
    {
        for (int j=i+1; j<points.size(); j++)
        {
            if (points[i].aire(points[j])>aireMax) aireMax = points[i].aire(points[j]);
        }
    }

    cout << "-----> " << aireMax << endl;

	return 0;
}

Point::Point(long long x, long long y)
{
    _x = x;
    _y = y;
}

Point::Point(string ligne)
{
    string xs;
    string ys;
    bool virgulePassee = false;
    for (char c : ligne)
    {
        if (c==',') virgulePassee=true;
        else if (!virgulePassee) xs.push_back(c);
        else ys.push_back(c);
    }
    if (!xs.empty()) _x = stoll(xs);
    if (!ys.empty()) _y = stoll(ys);
}

long long Point::distance(Point autre) const
{
    return(sqrt(pow((autre._x-_x),2)+pow((autre._y-_y),2)));
}

long long Point::aire(Point autre) const
{
    return((abs(autre._x-_x)+1)*(abs(autre._y-_y)+1));
}