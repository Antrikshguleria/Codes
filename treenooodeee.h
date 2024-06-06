#include <vector>
using namespace std;
template <typename T>
class node
{
public:
    T data;
    vector<node<int> *> children;
    node(T data)
    {
        this->data = data;
    }
    ~node()
    {
        for (int i = 0; i < children.size(); i++)
        {
            delete children[i];
        }
    }
};
