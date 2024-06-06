#include <iostream>
using namespace std;
void subsets(int a[], int s, int e)
{
    
}
int main()
{
    int n;
    cin >> n;
    int *p = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    subsets(p, n, n);
}