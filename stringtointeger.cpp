#include <iostream>
using namespace std;

int STI(string s)
{
    int x = 0;
    if (s.length() == 0)
    {
        return 0;
    }
    for (int i = 0; i < s.length(); i++)
    {
        x = x + (pow(10, i) * s[i]);
    }
    return x;
}

int main()
{
    string s;
    cin >> s;
    cout << s;
    int x = STI(s);
    cout << x;
}