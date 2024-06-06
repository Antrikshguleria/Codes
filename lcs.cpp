#include <iostream>
using namespace std;

int lcsdp(string s, string t)
{
    int m = s.size();
    int n = t.size();

    int **output = new int *[m];
    for (int i = 0; i <= m; i++)
    {
        output[i] = new int[n + 1];
    }

    for (int i = 0; i <= m; i++)
    {
        output[i][0] = 0;
    }
    for (int i = 0; i <= n; i++)
    {
        output[0][i] = 0;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[m - i] == t[n - j])
            {
                output[i][j] = 1 + output[i - 1][j - 1];
            }
            else
            {
                int a = output[i - 1][j];
                int b = output[i][j - 1];
                int c = output[i - 1][j - 1];
                output[i][j] = max(a, max(b, c));
            }
        }
    }

    return output[m][n];
}

int lcsmemhelper(string s, string t, int **output)
{
    if (output[s.size()][t.size()] != -1)
    {
        return output[s.size()][t.size()];
    }
    if (s.size() == 0 || t.size() == 0)
    {
        return 0;
    }
    if (s[0] == t[0])
    {
        output[s.size()][t.size()] = 1 + lcsmemhelper(s.substr(1), t.substr(1), output);
        return output[s.size()][t.size()];
    }
    else
    {
        int a = lcsmemhelper(s.substr(1), t, output);
        int b = lcsmemhelper(s, t.substr(1), output);
        output[s.size()][t.size()] = max(a, b);
        return output[s.size()][t.size()];
    }
}

int lcsmem(string s, string t)
{
    int **output = new int *[s.size() + 1];
    for (int i = 0; i < s.size() + 1; i++)
    {
        output[i] = new int[t.size() + 1];
        for (int j = 0; j < t.size() + 1; j++)
        {
            output[i][j] = -1;
        }
    }
    return lcsmemhelper(s, t, output);
}

int lcs(string s, string t)
{
    if (s.size() == 0 || t.size() == 0)
    {
        return 0;
    }
    if (s[0] == t[0])
    {
        return 1 + lcs(s.substr(1), t.substr(1));
    }
    else
    {
        int a = lcs(s.substr(1), t);
        int b = lcs(s, t.substr(1));
        // int c = lcs(s.substr(1), t.substr(1));
        return max(a, b);
    }
}

int main()
{
    string s;
    string t;
    cin >> s;
    cin >> t;
    cout << lcsdp(s, t) << endl;
}