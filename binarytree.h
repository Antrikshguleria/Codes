template <typename T>
class binarytree
{
public:
    T data;
    binarytree *left;
    binarytree *right;

    binarytree(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~binarytree()
    {
        delete left;
        delete right;
    }
};
