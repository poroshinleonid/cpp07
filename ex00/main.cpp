#include "TMax.hpp"
#include "TMin.hpp"
#include "TSwap.hpp"
#include <iostream>
#include <map>
#include <string>
#include <vector>

void test_subj();
void test_swap();
void test_complex();

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
};

int main() {
  std::cout << "SUBJECT "
               "---------------------------------------------------------------"
               "-----------"
            << std::endl;
  test_subj();
  std::cout << "SWAP "
               "---------------------------------------------------------------"
               "-----------"
            << std::endl;
  test_swap();
  std::cout << "COMPLEX CLASS "
               "---------------------------------------------------------------"
               "-----------"
            << std::endl;
  test_complex();
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
  std::string as = "I am the first string";
  std::string bs = "I am the SECOND string!";
  std::cout << "a = " << as << "; b = " << bs << std::endl;
  ::swap(as, bs);
  std::cout << "a = " << as << "; b = " << bs << std::endl;
  std::cout << "--------------------------------" << std::endl << std::endl;
}

void printmap(const std::map<std::string, std::vector<std::string>> &m) {
  for (auto it = m.begin(); it != m.end(); it++) {
    std::cout << "\tVector name: " << it->first << std::endl;
    std::vector<std::string> vv = it->second;
    for (size_t i = 0; i < vv.size(); i++) {
      std::cout << "\t\titem #" << i << ": " << vv[i] << std::endl;
    }
  }
}

void test_complex() {
  std::map<std::string, std::vector<std::string>> m;
  std::vector<std::string> v;
  v.push_back("first vec first item");
  v.push_back("first vec sec item");
  v.push_back("first vec thitd item");
  v.push_back("first vec 4 item");
  m["first test item"] = v;
  v.clear();
  v.push_back("SECOND vec first item");
  v.push_back("SECOND vec sec item");
  v.push_back("SECOND vec thitd item");
  v.push_back("SECOND vec 4 item");
  m["second one"] = v;
  v.clear();

  std::map<std::string, std::vector<std::string>> m2;
  std::vector<std::string> v2;
  v2.push_back("Some other map 11");
  v2.push_back("Some other map 12");
  m2["other map one"] = v2;
  v2.clear();
  v2.push_back("Some other map 21");
  v2.push_back("Some other map 22");
  m2["other map two"] = v2;
  v2.clear();

  std::cout << "Map number one:\n";
  printmap(m);
  std::cout << "map number two:\n";
  printmap(m2);

  ::swap(m, m2);
  std::cout << "SWAPPING MAPS\n";

  std::cout << "Map number one:\n";
  printmap(m);
  std::cout << "map number two:\n";
  printmap(m2);

  ::swap(m, m2);
  std::cout << "SWAPPING MAPS AGAIN\n";

  std::cout << "Map number one:\n";
  printmap(m);
  std::cout << "map number two:\n";
  printmap(m2);

  std::map<std::string, std::vector<std::string>> m3 = ::max(m, m2);
  std::map<std::string, std::vector<std::string>> m4 = std::max(m, m2);

  std::cout << "Max map according to me:\n";
  printmap(m3);
  std::cout << "Max map according to std:\n";
  printmap(m4);

  m3 = ::min(m, m2);
  m4 = std::min(m, m2);

  std::cout << "Min map according to me:\n";
  printmap(m3);
  std::cout << "Min map according to std:\n";
  printmap(m4);
}
