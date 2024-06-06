#include <iostream>
using namespace std;
#include "oops.cpp"
int main()
{
    student s1;
    // student *s2 = new student;
    s1.rollNumber = 101;
    s1.age = 24;
    // (*s2).age = 17;
    // (*s2).rollNumber = 123;
    cout << s1.age << endl;
}