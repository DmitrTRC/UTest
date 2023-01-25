#include <exception>
#include <iostream>
#include <sstream>
#include <vector>

template<class T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &s) {
  os << "[ ";
  for (const auto &item : s) {
    os << item << " ";
  }

  return os << "]";
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

int main() {

  std::vector<int> a = {1, 2, 3, 4, 5};
  std::vector<int> b = {1, 2, 3, 4, 5};
  std::vector<int> c  = {1, 2};

  Assert(Add(2, 5) == 7, "Test 2 + 5");
  std::cout << " 2 + 5  = 7 Passed!" << std::endl;



  //Test_Add();
//  Test_div();
  AssertEqual(Concat("Hello ", "world"), "Hello world", "Line 73 ");

  AssertEqual(a, b, "Compare vectors a & b ");
  std::cout << "a = b Passed " << std::endl;
  AssertEqual(a, c, "Line 77");
  std::cout << "a = c Passed " << std::endl;

  return 0;

}
