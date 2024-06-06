#include <climits>
template <typename T>
class stackusingarray
{
    T *data;
    int nextindex;
    int capacity;

public:
    stackusingarray()
    {
        data = new T[4];
        nextindex = 0;
        capacity = 4;
    }
    int size()
    {
        return nextindex;
    }
    bool isempty()
    {
        return nextindex == 0;
    }
    void push(T element)
    {
        if (nextindex == capacity)
        {
            //     cout << "my stack is full" << endl;
            T *newdata = new T[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                newdata[i] = data[i];
            }
            capacity *= 2;
            delete[] data;
            data = newdata;
        }
        data[nextindex] = element;
        nextindex++;
    }
    T pop()
    {
        if (isempty())
        {
            cout << "stack is empty" << endl;
            return 0;
        }
        nextindex--;
        return data[nextindex];
    }
    T top()
    {
        if (isempty())
        {
            cout << "stack is empty" << endl;
            return 0;
        }
        return data[nextindex - 1];
    }
};