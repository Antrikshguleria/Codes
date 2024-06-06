#include <iostream>
using namespace std;

string removeX(string s)
{
    if (s.length() == 0)
    {
        return s;
    }
    if (s[0] == 'x')
    {
        return removeX(s.substr(1));
    }
    else
    {
        return s.at(0) + removeX(s.substr(1));
    }
    return s;
}

int main()
{
    string s;
    cin >> s;
    string result = removeX(s);
    // s.erase(remove(s.begin(), s.end(), 'x'),s.end());
    cout << result;
}