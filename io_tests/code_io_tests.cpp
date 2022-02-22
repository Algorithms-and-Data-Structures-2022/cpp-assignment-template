#include <iostream>

#include "assignment/code.hpp"

int main(int argc, char** argv) {
  for (int i = 1; i < argc; ++i) {
    const int num = std::atoi(argv[i]);
    std::cout << num * num << '\n';
  }

  return 0;
}