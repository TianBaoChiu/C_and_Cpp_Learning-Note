#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Complex
{
private:
    int real;
    int img;

public:
    Complex(int r = 0, int i = 0)
    {
        real = r;
        img = i;
    }
    Complex add(Complex x)
    {
        Complex tmp;
        tmp.real = real + x.real;
        tmp.img = img + x.img;

        return tmp;
    }

    //--- operator overloading
    Complex operator+(Complex x)
    {
        Complex tmp;
        tmp.real = real + x.real;
        tmp.img = img + x.img;

        return tmp;
    }

    //--- friend function operator overloading
    friend Complex operator-(Complex c1, Complex c2);

    int getReal()
    {
        return real;
    }
    int getImg()
    {
        return img;
    }
};

Complex operator-(Complex c1, Complex c2)
{
    Complex tmp;
    tmp.real = c1.real - c2.real;
    tmp.img = c1.img - c2.img;

    return tmp;
}

int main(void)
{
    Complex c1(5, 7);
    Complex c2(6, 6);
    Complex c3;
    Complex c4;
    Complex c5;

    c3 = c1.add(c2);
    printf("real of c3 = %d\n", c3.getReal());
    printf("img of c3 = %d\n", c3.getImg());

    //--- using operator overloading
    c4 = c1 + c2;
    printf("real of c4 = %d\n", c4.getReal());
    printf("img of c4 = %d\n", c4.getImg());

    //--- using friend function operator overloading
    c5 = c4 - c2;
    printf("real of c5 = %d\n", c5.getReal());
    printf("img of c5 = %d\n", c5.getImg());

    return 0;
}