#include <iostream>
#include <span>

#include "assignment/code.hpp"

int main(int argc, char** argv) {
  const auto args = std::span(argv, argc);

  for (int i = 1; i < args.size(); ++i) {
    const int num = std::atoi(args[i]);
    std::cout << num * num << '\n';
  }

  return 0;
}