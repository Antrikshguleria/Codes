#include <string>
using namespace std;
class vehicle
{
private:
    int maxspeed;

protected:
    int numtyres;

public:
    string color;

    vehicle()
    {
        cout << "vehicle default constructor" << endl;
    }

    vehicle(int z)
    {
        maxspeed = z;
        cout << "vehicle paramertized constructor" << endl;
    }
    ~vehicle()
    {
        cout << "vehicle's destructor" << endl;
    }
};