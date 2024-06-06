#include <iostream>
// #include <cmath>
using namespace std;

int minstep_helper(int n, int *ans)
{
    if (n <= 1)
    {
        return 0;
    }
    if (ans[n] != -1)
    {
        return ans[n];
    }
    int x = minstep_helper(n - 1, ans);

    int y = INT_MAX, z = INT_MAX;
    if (n % 2 == 0)
    {
        y = minstep_helper(n / 2, ans);
    }
    if (n % 3 == 0)
    {
        z = minstep_helper(n / 3, ans);
    }
    int output = min(x, min(y, z)) + 1;
    ans[n] = output;
    return ans[n];
}

int minsteps_1(int n)
{
    int *ans = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        ans[i] = -1;
    }
    return minstep_helper(n, ans);
}

// int minsteps(int n)
// {
//     if (n <= 1)
//     {
//         return 0;
//     }
//     int x = minsteps(n - 1);

//     int y = INT_MAX, z = INT_MAX;
//     if (n % 2 == 0)
//     {
//         y = minsteps(n / 2);
//     }
//     if (n % 3 == 0)
//     {
//         z = minsteps(n / 3);
//     }
//     int ans = min(x, min(y, z)) + 1;
//     return ans;
// }

int main()
{

    int n;
    cin >> n;
    cout << minsteps_1(n) << endl;
}