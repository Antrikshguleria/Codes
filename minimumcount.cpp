#include <iostream>
using namespace std;

int mincounthelper_mem(int n, int *ans)
{
    if (ans[n] != -1)
    {
        return ans[n];
    }
    if (n == 0)
    {
        return 0;
    }
    int smallans = INT_MAX;
    for (int i = 1; i * i <= n; i++)
    {
        smallans = min(smallans, mincounthelper_mem(n - (i * i), ans));
    }
    ans[n] = smallans + 1;
    return ans[n];
}

int mincount_mem(int n)
{
    int *ans = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        ans[i] = -1;
    }
    return mincounthelper_mem(n, ans);
}


int mincount(int n)
{
    if (n == 0)
    {
        return 0;
    }
    int ans = INT_MAX;
    for (int i = 1; i * i <= n; i++)
    {
        ans = min(ans, mincount(n - (i * i)));
    }
    return ans + 1;
}

int main()
{
    int n;
    cin >> n;
    cout << mincount_mem(n) << endl;
}