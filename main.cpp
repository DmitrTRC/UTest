#include <exception>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>

template<class T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &s) {
  os << "[ ";
  for (const auto &item : s) {
    os << item << " ";
  }

  return os << "]";
}

//Override the << operator for map
template<class K, class V>
std::ostream &operator<<(std::ostream &os, const std::map<K, V> map_object) {
  os << "{" << std::endl;

  for (const auto &[key, value] : map_object) {
    std::cout << key << " : " << value << std::endl;
  }

  return os << "}";
}

template<class T, class U>
void AssertEqual(const T &lhs, const U &rhs, const std::string &hint) {

  if (lhs != rhs) {

    std::ostringstream os;

    os << "Assertion failed: " << lhs << " != " << rhs << " Hint : " << hint;

    throw std::runtime_error(os.str());

  }
}

void Assert(bool expression, const std::string &hint) {

  AssertEqual(expression, true, hint);

}

int Add(int a, int b) {
  return a + b;
}

double Div(double a, double b) {
  return a / b;
}

std::string Concat(const std::string &a, const std::string &b) {

  return a + b;
}

void Test_Add() {
  AssertEqual(Add(2, 5), 7, "Add 2 + 5");
  AssertEqual(Add(3, 4), 8, "Line : 51");
  AssertEqual(Add(-1, -2), -3, "Line 52");

}

void Test_div() {
  AssertEqual(Div(8.999, 3.0), 3, " Line 57");
}

void Test_Dict() {
  std::map<int, std::string> dict1 = {

      {9984444, "Dmitry"},
      {9372837, "Irina"},
      {6000000, "Taxi"}

  };

  AssertEqual(dict1.size(), 3, "Size of Dict is 3 ");

  dict1[1000000] = "Boutique";

  AssertEqual(dict1.size(), 4, "Size of Dic is now 4");

  AssertEqual(dict1.at(9984444), "Dmitry", "9984444 is Dmitry");

  AssertEqual(dict1[6000000], "Vlad", "6000000 is a Taxi");

}

void Test_Dict2() {
  std::map<int, std::string> m1 = {
      {9984444, "Dmitry"},
      {9372837, "Irina"},
      {6000000, "Taxi"}
  };
  std::map<int, std::string> m2 = {
      {9372837, "Irina"},
      {6000000, "Taxi"},
      {9984444, "Dmitry"}
  };

  AssertEqual(m1, m2, " Expect they are equal");

}

//TODO: Implement set types for AssertEqual
void Test_Set() {
  std::set<int> s1 = {1, 4, 6, 8};
  std::set<int> s2 = {10, 2, 4, 5, 7};

//  AssertEqual(s1.size(), 4, "The size of set is 4");
//  AssertEqual(s1, s2, "This set are not Equal");

}

int main() {

//  std::vector<int> a = {1, 2, 3, 4, 5};
//  std::vector<int> b = {1, 2, 3, 4, 5};
//  std::vector<int> c = {1, 2};
//
//  Assert(Add(2, 5) == 7, "Test 2 + 5");
//  std::cout << " 2 + 5  = 7 Passed!" << std::endl;
//


  //Test_Add();
//  Test_div();
//  AssertEqual(Concat("Hello ", "world"), "Hello world", "Line 73 ");
//
//  AssertEqual(a, b, "Compare vectors a & b ");
//  std::cout << "a = b Passed " << std::endl;
//  AssertEqual(a, c, "Line 77");
//  std::cout << "a = c Passed " << std::endl;
//
//  AssertEqual(a, std::vector({1, 2, 3, 4, 5}), "Line 80");
//  std::cout << "a = {1,2,3,4,5} Passed " << std::endl;

//  Test_Dict();

  Test_Dict2();
  std::cout << "Dict Test Passed" << std::endl;

  return 0;

}
