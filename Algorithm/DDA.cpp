#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double x1, x2, y1, y2;
    cout << "DDA\n";
    cout << "Enter the start point(x,y): ";
    cin >> x1 >> y1;

    cout << "Enter the final point(x,y): ";
    cin >> x2 >> y2;

    double m = (y2-y1)/(x2-x1);

    double x=x1, y=y1;

    cout << "All points: " << "(" << x << ", " << y << ")  ";

    if(m==1)
    {
        while(!(x==x2 && y==y2))
        {
            cout << "(" << ++x << ", " << ++y << ")  ";
        }
    }
    else if(m<1)
    {
        while(!(x==x2 && round(y)==y2))
        {
            y += m;
            cout << "(" << ++x << ", " << round(y) << ")  ";
        }

    }
    else
    {
        while(!(round(x)==x2 && y==y2))
        {
            x += 1/m;
            cout << "(" << round(x) << ", " << ++y << ")  ";
        }
    }

    return 0;
}