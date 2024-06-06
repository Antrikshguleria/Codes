#include <iostream>
#include "binarytree.h"
#include <queue>
using namespace std;
pair<int, int> heightdiameter(binarytree<int> *root)
{
    if (root == NULL)
    {
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }
    pair<int, int> leftans = heightdiameter(root->left);
    pair<int, int> rightans = heightdiameter(root->right);
    int ld = leftans.first;
    int lh = leftans.second;
    int rd = rightans.first;
    int rh = rightans.second;
    int height = 1 + max(lh, rh);
    int diameter = max(lh + rh, max(ld, rd));
    pair<int, int> p;
    p.first = diameter;
    p.second = height;
    return p;
}
int height(binarytree<int> *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}
int diameter(binarytree<int> *root)
{
    if (root == NULL)
        return 0;
    int option1 = height(root->left) + height(root->right);
    int option2 = diameter(root->left);
    int option3 = diameter(root->right);
    return max(option1, max(option2, option3));
}
binarytree<int> *buildtreehelper(int *in, int *pre, int ins, int ine, int pres, int pree)
{
    if (ins > ine)
    {
        return NULL;
    }

    int rootdata = pre[pres];
    int rootindex = -1;
    for (int i = ins; i < ine; i++)
    {
        if (in[i] == rootdata)
        {
            rootindex = i;
            break;
        }
    }
    int lins = ins;
    int line = rootindex - 1;
    int lpres = pres + 1;
    int lpree = line - lins + lpres;
    int rins = rootindex + 1;
    int rine = ine;
    int rpres = lpree + 1;
    int rpree = pree;
    binarytree<int> *root = new binarytree<int>(rootdata);
    root->left = buildtreehelper(in, pre, lins, line, lpres, lpree);
    root->right = buildtreehelper(in, pre, rins, rine, rpres, rpree);
    return root;
}
binarytree<int> *buildtree(int *in, int *pre, int size)
{
    return buildtreehelper(in, pre, 0, size - 1, 0, size - 1);
}
void preorder(binarytree<int> *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(binarytree<int> *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
void inorder(binarytree<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void mirror(binarytree<int> *root)
{
    if (root == NULL)
        return;
    binarytree<int> *temp = root->right;
    root->right = root->left;
    root->left = temp;
    mirror(root->right);
    mirror(root->left);
}
// int height(binarytree<int> *root)
// {
//     if (root == NULL)
//         return 0;
//     int l = height(root->left);
//     int r = height(root->right);
//     if (l > r)
//     {
//         return 1 + l;
//     }
//     return 1 + r;
// }
bool present(binarytree<int> *root, int x)
{
    if (root == NULL)
        return false;
    if (root->data == x)
    {
        return true;
    }
    bool l = present(root->left, x);
    bool r = present(root->right, x);
    if (l == true || r == true)
    {
        return true;
    }
    return false;
}
int countnode(binarytree<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + countnode(root->left) + countnode(root->right);
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
binarytree<int> *takeinput()
{
    int rootdata;
    cout << "enetr  data" << endl;
    cin >> rootdata;
    if (rootdata == -1)
    {
        return NULL;
    }
    binarytree<int> *root = new binarytree<int>(rootdata);
    binarytree<int> *leftchild = takeinput();
    binarytree<int> *rightchild = takeinput();
    root->left = leftchild;
    root->right = rightchild;
    return root;
}
void print(binarytree<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << ":";
    if (root->left != NULL)
    {
        cout << "L" << root->left->data << ":";
    }
    if (root->right != NULL)
    {
        cout << "R" << root->right->data;
    }
    cout << endl;
    print(root->left);
    print(root->right);
}
int main()
{
    // binarytree<int> *root = new binarytree<int>(1);
    // binarytree<int> *node1 = new binarytree<int>(2);
    // binarytree<int> *node2 = new binarytree<int>(3);
    // root->left = node1;
    // root->right = node2;
    binarytree<int> *root = takeinputlevelwise();
    // print(root);
    // cout << countnode(root) << endl;
    // int x;
    // cin >> x;
    // cout << present(root, x);
    // cout << height(root) << endl;
    // mirror(root);
    // print(root);
    // inorder(root);
    // preorder(root);
    // int in[] = {4, 2, 5, 1, 8, 6, 9, 3, 7};
    // int pre[] = {1, 2, 4, 5, 3, 6, 8, 9, 7};
    // binarytree<int> *root = buildtree(in, pre, 9);
    // print(root);
    // cout << diameter(root) << endl;
    pair<int, int> p = heightdiameter(root);
    cout << "diametr is :" << p.first << endl;
    cout << "height is:" << p.second << endl;
    delete root;
}