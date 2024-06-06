#include <iostream>
// #include "binarytree.h"
#include <queue>
using namespace std;
#include "binarysearchtree.h"
vector<int> *rootnode(binarytree<int> *root, int data)
{
    if (root == NULL)
        return NULL;
    if (root->data == data)
    {
        vector<int> *output = new vector<int>();
        output->push_back(root->data);
        return output;
    }
    vector<int> *leftoutput = rootnode(root->left, data);
    if (leftoutput != NULL)
    {
        leftoutput->push_back(root->data);
        return leftoutput;
    }
    vector<int> *rightoutput = rootnode(root->right, data);
    if (rightoutput != NULL)
    {
        rightoutput->push_back(root->data);
        return rightoutput;
    }
    else
        return NULL;
}
class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
node *bsttoll(binarytree<int> *root)
{
    if (root == NULL)
        return NULL;
    node *leftans = bsttoll(root->left);
    node *rightans = bsttoll(root->right);
    node *node1 = new node(root->data);
    node1->next = rightans;
    if (leftans == NULL)
        return NULL;
    node *temp = leftans;
    while (temp->next == NULL)
    {
        temp = temp->next;
    }
    temp->next = node1;
    return leftans;
}
void printtree(binarytree<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    printtree(root->left);
    printtree(root->right);
}
binarytree<int> *arraytobst(int a[], int start, int end)
{
    if (start > end)
        return NULL;
    int mid = (start + end) / 2;
    binarytree<int> *root = new binarytree<int>(a[mid]);
    root->left = (arraytobst(a, start, mid - 1));
    root->right = (arraytobst(a, mid + 1, end));
    return root;
}
class bst
{
public:
    bool bst;
    int minimum;
    int maximum;
};
bst bst2(binarytree<int> *root)
{
    if (root == NULL)
    {
        bst output;
        output.bst = true;
        output.minimum = INT_MAX;
        output.maximum = INT_MIN;
        return output;
    }
    bst leftoutput = bst2(root->left);
    bst rightoutput = bst2(root->right);
    int minimum = min(root->data, min(leftoutput.minimum, rightoutput.minimum));
    int maximum = max(root->data, max(leftoutput.maximum, rightoutput.maximum));
    bool isbst = (root->data > leftoutput.maximum) && (root->data <= rightoutput.minimum) && leftoutput.bst && rightoutput.bst;
    bst output;
    output.minimum = minimum;
    output.maximum = maximum;
    output.bst = isbst;
    return output;
}
int maximun(binarytree<int> *root)
{
    if (root == NULL)
    {
        return INT_MIN;
    }
    return max(root->data, max(maximun(root->left), maximun(root->right)));
}
int minimum(binarytree<int> *root)
{
    if (root == NULL)
    {
        return INT_MAX;
    }
    return min(root->data, min(minimum(root->left), minimum(root->right)));
}
bool checkbst(binarytree<int> *root)
{
    if (root == NULL)
    {
        return true;
    }
    int leftmax = maximun(root->left);
    int rightmin = minimum(root->right);
    bool output = (root->data > leftmax) && (root->data <= rightmin) && checkbst(root->left) && checkbst(root->right);
    return output;
}
void elementsbetween(binarytree<int> *root, int k1, int k2)
{
    if (root == NULL)
    {
        return;
    }
    if (root->data >= k1 && root->data <= k2)
    {
        elementsbetween(root->left, k1, k2);
        cout << root->data << endl;
        elementsbetween(root->right, k1, k2);
        return;
    }
    else if (root->data <= k1)
    {
        elementsbetween(root->right, k1, k2);
        return;
    }
    else if (root->data >= k2)
    {
        elementsbetween(root->left, k1, k2);

        return;
    }
}
bool search(binarytree<int> *root, int a)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == a)
    {
        return true;
    }
    else if (root->data > a)
    {
        return search(root->left, a);
    }
    else if (root->data < a)
    {
        return search(root->right, a);
    }
    return false;
}
binarytree<int> *takeinputlevelwise()
{
    int rootdata;
    cout << "enetr  root data" << endl;
    cin >> rootdata;
    if (rootdata == -1)
    {
        return NULL;
    }
    binarytree<int> *root = new binarytree<int>(rootdata);
    queue<binarytree<int> *> pendingnodes;
    pendingnodes.push(root);
    while (pendingnodes.size() != 0)
    {
        binarytree<int> *front = pendingnodes.front();
        pendingnodes.pop();
        cout << "enter the left child of " << front->data << endl;
        int leftchilddata;
        cin >> leftchilddata;
        if (leftchilddata != -1)
        {
            binarytree<int> *leftchild = new binarytree<int>(leftchilddata);
            front->left = leftchild;
            pendingnodes.push(leftchild);
        }
        cout << "enter the right child of " << front->data << endl;
        int rightchilddata;
        cin >> rightchilddata;
        if (rightchilddata != -1)
        {
            binarytree<int> *rightchild = new binarytree<int>(rightchilddata);
            front->right = rightchild;
            pendingnodes.push(rightchild);
        }
    }
    return root;
}
int main()
{
    // binarytree<int> *root = takeinputlevelwise();
    // int a;
    // cout << "enter the element to be searched" << endl;
    // cin >> a;
    // cout << search(root, a) << endl;
    // int k1, k2;
    // cout << "enter the elements searched between" << endl;
    // cin >> k1 >> k2;
    // elementsbetween(root, k1, k2);
    // cout << checkbst(root) << endl;
    // cout << "is bst = " << bst2(root).bst << endl;
    // cout << "Minimum is = " << bst2(root).minimum << endl;
    // cout << "Maximum is = " << bst2(root).maximum << endl;
    // int n;
    // cin >> n;
    // int a[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> a[i];
    // }
    // binarytree<int> *root;
    // root = arraytobst(a, 0, n);

    // printtree(root);
    // delete root;
    // node *head = bsttoll(root);
    // while (head != NULL)
    // {
    //     cout << head->data << endl;
    //     head = head->next;
    // }
    // int data;
    // cin >> data;
    // vector<int> *output = rootnode(root, data);
    // for (int i = 0; i < output->size(); i++)
    // {
    //     cout << output->at(i) << endl;
    // }
    BST b;
    b.insertdata(10);
    b.insertdata(5);
    b.insertdata(20);
    b.insertdata(7);
    b.insertdata(3);
    b.insertdata(15);
    b.printtree();
    b.deletedata(10);
    b.deletedata(100);
    b.printtree();
}
// 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
