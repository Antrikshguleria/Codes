class poly
{
    int *degcoeff;
    int capacity;

public:
    poly()
    {
        this->degcoeff = new int[6];
        this->capacity = 6;
    }

    poly(int capacity)
    {
        this->degcoeff = new int[capacity];
        this->capacity = capacity;
    }

    poly(poly &p)
    {
        this->degcoeff = new int[p.capacity];
        for (int i = 0; i < capacity; i++)
        {
            this->degcoeff[i] = p.degcoeff[i];
        }
        this->capacity = p.capacity;
    }

    void setcoeff(int degree, int coeff)
    {
        if (degree < capacity)
        {
            degcoeff[degree] = coeff;
        }
        else
        {
            int *newdegcoeff = new int[degree + 1];
            for (int i = 0; i < capacity; i++)
            {
                newdegcoeff[i] = degcoeff[i];
            }
            degcoeff = newdegcoeff;
            degcoeff[degree] = coeff;
            capacity = degree + 1;
        }
    }

    poly operator+(poly const &p2)
    {
        int newcap = max(capacity, p2.capacity);
        poly p3(newcap);
        for (int i = 0; i < newcap; i++)
        {
            if (i <= capacity && i <= p2.capacity)
            {
                p3.degcoeff[i] = degcoeff[i] + p2.degcoeff[i];
                if (i <= capacity)
                {
                    p3.degcoeff[i] = degcoeff[i];
                }
                else
                    p3.degcoeff[i] = p2.degcoeff[i];
            }
        }
        return p3;
    }

    poly operator-(poly const &p2)
    {
        int newcap = max(capacity, p2.capacity);
        poly p3(newcap);
        for (int i = 0; i < newcap; i++)
        {
            if (i <= capacity && i <= p2.capacity)
            {
                p3.degcoeff[i] = degcoeff[i] - p2.degcoeff[i];
                if (i <= capacity)
                {
                    p3.degcoeff[i] = degcoeff[i];
                }
                else
                    p3.degcoeff[i] = -p2.degcoeff[i];
            }
        }
        return p3;
    }

    poly operator*(poly const &p2)
    {
       
    }


    void print()
    {
        for (int i = 0; i <= capacity; i++)
        {
            if (degcoeff[i] != 0)
            {
                cout << degcoeff[i] << "X" << i << " ";
            }
            cout << endl;
        }
    }
};
