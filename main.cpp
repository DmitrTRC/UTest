#include "Test_Runner.hpp"

#include <map>
#include <set>
#include <vector>

using namespace UTest;

void Run_All_Tests();

struct Car {
  std::string Model;
  std::string Color;
  int Year{1980};
  int Power{0};

};

int Add(int a, int b) {
  return a + b;
}

double Div(double a, double b) {
  return a / b;
}

int main() {
  Run_All_Tests();

  return 0;

}

void Test_Add() {
  AssertEqual(Add(2, 5), 7, "Add 2 + 5");
  AssertEqual(Add(3, 4), 8, "Line : 51");
  AssertEqual(Add(-1, -2), -3, "Line 52");

}
void Test_Set() {
  std::set<int> a = {1, 2, 3, 4, 5};
  std::set<int> b = {7, 8, 9, 2, 1};

  AssertEqual(a.size(), b.size(), "The sizes are equal!");
  AssertEqual(a, b, "this sets are not equal");

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


//TODO : Implement support for custom type Car
void Test_Car() {

  Car c1 = {
      "BMW",
      "Blue",
      2000,
      286
  };

  Car c2 = {
      "Audi",
      "Black",
      2020,
      380
  };

//  AssertEqual(c1, c2, "This id the difference cars!");

}

void Run_All_Tests() {
  TestRunner tr;
  tr.RunTest(Test_Add, "Test_Add");
  tr.RunTest(Test_div, "Test_div");
  tr.RunTest(Test_Dict, "Test_Dict");
  tr.RunTest(Test_Dict2, "Test_Dict2");
  tr.RunTest(Test_Set, "Test_Set");
  tr.RunTest(Test_Car, "Test_Car");

}
