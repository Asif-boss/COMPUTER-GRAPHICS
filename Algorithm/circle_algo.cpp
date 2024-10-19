#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    int x, y, r;
    vector<int> vec_x, vec_y;
    cout << "Find out (x, y) point for circle:\n\n";
    cout << "Enter the center point(x, y): ";
    cin >> x >> y;

    cout << "Enter the radious: ";
    cin >> r;

    int d = 1-r;
    int xp=0, yp=r;

    vec_x.push_back(xp+x);
    vec_y.push_back(yp+y);

    cout << "(x, y) points: " << "(" << xp+x << ", " << yp+y << ")  ";

    while(xp<yp){
        if(d<0){
            d = d+(2*xp)+3;
            xp++;
            if (xp>yp) break;
            vec_x.push_back(xp+x);
            vec_y.push_back(yp+y);
            cout << "(" << xp+x << ", " << yp+y << ")  ";
            
        }else{
            d = d+2*(xp-yp)+5;
            xp++;
            yp--;
            if (xp>yp) break;
            vec_x.push_back(xp+x);
            vec_y.push_back(yp+y);
            cout << "(" << xp+x << ", " << yp+y << ")  ";
        }
    }

    cout << "\n(y, x) points: ";

    for (int i = 0; i < vec_x.size(); i++){
        cout << "(" << vec_y[i] << ", " << vec_x[i] << ")  ";
    }

    cout << "\n(y, -x) points: ";

    for (int i = 0; i < vec_x.size(); i++){
        cout << "(" << vec_y[i] << ", -" << vec_x[i] << ")  ";
    }
    
    cout << "\n(x, -y) points: ";

    for (int i = 0; i < vec_x.size(); i++){
        cout << "(" << vec_x[i] << ", -" << vec_y[i] << ")  ";
    }

    cout << "\n(-x, -y) points: ";

    for (int i = 0; i < vec_x.size(); i++){
        cout << "(-" << vec_x[i] << ", -" << vec_y[i] << ")  ";
    }

    cout << "\n(-y, -x) points: ";

    for (int i = 0; i < vec_x.size(); i++){
        cout << "(-" << vec_y[i] << ", -" << vec_x[i] << ")  ";
    }

    cout << "\n(-y, x) points: ";

    for (int i = 0; i < vec_x.size(); i++){
        cout << "(-" << vec_y[i] << ", " << vec_x[i] << ")  ";
    }

    cout << "\n(-x, y) points: ";

    for (int i = 0; i < vec_x.size(); i++){
        cout << "(-" << vec_x[i] << ", " << vec_y[i] << ")  ";
    }

    return 0;
}
