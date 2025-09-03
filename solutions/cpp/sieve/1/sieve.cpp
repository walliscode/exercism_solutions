#include "sieve.h"
#include <iostream>
#include <ostream>
#include <vector>

namespace sieve {

bool is_prime(int n) {

  if (n <= 1)
    return false;
  if (n == 2)
    return true;
  if (n % 2 == 0)
    return false;
  for (int i = 3; i * i <= n; i += 2) {
    if (n % i == 0)
      return false;
  }
  return true;
}
std::vector<int> primes(int n) {

  // create return vector
  std::vector<int> prime_numbers;

  // create vector of bools to capture info about n
  std::vector<bool> non_prime_tracker(n + 1, false);

  for (int i = 2; i <= n; i++) {
    // skip if its been marked as a true
    if (non_prime_tracker[i])
      continue;

    // add to prime_numbers vector if it is prime
    if (is_prime(i))
      prime_numbers.push_back(i);

    // mark multiple of i as true as they are not primes
    for (int j = 2; i * j <= n; j++) {
      non_prime_tracker[i * j] = true;
    }
  }

  return prime_numbers;
}
} // namespace sieve
