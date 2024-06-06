#include <iostream>
using namespace std;
void permu(string s, int a = 0, int l)
{
    if (l <= 1)
        cout << s;
    for (int i = 0; i < l; i++)
    {
        if(i==a)
            break;
        
    }
}
int main()
{
    string s;
    cin >> s;
    int l = s.size();
    permu(s, l);
}