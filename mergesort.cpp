#include <iostream>
using namespace std;
void merge(int arr[], int start, int mid, int end)
{
    int n1 = mid - start + 1;
    int n2 = end - mid;
    int a[n1];
    int b[n2];
    for (int i = 0; i < n1; i++)
    {
        a[i] = arr[start + i];
    }
    for (int i = 0; i < n2; i++)
    {
        b[i] = arr[mid + i + 1];
    }
    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            arr[start] = a[i];
            start++;
            i++;
        }
        if (a[i] > b[j])
        {
            arr[start] = b[j];
            start++;
            j++;
        }
    }
    while (i < n1)
    {
        arr[start] = a[i];
        start++;
        i++;
    }
    while (j < n2)
    {
        arr[start] = b[j];
        start++;
        j++;
    }
}
void mergesort(int arr[], int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int mid = (start + end) / 2;
    mergesort(arr, start, mid);
    mergesort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    mergesort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
}