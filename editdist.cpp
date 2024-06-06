#include <iostream>
using namespace std;

int editdistDP(string s, string t)
{
    int m = s.size();
    int n = t.size();
    int **output = new int *[m + 1];
    for (int i = 0; i < m + 1; i++)
    {
        output[i] = new int[n + 1];
    }
    for (int i = 0; i <= m; i++)
    {
        output[i][0] = i;
    }
    for (int j = 1; j <= n; j++)
    {
        output[0][j] = j;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[m - i] == t[n - j])
            {
                output[i][j] = output[i - 1][j - 1];
            }
            else
            {
                int i = output[i - 1][j];
                int d = output[i][j - 1];
                int r = output[i - 1][j - 1];
                output[i][j] = min(i, min(d, r)) + 1;
            }
        }
    }
    return output[m][n];
}

int editdistmem_helper(string s, string t, int **output)
{
    if (s.size() == 0 || t.size() == 0)
    {
        return max(s.size(), t.size());
    }
    int m = s.size();
    int n = t.size();
    if (output[m][n] != -1)
    {
        return output[m][n];
    }
    if (s.size() == 0 || t.size() == 0)
    {
        output[m][n] = max(s.size(), t.size());
    }

    if (s[0] == t[0])
    {
        return editdistmem_helper(s.substr(1), t.substr(1), output);
    }
    else
    {
        int i = editdistmem_helper(s.substr(1), t, output);
        int d = editdistmem_helper(s, t.substr(1), output);
        int r = editdistmem_helper(s.substr(1), t.substr(1), output);
        output[m][n] = min(i, min(d, r)) + 1;
        return output[m][n];
    }
}

int editdistmem(string s, string t)
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
    return editdistmem_helper(s, t, output);
}

int editdist(string s, string t)
{
    if (s.size() == 0 || t.size() == 0)
    {
        return max(s.size(), t.size());
    }

    if (s[0] == t[0])
    {
        return editdist(s.substr(1), t.substr(1));
    }
    else
    {
        int i = editdist(s.substr(1), t);
        int d = editdist(s, t.substr(1));
        int r = editdist(s.substr(1), t.substr(1));
        return min(i, min(d, r)) + 1;
    }
}

int main()
{
    string s;
    cin >> s;
    string t;
    cin >> t;
    cout << editdistDP(s, t) << endl;
}