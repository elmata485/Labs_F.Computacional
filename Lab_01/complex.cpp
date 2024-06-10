#include <iostream>
#include <cmath>

#include "complex.hpp"

Complex::Complex(){
  std::cout << "Default Constructor" <<std::endl;
  real = 0.0;
  imag = 0.0;
}

Complex::Complex(double a, double b){
  std::cout << "Custom Constructor" <<std::endl;
  real = a;
  imag = b;
}


void Complex::print(){
  std::cout << real << "," << imag <<std::endl;
}


double Complex::norm(){
  std::cout << "Norma" <<std::endl;
  return std::sqrt( (real*real) + (imag*imag) );
}


void Complex::conjugado(){
  std::cout << "Conjugado" <<std::endl;
  imag = -imag;
}


Complex::~Complex(){
  std::cout << "Destructor" << std::endl;
}

Complex::Complex(const Complex &obj){
  std::cout << "Copy Constructor" << std::endl;
  real = obj.real;
  imag = obj.imag;
}

Complex &Complex::operator=(const Complex &obj){
  std::cout << "Assign" << std::endl;
  real = obj.real;
  imag = obj.imag;
  return *this;
}

Complex Complex::operator+(const Complex &obj){
  std::cout << "Sum" << std::endl;

  Complex c;

  c.real =  real + obj.real;
  c.imag =  imag + obj.imag;

  return c;
}

Complex Complex::operator-(const Complex &obj){
  std::cout << "Minus" << std::endl;

  Complex c;
  c.real =  real - obj.real;
  c.imag =  imag - obj.imag;

  return c;
}

Complex Complex::operator*(const Complex &obj){
  std::cout << "Multi" << std::endl;

  Complex c;
  c.real =  (real * obj.real) - (imag * obj.imag);
  c.imag =  (real * obj.imag) + (imag * obj.real);

  return c;
}

Complex Complex::operator/(const Complex &obj){
  std::cout << "Division" << std::endl;
  Complex c;

  c.real =  ( (real * obj.real) + (imag * obj.imag) )/(obj.real*obj.real + obj.imag * obj.imag);
  c.imag =  ( -1 * (real * obj.imag) + (imag * obj.real) )/(obj.real*obj.real + obj.imag * obj.imag);

  return c;

}
