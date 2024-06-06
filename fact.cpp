#include <iostream>
using namespace std;

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

int icj(int i, int j)
{
    int k = (factorial(i)) / (factorial(j) * (factorial(i - j)));
    return k;
}
vector<vector<int> > pascalTriangle(int N)
{
    vector<vector<int> > pascalTriangle;
    

    for (int i = 0; i < N; i++)
    {
        vector<int> temp;
        for (int j = 0; j <= i; j++)
        {
            temp.push_back(icj(i, j));
        }
        pascalTriangle.push_back(temp);
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << pascalTriangle[i][j] << " ";
        }
        cout << endl;
    }
    return pascalTriangle;
}
int main()
{
    int n;
    cin >> n;
    pascalTriangle(n);
}