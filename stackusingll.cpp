#include <iostream>
using namespace std;
template <typename t>
class node
{
public:
    t data;
    node<t> *next;
    node(t data)
    {
        this->data = data;
        next = NULL;
    }
};
template <typename t>
class stack
{
    node<t> *head;
    int size;

public:
    stack()
    {
        head = NULL;
        size = 0;
    }
    int getsize()
    {
        cout << size << endl;
        return 0;
    }
    bool isempty()
    {
        if (size == 0)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        return 0;
    }
    void push(t element)
    {
        node<t> *newnode = new node<t>(element);
        newnode->next = head;
        head = newnode;
        size++;
    }
    t pop()
    {
        if (size == 0)
        {
            cout << "stack is empty" << endl;
            return 0;
        }
        cout << head->data << endl;
        node<t> *temp = head;
        t ans = head->data;
        head = head->next;
        size--;
        delete temp;
        return ans;
    }
    t top()
    {
        if (isempty())
        {
            return 0;
        }
        cout << head->data << endl;
        return 0;
    }
};
int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.getsize();
    s.isempty();
    s.push(40);
    s.pop();
    s.top();
    s.pop();
    s.pop();
    s.pop();
    s.getsize();
    s.isempty();
}