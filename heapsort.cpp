#include <iostream>
using namespace std;
void sort(int input[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int childindex = i;
        while (childindex > 0)
        {
            int parentindex = (childindex - 1) / 2;
            if (input[childindex] < input[parentindex])
            {
                int temp = input[childindex];
                input[childindex] = input[parentindex];
                input[parentindex] = temp;
            }
            else
            {
                break;
            }
            childindex = parentindex;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << input[i] << " ";
    }
    cout << endl;
    // remove
    int size = n;
    while (size > 1)
    {
        int temp = input[0];
        input[0] = input[size - 1];
        input[size - 1] = temp;

        size--;
        cout << size << endl;
        int parentindex = 0;
        int leftchildlindex = 2 * parentindex + 1;
        int rightchildindex = 2 * parentindex + 2;

        while (leftchildlindex < size)
        {
            int minindex = parentindex;
            if (input[minindex] > input[leftchildlindex])
            {
                minindex = leftchildlindex;
            }
            if (input[minindex] > input[rightchildindex] && rightchildindex < size)
            {
                minindex = rightchildindex;
            }
            if (minindex == parentindex)
            {
                break;
            }
            int temp1 = input[minindex];
            input[minindex] = input[parentindex];
            input[parentindex] = temp1;
            parentindex = minindex;

            leftchildlindex = 2 * parentindex + 1;
            rightchildindex = 2 * parentindex + 2;
        }
    }
}

int main()
{
    cout << "Enter the array size" << endl;
    int n;
    cin >> n;
    cout << "Enter the value of array" << endl;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // int a[] = {5, 1, 2, 8, 0};
    sort(a, n);
    for (int i = 0; i < 5; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    // 5 8 1 2 0
}