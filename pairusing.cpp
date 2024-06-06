#include <iostream>
using namespace std;
#include "makepair.cpp"
int main()
{
    //     makepair<int> p1;
    //     p1.setX(10);
    //     p1.setY(20);
    //     makepair<double> p2;
    //     p2.setX(100.34);
    //     p2.setY(34.21);
    //     cout << p1.getX() << " " << p1.getY() << endl;
    //     cout << p2.getX() << " " << p2.getY() << endl;
    makepair<int, double> p1;
    p1.setX(10);
    p1.setY(100.56);
    cout << p1.getX() << " " << p1.getY() << endl;
}