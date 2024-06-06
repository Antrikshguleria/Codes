#include <iostream>
using namespace std;

int notrees(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    int mod = (int)(pow(10, 9)) + 7;
    int x = notrees(n - 1);
    int y = notrees(n - 2);
    int temp1 = (int)(((long)x * x) % mod);
    int temp2 = (int)((2*(long)x * y) % mod);
    int ans = (temp1 + temp2) % mod;
    // int ans = (x * x + 2 * x * y) % mod;
    return ans;
}

int main()
{
    int n;
    cin >> n;
    cout << notrees(n) << endl;
}