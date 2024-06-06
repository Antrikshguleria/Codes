#include <iostream>
using namespace std;

string replace(string s)
{
    if (s.length() == 0)
    {
        return s;
    }
    //string smallOutput = replace(s.substr(2));
    if (s[0] == 'p' && s[1] == 'i')
    {
        string smallOutput = replace(s.substr(2));
        return "3.14" + smallOutput;
    }
    else
    {
        return s[0] + replace(s.substr(1));
    }
}

int main()
{
    string s;
    cin >> s;
    string result = replace(s);
    cout << result << endl;
}