#include "raindrops.h"
#include <string>

namespace raindrops {

std::string convert(int number) {
  std::string result;

  if (number % 3 == 0)
    result.append("Pling");
  if (number % 5 == 0)
    result.append("Plang");
  if (number % 7 == 0)
    result.append("Plong");

  if (result.empty())
    result.append(std::to_string(number));
  return result;
}

} // namespace raindrops
