#include <iostream>
using namespace std;
#include "dynamic.cpp"
int main()
{
    dynamic d1;
    d1.add(10);
    d1.add(20);
    d1.add(30);
    d1.add(40);
    d1.add(50);
    d1.add(60);
    d1.print();
    dynamic d2(d1);
    d1.add(0, 100);
    d1.print();
    d2.print();
    dynamic d3;
    d3 = d1;
    d1.add(0, 200);
    d1.print();
    d3.print();
}