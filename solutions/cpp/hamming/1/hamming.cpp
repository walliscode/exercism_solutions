#include "hamming.h"
#include <stdexcept>

namespace hamming {

int compute(const std::string &strand_one, const std::string &strand_two) {
  int errors{0};

  if (strand_one.size() != strand_two.size())
    throw std::domain_error("strand sizes do not match");

  for (size_t i{0}; i < strand_one.size(); i++) {
    if (strand_one[i] != strand_two[i])
      errors++;
  }
  return errors;
}

} // namespace hamming
