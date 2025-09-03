#include "collatz_conjecture.h"
#include <stdexcept>

namespace collatz_conjecture {

int steps(int starting_number) {

  if (starting_number <= 0)
    throw std::domain_error("number must be greater than 0");
  // capture the number of steps
  int steps{0};

  while (starting_number > 1) {

    if (starting_number % 2 == 0)
      starting_number = starting_number / 2;

    else
      starting_number = (starting_number * 3) + 1;

    steps++;
  }

  return steps;
}

} // namespace collatz_conjecture
