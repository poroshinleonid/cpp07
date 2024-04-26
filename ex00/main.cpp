#include "TSwap.h"
#include "TMin.h"
#include "TMax.h"
#include <iostream>
#include <string>

void test_subj();
void test_swap();

  
int main() {
  test_subj();
  test_swap();
}

void test_subj() {
  int a = 2;
  int b = 3;
  ::swap(a, b);
  std::cout << "a = " << a << ", b = " << b << std::endl;
  std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
  std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
  std::string c = "chaine1";
  std::string d = "chaine2";
  ::swap(c, d);
  std::cout << "c = " << c << ", d = " << d << std::endl;
  std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
  std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
  std::cout << "--------------------------------" << std::endl << std::endl;
}

void test_swap() {
  std::cout << "Swapping ints:" << std::endl;
  int a = 10;
  int b = 28;
  std::cout << "a = " << a << "; b = " << b << std::endl;
  ::swap(a, b);
  std::cout << "a = " << a << "; b = " << b << std::endl;
  std::cout << "--------------------------------" << std::endl << std::endl;

  std::cout << "Swapping strings:" << std::endl;
  std::string as = "I am the first happy string";
  std::string bs = "I am the second angry string!";
  std::cout << "a = " << as << "; b = " << bs << std::endl;
  ::swap(as, bs);
  std::cout << "a = " << as << "; b = " << bs << std::endl;
  std::cout << "--------------------------------" << std::endl << std::endl;
}