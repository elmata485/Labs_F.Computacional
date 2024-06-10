#ifndef COMPLEX_HPP
#define COMPLEX_HPP

class Complex

{
  public:

    double real, imag;
  
    double norm();
    void conjugado();
    void print();

    Complex(double a, double b);
    Complex(const Complex &obj);

    Complex operator/(const Complex &obj);
    Complex operator+(const Complex &obj);
    Complex operator-(const Complex &obj);
    Complex operator*(const Complex &obj);
    Complex &operator=(const Complex &obj);

    ~Complex();

    Complex();


};





#endif
