#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x = 5;
    int y = 6;

    int * x_p = &x;
    int * y_p = &y;

    cout << "x_p is " << *x_p << endl;
    cout << "y_p is " << *y_p << endl;

    int ** xpp = nullptr;
    int ** ypp = nullptr;

    xpp = &(x_p);
    ypp = &(y_p);
    cout << "xpp is " << **xpp << endl;
    cout << "ypp is " << **ypp << endl;

    xpp = &(y_p);
    ypp = &(x_p);
    cout << "xpp is " << **xpp << endl;
    cout << "ypp is " << **ypp << endl;

    x = 656;
    y = 544;

    cout << "xpp is " << **xpp << endl;
    cout << "ypp is " << **ypp << endl;

}