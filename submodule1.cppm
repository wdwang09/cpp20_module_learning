module;

#include <random>

export module module1:sub1;

export int f_s1() {
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<int> dist(1, 100);
  return dist(mt);
}
