#include <iostream>
using namespace std;
#include <queue>

vector<int> klargestelements(int input[], int n, int k)
{
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int> > max;
    for (int i = 0; i < k; i++)
    {
        max.push(input[i]);
    }
    for (int i = k; i < n; i++)
    {
        if (max.top() < input[i])
        {
            max.pop();
            max.push(input[i]);
        }
    }
    while (!max.empty())
    {
        ans.push_back(max.top());
        max.pop();
    }
    return ans;
}
vector<int> ksmallestelements(int input[], int n, int k)
{
    vector<int> ans;
    priority_queue<int> min;
    for (int i = 0; i < k; i++)
    {
        min.push(input[i]);
    }
    for (int i = k; i < n; i++)
    {
        if (min.top() > input[i])
        {
            min.pop();
            min.push(input[i]);
        }
    }
    while (!min.empty())
    {
        ans.push_back(min.top());
        min.pop();
    }
    return ans;
}
void Ksortedarray(int input[], int n, int k)
{
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(input[i]);
    }
    int j = 0;
    for (int i = k; i < n; i++)
    {
        input[j] = pq.top();
        pq.pop();
        pq.push(input[i]);
        j++;
    }

    while (!pq.empty())
    {
        input[j] = pq.top();
        pq.pop();
        j++;
    }
}
int main()
{
    // int input[] = {12, 15, 6, 7, 9};
    // Ksortedarray(input, 5, 3);
    // for (int i = 0; i < 5; i++)
    // {
    //     cout << input[i] << " ";
    // }
    // cout << endl;
    int size;
    cin >> size;
    int *input = new int[size];
    for (int i = 0; i < size; i++)
    {
        cin >> input[i];
    }
    int k;
    cin >> k;
    // vector<int> output = ksmallestelements(input, size, k);
    vector<int> output = klargestelements(input, size, k);
    // sort(output.begin(), output.end());
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << " ";
    }
    cout << endl;
    delete[] input;
}