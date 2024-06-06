#include <iostream>
using namespace std;

int mincost_dp(int **input, int m, int n)
{
    int **output = new int *[m];
    for (int i = 0; i < m; i++)
    {
        output[i] = new int[n];
    }

    output[m - 1][n - 1] = input[m - 1][n - 1];

    for (int j = n - 2; j >= 0; j--) // last row
    {
        output[m - 1][j] = output[m - 1][j + 1] + input[m - 1][j];
    }

    for (int i = m - 2; i >= 0; i--) // last column
    {
        output[i][n - 1] = output[i + 1][n - 1] + input[i][n - 1];
    }

    // remaining cell
    for (int i = m - 2; i >= 0; i--)
    {
        for (int j = n - 2; j >= 0; j--)
        {
            output[i][j] = min(output[i][j + 1], min(output[i + 1][j + 1], output[i + 1][j])) + input[i][j];
        }
    }

    return output[0][0];
}

int mincostpath_mem(int **input, int m, int n, int i, int j, int **output)
{

    if (i == m - 1 && j == n - 1)
    {
        return input[i][j];
    }

    if (i >= m || j >= n)
    {
        return INT_MAX;
    }

    if (output[i][j] != -1)
    {
        return output[i][j];
    }

    int x = mincostpath_mem(input, m, n, i, j + 1, output);
    int y = mincostpath_mem(input, m, n, i + 1, j + 1, output);
    int z = mincostpath_mem(input, m, n, i + 1, j, output);

    int ans = min(x, min(y, z)) + input[i][j];
    output[i][j] = ans;
    return ans;
}

int mincost_mem(int **input, int m, int n)
{
    int **output = new int *[m];
    for (int i = 0; i < m; i++)
    {
        output[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            output[i][j] = -1;
        }
    }
    return mincostpath_mem(input, m, n, 0, 0, output);
}

int mincosthelper(int **input, int m, int n, int i, int j)
{
    if (i == m - 1 && j == n - 1)
    {
        return input[i][j];
    }

    if (i >= m || j >= n)
    {
        return INT_MAX;
    }

    int x = mincosthelper(input, m, n, i, j + 1);
    int y = mincosthelper(input, m, n, i + 1, j + 1);
    int z = mincosthelper(input, m, n, i + 1, j);

    int ans = min(x, min(y, z)) + input[i][j];
    return ans;
}

int mincost(int **input, int m, int n)
{
    return mincosthelper(input, m, n, 0, 0);
}

int main()
{
    int m, n;
    cout << "enter the number of rows and columns:" << endl;
    cin >> m >> n;
    int **a = new int *[m];
    for (int i = 0; i < m; i++)
    {
        a[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << mincost(a, m, n) << endl;
    cout << mincost_mem(a, m, n) << endl;
    cout << mincost_dp(a, m, n) << endl;
}