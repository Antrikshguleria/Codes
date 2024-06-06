#include "trieniode.h"
#include <string>
using namespace std;
class trie
{
    trienode *root;

public:
    trie()
    {
        root = new trienode('\0');
    }

    void insert(trienode *root, string word)
    {
        // base case
        if (word.size() == 0)
        {
            root->isterminal = true;
            return;
        }

        // small calculation
        int index = word[0] - 'a';
        trienode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new trienode(word[0]);
            root->children[index] = child;
        }

        // recursive call
        insert(child, word.substr(1));
    }

    void insert(string word)
    {
        insert(root, word);
    }

    bool search(trienode *root, string word)
    {
        if (word.size() == 0)
        {
            return root->isterminal;
        }
        if (root->children[word[0] - 'a'] == NULL)
        {
            return false;
        }
        return search(root->children[word[0] - 'a'], word.substr(1));
    }

    bool search(string word)
    {
        return search(root, word);
    }

    void remove(trienode *root, string word)
    {
        if (word.size() == 0)
        {
            root->isterminal = false;
            return;
        }
        trienode *child;
        int index = word[0] - 'a';
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
            return;
        remove(child, word.substr(1));

        if (child->isterminal == false)
        {
            for (int i = 0; i < 26; i++)
            {
                if (child->children[i] != NULL)
                {
                    return;
                }
            }
            root->children[index] = NULL;
            delete child;
        }
    }

    void remove(string word)
    {
        remove(root, word);
    }
};