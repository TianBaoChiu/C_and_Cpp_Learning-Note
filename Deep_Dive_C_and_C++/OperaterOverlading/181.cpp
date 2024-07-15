#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Complex
{
private:
    int real, img;

public:
    Complex(int r, int i)
    {
        real = r;
        img = i;
    }

    void Display()
    {
        cout << real << "+i" << img << endl;
    }

    //--- insertion operator overloading
    friend ostream &operator<<(ostream &o, Complex &c1);
};

ostream &operator<<(ostream &o, Complex &c1)
{
    o << c1.real << "+i" << c1.img;

    return o;
}

int main(void)
{
    Complex c1(5, 6);

    c1.Display();

    cout << c1;

    return 0;
}