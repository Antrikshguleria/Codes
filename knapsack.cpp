#include <iostream>
using namespace std;

int knapsack(int *w, int *v, int n, int maxi)
{
    if (n == 0 || maxi == 0)
    {
        return 0;
    }
    if (w[0] > maxi)
    {
        return knapsack(w + 1, v + 1, n - 1, maxi);
    }
    int a = knapsack(w + 1, v + 1, n - 1, maxi - w[0]) + v[0];
    int b = knapsack(w + 1, v + 1, n - 1, maxi);
    return max(a, b);
}

int main()
{
    int n;
    cin >> n;
    int *w = new int[n];
    int *v = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int maxi;
    cin >> maxi;
    cout << knapsack(w, v, n, maxi) << endl;
}