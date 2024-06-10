#include <iostream>

#include "complex.hpp"

int main(){

  Complex a(3,-5);
  Complex b(2,4);

  Complex c = a - b;

  c.print();

  return 0;
}
