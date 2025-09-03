#include "grains.h"

#include <cstdint>

namespace grains {

/////////////////////////////////////////////////
uint64_t square(const std::size_t square_position) {

  uint64_t number_of_grains = 1ULL << (square_position - 1);
  return number_of_grains;
}
/////////////////////////////////////////////////
uint64_t total() { return UINT64_MAX; }

} // namespace grains
