#include <iostream>
using namespace std;

int staircase_helper(int n, int *ans)
{
    if (ans[n] != -1)
    {
        return ans[n];
    }
    if (n <= 1)
    {
        return 1;
    }
    int x = staircase_helper(n - 1, ans);
    int y = 0, z = 0;
    if (n >= 2)
    {
        y = staircase_helper(n - 2, ans);
    }
    if (n >= 3)
    {
        z = staircase_helper(n - 3, ans);
    }
    ans[n] = x + y + z;
    return ans[n];
}

int staircase(int n)
{
    int *ans = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        ans[i] = -1;
    }
    return staircase_helper(n, ans);
}

int main()
{
    int n;
    cin >> n;
    cout << staircase(n) << endl;
}