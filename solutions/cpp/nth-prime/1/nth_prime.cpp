#include "nth_prime.h"
#include <cmath>
#include <stdexcept>

namespace nth_prime {

int nth(int required_prime) {

  // the nth prime will be set and returned
  int nth_prime{0};

  if (required_prime == 0)
    throw std::domain_error("n must be greater than 0");

  int counter{2};

  // keep on iterating until the reqired number of prime numbers is hit
  while (required_prime > 0) {

    // set to false if modulo calc is 0
    bool is_prime{true};
    // end point is the sqrt of the number
    size_t sqroot = std::sqrt(counter);
    for (size_t i{2}; i <= sqroot; i++) {
      if ((counter % i) == 0)
        is_prime = false;
    }

    if (is_prime)
      required_prime--;

    if (required_prime == 0)
      return counter;

    counter++;
  }
  return nth_prime;
}

} // namespace nth_prime
