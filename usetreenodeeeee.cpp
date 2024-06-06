#include <iostream>
#include <queue>
using namespace std;
#include "treenooodeee.h"
bool contain(node<int> *root, int x)
{
    if (root == NULL){
        return false;
    }
    if (root->data == x)
    {
        return true;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        if (root->children[i]->data == x)
            return true;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        contain(root->children[i], x);
    }
    return false;
}
node<int> *takeinputlevelwise()
{
    int rootdata;
    cout << "enter the root data" << endl;
    cin >> rootdata;
    node<int> *root = new node<int>(rootdata);
    queue<node<int> *> pendingnode;
    pendingnode.push(root);
    while (pendingnode.size() != 0)
    {
        node<int> *front = pendingnode.front();
        pendingnode.pop();
        cout << "enter the number of child of " << front->data << endl;
        int numchild;
        cin >> numchild;
        for (int i = 0; i < numchild; i++)
        {
            cout << "enter the " << i << "th child of " << front->data << endl;
            int childdata;
            cin >> childdata;
            node<int> *child = new node<int>(childdata);
            front->children.push_back(child);
            pendingnode.push(child);
        }
    }
    return root;
}
node<int> *takeinput()
{
    cout << "enter the root data" << endl;
    int rootdata;
    cin >> rootdata;
    node<int> *root = new node<int>(rootdata);
    cout << "enter the number of children" << endl;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        node<int> *children = takeinput();
        root->children.push_back(children);
    }
    return root;
}
void printnode(node<int> *root)
{
    if (root == NULL)
        return;
    cout << root->data << ":";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << ",";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        printnode(root->children[i]);
    }
}
int main()
{
    node<int> *root = takeinputlevelwise();
    // printnode(root);
    int x;
    cin >> x;
    cout<<contain(root, x);
}