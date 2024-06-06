#include "inheritance.cpp"
class car : public vehicle
{
public:
    int numgears;

    car(int x) : vehicle(x)
    {
        cout << "car's constructor" << endl;
    }

    ~car()
    {
        cout << "car's destructor" << endl;
    }

    void print()
    {
        cout << "number of tyres :" << numtyres << endl;
        cout << "color :" << color << endl;
        cout << "number of gears :" << numgears << endl;
        // cout << " max speed :" << maxspeed << endl; XX
    }
};