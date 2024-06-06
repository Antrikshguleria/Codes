#include <iostream>
using namespace std;
#include "trie.h"
int main()
{
    trie t;
    t.insert("and");
    t.insert("are");
    t.insert("dor");
    cout << t.search("are") << endl;
    t.remove("and");
    cout << t.search("and") << endl;
}