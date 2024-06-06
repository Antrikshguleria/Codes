template <typename T,typename V>
class makepair
{
    T x;
    V y;

public:
    void setX(T x)
    {
        this->x = x;
    }
    T getX()
    {
        return x;
    }
    void setY(T y)
    {
        this->y = y;
    }
    V getY()
    {
        return y;
    }
};