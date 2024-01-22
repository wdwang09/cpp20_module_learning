#include <iostream>
#include <vector>

import module1;

int main() {
  std::vector<int> v{f1(), f::f2(), f::f3(), f4(), f5(), g(), f_s1(), f_s2()};
  for (auto& item : v) {
    std::cout << item << " ";
  }
  std::cout << std::endl;
  return 0;
}
