template <typename T>
class node
{
public:
    T data;
    node<T> *next;
    node(T data)
    {
        this->data = data;
        next = NULL;
    }
};

template <typename T>
class queue
{
    node<T> *head;
    node<T> *tail;
    int size;

public:
    queue()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    int getsize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }
    void enqueue(T element)
    {
        node<T> *newnode = new node<T>(element);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        size++;
    }

    T front()
    {
        if (head == NULL)
        {
            return 0;
        }
        return head->data;
    }

    T dequeue()
    {
        if (head == NULL)
        {
            return 0;
        }
        T ans = head->data;
        node<T> *temp = head;
        head=head->next;
        delete temp;
        size--;
        return ans;
    }
};