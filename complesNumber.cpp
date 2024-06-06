class complex
{
private:
    int real;
    int imaginary;

public:
    complex(int real, int imaginary)
    {
        this->real = real;
        this->imaginary = imaginary;
    }
    void print()
    {
        cout << real << "+i" << imaginary << endl;
    }
    void add(complex c2)
    {
        real = real + c2.real;
        imaginary = imaginary + c2.imaginary;
    }
    void multi(complex c2)
    {
        int r;
        r = (real * c2.real) - (imaginary * c2.imaginary);
        imaginary = (real * c2.imaginary) + (imaginary * c2.real);
        real = r;
    }
};