#include "difference_of_squares.h"

namespace difference_of_squares {

int square_of_sum(int n) {

  int result{0};
  result = n + 1;
  result = result * n;
  result = result / 2;
  result = result * result;
  return result;
}

int sum_of_squares(int n) {

  int result{0};

  // step one
  result = (2 * n) + 1;
  result = result * (n + 1);
  result = result * n;
  result = result / 6;

  return result;
}

int difference(int n) { return square_of_sum(n) - sum_of_squares(n); }

} // namespace difference_of_squares
