#include "binarytree.h"
class BST
{
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
    binarytree<int> *deletedata(int data, binarytree<int> *node)
    {
        if (node == NULL)
            return NULL;
        if (data > node->data)
        {
            node->right = deletedata(data, node->right);
            return node;
        }
        else if (data < node->data)
        {
            node->left = deletedata(data, node->left);
            return node;
        }
        else
        {
            if (node->left == NULL && node->right == NULL)
            {
                delete node;
                return NULL;
            }
            else if (node->left == NULL)
            {
                binarytree<int> *temp = node->right;
                node->right = NULL;
                delete node;
                return temp;
            }
            else if (node->right == NULL)
            {
                binarytree<int> *temp = node->left;
                node->left = NULL;
                delete node;
                return temp;
            }
            else
            {
                binarytree<int> *minnode = node->right;
                while (minnode->left != NULL)
                {
                    minnode = minnode->left;
                }
                int rightmin = minnode->data;
                node->data = rightmin;
                node->right = deletedata(rightmin, node->right);
                return node;
            }
        }
    }
    binarytree<int> *root;
    bool hasdata(int data, binarytree<int> *node)
    {
        if (node == NULL)
            return false;
        if (node->data == data)
            return true;
        else if (node->data > data)
        {
            return hasdata(data, node->left);
        }
        else
        {
            return hasdata(data, root->right);
        }
    }
    binarytree<int> *insertdata(int data, binarytree<int> *node)
    {

        if (node == NULL)
        {
            binarytree<int> *newnode = new binarytree<int>(data);
            return newnode;
        }
        if (node->data > data)
        {
            node->left = insertdata(data, node->left);
        }
        else if (node->data <= data)
        {
            node->right = insertdata(data, node->right);
        }
        return node;
    }

public:
    BST()
    {
        root = NULL;
    }
    ~BST()
    {
        delete root;
    }
    void insertdata(int data)
    {
        this->root = insertdata(data, root);
    }
    void deletedata(int data)
    {
        this->root = deletedata(data, root);
    }
    bool hasdata(int data)
    {
        return hasdata(data, root);
    }
    void printtree()
    {
        print(root);
    }
};