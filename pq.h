#include <vector>
class pq
{
    vector<int> p;

public:
    pq()
    {
    }

    bool isEmpty()
    {
        return p.size() == 0;
    }

    int getsize()
    {
        return p.size();
    }

    int getmin()
    {
        if (isEmpty())
        {
            return 0;
        }
        return p[0];
    }

    void insert(int element)
    {
        p.push_back(element);
        int childindex = p.size() - 1;
        while (childindex > 0)
        {
            int parentindex = (childindex - 1) / 2;
            if (p[childindex] < p[parentindex])
            {
                int temp = p[childindex];
                p[childindex] = p[parentindex];
                p[parentindex] = temp;
            }
            childindex = parentindex;
        }
    }

    int removemin()
    {
        if (isEmpty())
        {
            return 0;
        }
        int ans = p[0];
        p[0] = p[p.size() - 1];
        p.pop_back();
        int parentindex = 0;
        int leftchilindex = 2 * parentindex + 1;
        int rightchilindex = 2 * parentindex + 2;
        while (leftchilindex < p.size())
        {
            int minIndex = parentindex;
            if (p[minIndex] > p[leftchilindex])
            {
                minIndex = leftchilindex;
            }
            if (p[minIndex] > p[rightchilindex] && rightchilindex < p.size())
            {
                minIndex = rightchilindex;
            }
            if (minIndex == parentindex)
            {
                break;
            }

            int temp = p[minIndex];
            p[minIndex] = p[parentindex];
            p[parentindex] = temp;
            parentindex = minIndex;
            leftchilindex = 2 * parentindex + 1;
            rightchilindex = 2 * parentindex + 2;
        }
        return ans;
    }
};
