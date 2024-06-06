#include <iostream>
using namespace std;

pair<int, int> missingAndRepeating(vector<int> &arr, int n)
{
    pair<int, int> p;
    unordered_map<int, int> store;
    for (int i = 0; i < arr.size(); i++)
    {
        store[arr[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (store[i] == 0)
            p.first = i;
        else if (store[i] == 2)
            p.second = i;
    }
    if (p.first == 0)
        p.first = n;
    return p;
}
int main()
{
    vector<int> A;
    int n;
    int a;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        A.push_back(a);
    }
    pair<int, int> p = missingAndRepeating(A, n);
    cout << p.first << " " << p.second << endl;
}