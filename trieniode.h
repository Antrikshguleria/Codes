class trienode
{
public:
    char data;
    trienode **children;
    bool isterminal;
    trienode(char data)
    {
        this->data = data;
        children = new trienode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isterminal = false;
    }
};