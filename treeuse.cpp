#include <iostream>
#include <queue>
#include "treenode.h"
using namespace std;
void deletetree(treenode<int> *root)
{
    for (int i = 0; i < root->children.size(); i++)
    {
        deletetree(root->children[i]);
    }
    delete root;
}
void postorder(treenode<int> *root)
{
    if (root == NULL)
        return;
    for (int i = 0; i < root->children.size(); i++)
    {
        postorder(root->children[i]);
    }
    cout << root->data << " ";
}
void preorder(treenode<int> *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    for (int i = 0; i < root->children.size(); i++)
    {
        preorder(root->children[i]);
    }
}
int leafnode(treenode<int> *root)
{
    if (root == NULL)
        return 0;
    if (root->children.size() == 0)
        return 1;
    int height = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        height += leafnode(root->children[i]);
    }
    return height;
}
void depth(treenode<int> *root, int k)
{
    if (root == NULL)
    {
        return;
    }
    if (k == 0)
    {
        cout << root->data << endl;
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        depth(root->children[i], k - 1);
    }
}
int heightofnode(treenode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int heigth = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        int childheight = heightofnode(root->children[i]);
        if (childheight > heigth)
        {
            heigth = childheight;
        }
    }
    return heigth + 1;
}
int maxnode(treenode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int largest = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        int child = maxnode(root->children[i]);
        if (child > largest)
        {
            largest = child;
        }
    }
    return largest;
}
int sumofallnodes(treenode<int> *root)
{
    int sum;
    sum = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        sum += sumofallnodes(root->children[i]);
    }
    return sum;
}
int count(treenode<int> *root)
{
    int ans = 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += count(root->children[i]);
    }
    return ans;
}
treenode<int> *takeinputlevelwise()
{
    int rootdata;
    cout << "enter root data" << endl;
    cin >> rootdata;
    treenode<int> *root = new treenode<int>(rootdata);
    queue<treenode<int> *> pendingnodes;
    pendingnodes.push(root);
    while (pendingnodes.size() != 0)
    {
        treenode<int> *front = pendingnodes.front();
        pendingnodes.pop();
        cout << "number of the children of " << front->data << endl;
        int numchild;
        cin >> numchild;
        for (int i = 0; i < numchild; i++)
        {
            int childdata;
            cout << "enter " << i << "th child of " << front->data << endl;
            cin >> childdata;
            treenode<int> *child = new treenode<int>(childdata);
            front->children.push_back(child);
            pendingnodes.push(child);
        }
    }
    return root;
}
treenode<int> *takeinput()
{
    int rootdata;
    cout << "enter the data" << endl;
    cin >> rootdata;
    treenode<int> *root = new treenode<int>(rootdata);
    int n;
    cout << "enter the number of children of " << rootdata << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        treenode<int> *children = takeinput();
        root->children.push_back(children);
    }

    return root;
}
void printtree(treenode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << ":";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << ",";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        printtree(root->children[i]);
    }
}
int main()
{
    // treenode<int> *root = new treenode<int>(1);
    // treenode<int> *node1 = new treenode<int>(2);
    // treenode<int> *node2 = new treenode<int>(3);
    // root->children.push_back(node1);
    // root->children.push_back(node2);
    // treenode<int> *root = takeinput();
    // printtree(root);
    treenode<int> *root = takeinputlevelwise();
    // printtree(root);
    // cout << count(root) << endl;
    // cout << sumofallnodes(root) << endl;
    // cout << maxnode(root) << endl;
    // cout << heightofnode(root) << endl;
    // int deep;
    // cin >> deep;
    // depth(root, deep);
    // cout << leafnode(root) << endl;
    // preorder(root);
    // postorder(root);
    // deletetree(root);
    // delete root;
}
// 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0