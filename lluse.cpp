#include <iostream>
using namespace std;
#include "ll.cpp"
node *recinsert(node *head, int i, int data)
{

    if (head->next == NULL)
    {
        return head;
    }
    else if (i == 0)
    {
        // node *n1 = new node(data);
        // n1->next = head;
        head->next= recinsert(head->next, i - 1, data);
    }
    return head;
}
int reclength(node *head)
{
    node *n1 = head;
    if (n1->next == NULL)
    {
        return 1;
    }
    else
    {
        return 1 + reclength(n1->next);
    }
}
node *del(node *head, int i)
{
    node *n1 = head;
    int count = 0;
    while (n1->next != NULL)
    {
        if (i == 0)
        {
            head = n1->next;
            delete n1;
            return head;
        }
        if (count == i - 1)
        {
            node *a = n1->next;
            node *b = a->next;
            n1->next = b;
            delete a;
            return head;
        }
        else
        {
            count++;
            cout << count << n1->next << endl;
            n1 = n1->next;
        }
    }
}
int find(node *head, int i)
{
    node *n1 = head;
    int count = 0;
    while (n1->next != NULL)
    {
        if (count == i)
            return n1->data;
        else
        {
            count++;
            n1 = n1->next;
        }
    }
    return 0;
}
node *insert(node *head, int i, int data)
{
    node *newnode = new node(data);
    int count = 0;
    node *temp = head;
    if (i == 0)
    {
        newnode->next = head;
        head = newnode;
        return head;
    }

    while (temp != NULL && count < i - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp != NULL)
    {
        newnode->next = temp->next;
        temp->next = newnode;
    }
    return head;
}
int length(node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}
node *takeinput()
{
    int data;
    cin >> data;
    node *head = NULL;
    node *tail = NULL;
    while (data != -1)
    {
        node *newnode = new node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = tail->next;
        }
        cin >> data;
    }
    return head;
}
void print(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
int main()
{
    node *head = takeinput();
    cout << length(head) << endl;
    // int i, data;
    // cin >> i >> data;
    // head = insert(head, i, data);
    // int j;
    // cin >> j;
    // cout << find(head, j) << endl;
    // print(head);
    // int k;
    // cin >> k;
    // head = del(head, k);
    // print(head);
    // cout << reclength(head) << endl;
    // int i, data;
    // cin >> i >> data;
    // head = recinsert(head, i, data);
    // print(head);
}
