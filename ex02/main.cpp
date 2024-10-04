// #include "Array.hpp"
// #include <iostream>

// #define MAX_VAL 750
// int main(int, char **) {
//   Array<int> numbers(MAX_VAL);
//   int *mirror = new int[MAX_VAL];
//   srand(time(NULL));
//   for (int i = 0; i < MAX_VAL; i++) {
//     const int value = rand();
//     numbers[i] = value;
//     mirror[i] = value;
//   }

//   {
//     Array<int> tmp = numbers;
//     Array<int> test(tmp);
//   }

//   for (int i = 0; i < MAX_VAL; i++) {
//     if (mirror[i] != numbers[i]) {
//       std::cerr << "didn't save the same value!!" << std::endl;
//       return 1;
//     }
//   }
//   try {
//     numbers[-2] = 0;
//   } catch (const std::exception &e) {
//     std::cerr << e.what() << '\n';
//   }
//   try {
//     numbers[MAX_VAL] = 0;
//   } catch (const std::exception &e) {
//     std::cerr << e.what() << '\n';
//   }

//   for (int i = 0; i < MAX_VAL; i++) {
//     numbers[i] = rand();
//   }
//   delete[] mirror; //
//   return 0;
// }

#include "Array.hpp"
#include <iostream>
#include <string>
#define MAX_VAL 10

// Example custom class for testing
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

// Test with double array
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

// Test w/ std::string array
void testStrings() {
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

// custom class
void testPoints() {
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
  testStrings();
  std::cout << std::endl
            << "========= Testing Array with Custom Class (Point) =========\n";
  testPoints();

  return 0;
}