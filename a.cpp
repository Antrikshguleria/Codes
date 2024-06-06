#include <iostream>
using namespace std;
#include "complesNumber.cpp"
int main()
{
    int real1, real2, imaginary1, imaginary2;
    cin >> real1 >> imaginary1;
    cin >> real2 >> imaginary2;

    complex c1(real1, imaginary1);
    complex c2(real2, imaginary2);

    int choice;
    cin >> choice;

    if (choice == 1)
    {
        c1.add(c2);
        c1.print();
    }

    if (choice == 2)
    {
        c1.multi(c2);
        c1.print();
    }
}
