#include <vector>
#include <climits>
using namespace std;
class maxheap
{
    vector<int> p;

public:

    maxheap()
    {
    }

    int getSize()
    {
        return p.size();
    }

    bool isEmpty()
    {
        return p.size() == 0;
    }

    void insert(int element)
    {
        p.push_back(element);
        int childindex = p.size() - 1;
        while (childindex > 0)
        {
            int parentindex = (childindex - 1) / 2;
            if (p[childindex] > p[parentindex])
            {
                int temp = p[childindex];
                p[childindex] = p[parentindex];
                p[parentindex] = temp;
            }
            childindex = parentindex;
        }
    }

    int getmax()
    {
        if (isEmpty())
        {
            return INT_MIN;
        }
        return p[0];
    }

    int removeMax()
    {
        if (isEmpty())
        {
            return INT_MIN;
        }
        int ans = p[0];
        p[0] = p[p.size() - 1];
        p.pop_back();
        int parentindex = 0;
        int leftchilindex = 2 * parentindex + 1;
        int rightchilindex = 2 * parentindex + 2;
        while (leftchilindex < p.size())
        {
            int maxindex = parentindex;
            if (p[parentindex] < p[leftchilindex])
            {
                maxindex = leftchilindex;
            }
            else if (p[parentindex] < p[rightchilindex] && rightchilindex < p.size())
            {
                maxindex = rightchilindex;
            }
            else if (maxindex == parentindex)
            {
                break;
            }
            int temp = p[maxindex];
            p[maxindex] = p[parentindex];
            p[parentindex] = temp;
        }
        return ans;
    }

    void print()
    {
        for (int i = 0; i < p.size(); i++)
        {
            cout << p[i] << " ";
        }
    }
};