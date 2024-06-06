#include <iostream>
using namespace std;
#include "ll.cpp"
class pa
{
public:
    node *head;
    node *tail;
};
node *reversell_3(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *smalloutput = reversell_3(head->next);
    node *tail = head->next;
    tail->next = head;
    head->next = NULL;
    return smalloutput;
}
pa reversell_2(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        pa ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }
    pa smalloutput = reversell_2(head->next);
    smalloutput.tail->next = head;
    head->next = NULL;
    pa ans;
    ans.head = smalloutput.head;
    ans.tail = head;
    return ans;
}
node *reversebetter(node *head)
{
    return reversell_2(head).head;
}
node *reversell(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *smalloutput = reversell(head->next);
    node *temp = smalloutput;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head;
    head->next = NULL;
    return smalloutput;
}
node *mergesort(node *head, node *head1)
{
    node *n12;
    node *t;
    n12 = t;
    while (head->next != NULL && head1->next != NULL)
    {
        if (head->data >= head1->data)
        {
            node *newnode = new node(head1->data);
            t->next = head1;
            t = t->next;
        }
        else if (head->data < head1->data)
        {
            node *newnode = new node(head1->data);
            t->next = head;
            t = t->next;
        }
    }
    return n12;
}
int midpoint(node *head, int len)
{
    node *t1 = head;
    node *t2 = head;
    if (len == 1)
    {
        return head->data;
    }
    else if (len % 2 != 0)
    {
        while (t2->next != NULL)
        {
            t1 = t1->next;
            t2 = t2->next->next;
        }
        return t1->data;
    }
    while (t2->next->next != NULL)
    {
        t1 = t1->next;
        t2 = t2->next->next;
    }
    return t1->data;
}
node *eliminate(node *head)
{
    node *t1 = head;
    node *t2 = head;
    if (head->next == NULL)
        return head;
    for (int i = 0; t1 != NULL; i++)
    {
        for (int i = 0; t2 != NULL; i++)
        {
            if (t1->data == t2->data)
            {
                t1->next = t2->next;
                return t1;
            }
            t2 = t2->next;
        }
        t1 = t1->next;
    }
    return head;
}
node *appen(node *head, int append, int len)
{
    node *n1 = head;
    node *h;
    for (int i = 1; i < (len - append); i++)
    {
        n1 = n1->next;
    }
    node *a = n1->next;
    n1->next = NULL;
    h = a;
    for (int i = 1; i < append; i++)
    {
        a = a->next;
    }
    a->next = head;
    return h;
}
int find(node *head, int data)
{
    int i = 0;
    while (head != NULL)
    {
        if (head->data == data)
        {
            return i;
        }
        head = head->next;
        i++;
    }
    return -1;
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

int main()
{
    node *head = takeinput();
    // node *head1 = takeinput();
    // int data;
    // cin >> data;
    // print(head);
    // cout << find(head, data) << endl;
    // int len = length(head);
    // // cout << len << endl;
    // int append;
    // cin >> append;
    // head = appen(head, append, len);
    // print(head);
    //     head = eliminate(head);
    //     print(head);
    // cout << midpoint(head, len) << endl;
    // node *head2 = mergesort(head, head1);
    // print(head2);
    // print(reversell(head));
    // print(reversebetter(head));
    print(reversell_3(head));
}