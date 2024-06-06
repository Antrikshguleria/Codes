#include <iostream>
using namespace std;

vector<int> nextGreaterPermutation(vector<int> &A)
{
    unordered_map<int, int> store;
    for (int i = 0; i < A.size(); i++)
    {
        store[A[i]]++;
    }
    cout << "O occur " << store[0] << endl;
    cout << "1 occur " << store[1] << endl;
    cout << "2 occur " << store[2] << endl;
    int i = 0;
    for (; store[0] != 0; i++)
    {
        A[i] = 0;
        store[0]--;
    }
    for (; store[1] != 0; i++)
    {
        A[i] = 1;
        store[1]--;
    }
    for (; store[2] != 0; i++)
    {
        A[i] = 2;
        store[2]--;
    }
    return A;
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
    A = nextGreaterPermutation(A);
    for (int i = 0; i < n; i++)
    {
        cout << A[i];
    }
}