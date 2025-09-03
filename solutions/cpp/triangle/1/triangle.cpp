#include "triangle.h"
#include <stdexcept>

namespace triangle {

/////////////////////////////////////////////////
flavor kind(const float a, const float b, const float c) {
  // sort out domain_error: e.g is this a valid triangle
  if (a <= 0 || b <= 0 || c <= 0) {
    throw std::domain_error("not a valid triangle");
  } else if (!((a + b >= c) && (a + c >= b) && (b + c >= a))) {
    throw std::domain_error(
        "the sum of any two sides must be greater or equal to the third");
  }

  // find type of triangle
  if (a == b) {
    if (a == c) {
      return flavor::equilateral;
    } else {
      return flavor::isosceles;
    }
  } else {
    if (a == c || b == c) {
      return flavor::isosceles;
    } else {
      return flavor::scalene;
    }
  }
  // final guard statement for slip through statements
  throw std::domain_error("not a valiad triangle");
}

} // namespace triangle
