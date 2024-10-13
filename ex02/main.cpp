#include "Array.hpp"
#include <iostream>
#include <string>
#define MAX_VAL 10

class Point {
public:
  int x, y;
  bool operator==(const Point &other) const {
    return x == other.x && y == other.y;
  }
  bool operator<(const Point &other) const {
    if (x != other.x)
      return x < other.x;
    return y < other.y;
  }
  Point() : x(0), y(0) {}
  Point(int xVal, int yVal) : x(xVal), y(yVal) {}
  friend std::ostream &operator<<(std::ostream &os, const Point &p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
  }
};

void test_int() {
  Array<int> numbers(MAX_VAL);
  srand(time(NULL));

  std::cout << "Generating random numbers" << std::endl;
  for (int i = 0; i < MAX_VAL; i++) {
    numbers[i] = rand();
    std::cout << numbers[i] << " ";
  }
  std::cout << std::endl;

  std::cout << "Copy constructor and assignment operator check.\n";
  Array<int> tmp = numbers;
  Array<int> test(tmp);
  for (size_t i = 0; i < numbers.size(); i++) {
    if (numbers[i] != tmp[i] || numbers[i] != test[i]) {
      std::cout
          << "!!! Copy constructor and assignment operator DONT WORK PROPERLY"
          << std::endl;
    }
  }
  if (tmp.size() != numbers.size() || test.size() != numbers.size()) {
    std::cout
        << "!!! Copy constructor and assignment operator DONT WORK PROPERLY"
        << std::endl;
  }
  std::cout << "Copy constructor and assignment operator tested.\n";

  std::cout << "generating OutOfRange intentionally" << std::endl;
  try {
    numbers[-2] = 0;
  } catch (const std::exception &e) {
    std::cerr << "Caught exception (expected): " << e.what() << '\n';
  }
  try {
    numbers[MAX_VAL] = 0;
  } catch (const std::exception &e) {
    std::cerr << "Caught exception (expected): " << e.what() << '\n';
  }

  std::cout << "Change some of the numbers:" << std::endl;
  numbers[0] = 0;
  numbers[1] = 1;
  numbers[2] = 2;
  numbers[3] = 3;
  for (unsigned int i = 0; i < numbers.size(); i++) {
    std::cout << numbers[i] << " ";
  }
  std::cout << std::endl;

  std::cout << "Generate new values for the array:" << std::endl;
  for (int i = 0; i < MAX_VAL; i++) {
    numbers[i] = rand();
  }
  for (int i = 0; i < MAX_VAL; i++) {
    std::cout << numbers[i] << " ";
  }
  std::cout << std::endl;
}

void test_double() {
  Array<double> numbers(MAX_VAL);
  srand(time(NULL));

  std::cout << "Generating random numbers" << std::endl;
  for (int i = 0; i < MAX_VAL; i++) {
    numbers[i] = rand();
    std::cout << numbers[i] << " ";
  }
  std::cout << std::endl;

  std::cout << "Copy constructor and assignment operator check.\n";
  Array<double> tmp = numbers;
  Array<double> test(tmp);
  for (size_t i = 0; i < numbers.size(); i++) {
    if (numbers[i] != tmp[i] || numbers[i] != test[i]) {
      std::cout
          << "!!! Copy constructor and assignment operator DONT WORK PROPERLY"
          << std::endl;
    }
  }
  if (tmp.size() != numbers.size() || test.size() != numbers.size()) {
    std::cout
        << "!!! Copy constructor and assignment operator DONT WORK PROPERLY"
        << std::endl;
  }
  std::cout << "Copy constructor and assignment operator tested.\n";

  std::cout << "generating OutOfRange intentionally" << std::endl;
  try {
    numbers[-2] = 0;
  } catch (const std::exception &e) {
    std::cerr << "Caught exception (expected): " << e.what() << '\n';
  }
  try {
    numbers[MAX_VAL] = 0;
  } catch (const std::exception &e) {
    std::cerr << "Caught exception (expected): " << e.what() << '\n';
  }

  std::cout << "Change some of the numbers:" << std::endl;
  numbers[0] = 0.1234;
  numbers[1] = 1.2345;
  numbers[2] = 2.3456;
  numbers[3] = 3.4567;
  for (unsigned int i = 0; i < numbers.size(); i++) {
    std::cout << numbers[i] << " ";
  }
  std::cout << std::endl;

  std::cout << "Generate new values for the array:" << std::endl;
  for (int i = 0; i < MAX_VAL; i++) {
    numbers[i] = rand();
  }
  for (int i = 0; i < MAX_VAL; i++) {
    std::cout << numbers[i] << " ";
  }
  std::cout << std::endl;
}

void test_strings() {
  Array<std::string> stringArray(4);
  stringArray[0] = "apple";
  stringArray[1] = "banana";
  stringArray[2] = "cherry";
  stringArray[3] = "pear";

  std::cout << "Initial string array values: ";
  for (unsigned int i = 0; i < stringArray.size(); ++i) {
    std::cout << stringArray[i] << " ";
  }
  std::cout << std::endl;

  stringArray[0] = "zero";
  stringArray[1] = "one";

  std::cout << "Modified string array values: ";
  for (unsigned int i = 0; i < stringArray.size(); ++i) {
    std::cout << stringArray[i] << " ";
  }
  std::cout << std::endl;

  std::cout << "generating OutOfRange intentionally" << std::endl;
  try {
    stringArray[4] = "monkey";
  } catch (const std::exception &e) {
    std::cerr << "Caught exception (expected): " << e.what() << '\n';
  }
}

void test_points() {
  Array<Point> pointArray(3);
  pointArray[0] = Point(1, 2);
  pointArray[1] = Point(3, 4);
  pointArray[2] = Point(5, 6);

  std::cout << "Initial Point array values: ";
  for (unsigned int i = 0; i < pointArray.size(); ++i) {
    std::cout << pointArray[i] << " ";
  }
  std::cout << std::endl;

  pointArray[0] = Point(7, 8);
  pointArray[1] = Point(9, 10);

  std::cout << "Modified Point array values: ";
  for (unsigned int i = 0; i < pointArray.size(); ++i) {
    std::cout << pointArray[i] << " ";
  }
  std::cout << std::endl;

  std::cout << "generating OutOfRange intentionally" << std::endl;
  try {
    pointArray[3] = Point(11, 12);
  } catch (const std::exception &e) {
    std::cerr << "Caught exception (expected): " << e.what() << '\n';
  }
}

int main() {
  std::cout << "========= Testing Array with Integers =========\n";
  test_int();
  std::cout << std::endl << "========= Testing Array with Doubles =========\n";
  test_double();
  std::cout << std::endl << "========= Testing Array with Strings =========\n";
  test_strings();
  std::cout << std::endl
            << "========= Testing Array with Custom Class (Point) =========\n";
  test_points();

  return 0;
}