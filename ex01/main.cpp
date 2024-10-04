#include "iter.hpp"
#include <iostream>
#include <string>
#include <vector>

template <typename T> void print_element(T const &element) {
  std::cout << element << " ";
}

template <typename T> void increment(T &element) { ++element; }

template <typename T> void square(T &element) { element *= element; }

template <typename T> void my_clear(T &element) { element.clear(); }

void function(int i) { std::cout << "[" << i << "]" << " "; }

void test_ints() {
  int is[] = {1, 2, 3, 4, 5};
  std::cout << "------------- INTEGER -------------" << std::endl;
  std::cout << "original ints array" << std::endl;
  iter(is, 5, function);
  std::cout << std::endl;

  std::cout << "array after the increment" << std::endl;
  iter(is, 5, increment<int>);
  iter(is, 5, print_element<int>);
  std::cout << std::endl;

  std::cout << std::endl;
  std::cout << "array after the increment and square" << std::endl;
  iter(is, 5, square<int>);
  iter(is, 5, print_element<int>);
  std::cout << std::endl;
  std::cout << std::endl;
}
void test_doubles() {
  double is[] = {1, 2, 3, 4, 5};
  std::cout << "------------- INTEGER -------------" << std::endl;
  std::cout << "original doubles array" << std::endl;
  iter(is, 5, function);
  std::cout << std::endl;

  std::cout << "array after the increment" << std::endl;
  iter(is, 5, increment<double>);
  iter(is, 5, print_element<double>);
  std::cout << std::endl;

  std::cout << std::endl;
  std::cout << "array after the increment and square" << std::endl;
  iter(is, 5, square<double>);
  iter(is, 5, print_element<double>);
  std::cout << std::endl;
  std::cout << std::endl;
}

void test_clear() {
  std::vector<std::string> v;
  std::cout << "------------- STRINGS -------------" << std::endl;
  v.push_back("first");
  v.push_back("second element");
  v.push_back("3rd elem");
  v.push_back("final elem");

  std::cout << "Array of strings: ";
  for (size_t i = 0; i < v.size(); i++) {
    std::cout << "[" << v[i] << "], ";
  }
  std::cout << std::endl;

  iter(v.data(), v.size(), my_clear<std::string>);

  std::cout << "Array after iter: ";
  for (size_t i = 0; i < v.size(); i++) {
    std::cout << "[" << v[i] << "], ";
  }
  std::cout << std::endl;
}

int main() {
  test_ints();
  test_doubles();
  test_clear();
}
