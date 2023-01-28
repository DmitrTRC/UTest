//
// Created by Dmitry Morozov on 27/1/23.
//

#ifndef UTEST_MAIN__TEST_RUNNER_HPP_
#define UTEST_MAIN__TEST_RUNNER_HPP_

#include <iostream>
#include <map>
#include <sstream>
#include <vector>

namespace UTest {


// Override the << operator for std::vector
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

class TestRunner {
 public:
  TestRunner() : fail_count(0) {};

  ~TestRunner() {
    if (fail_count > 0) {
      std::cerr << fail_count << " Unit Tests Failed. terminate" << std::endl;
      exit(1);
    }
  }

  template<class TestFunc>
  void RunTest(TestFunc func, const std::string &testName) {

    try {
      func();
      std::cerr << testName << " : OK" << std::endl;
    } catch (std::runtime_error &ex) {
      std::cerr << testName << " Filed with : " << ex.what() << std::endl;
      ++fail_count;
    }
  };

 private:
  int fail_count;
};

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


}

#endif //UTEST_MAIN__TEST_RUNNER_HPP_
