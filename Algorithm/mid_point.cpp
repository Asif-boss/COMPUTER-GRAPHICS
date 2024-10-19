#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double x1, x2, y1, y2;
    cout << "Mid Point\n";
    cout << "Enter the start point(x,y): ";
    cin >> x1 >> y1;

    cout << "Enter the final point(x,y): ";
    cin >> x2 >> y2;

    double m = (y2-y1)/(x2-x1);
    double dy=(y2-y1), dx=(x2-x1);

    double x=x1, y=y1;
    double d;

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
        d=2*dy-dx;

        while(!(x==x2 && y==y2))
        {


            if(d>0)
            {
                cout << "(" << ++x << ", " << ++y << ")  ";
                d += 2*(dy-dx);
            }
            else
            {
                cout << "(" << ++x << ", " << y << ")  ";
                d += 2*dy;
            }

        }

    }
    else
    {
        d=2*dy-dx;

        while(!(x==x2 && y==y2))
        {
            if(d>0)
            {
                cout << "(" << ++x << ", " << ++y << ")  ";
                d += 2*(dx-dy);
            }
            else
            {
                cout << "(" << ++x << ", " << y << ")  ";
                d += 2*dx;
            }
        }
    }

    return 0;
}
