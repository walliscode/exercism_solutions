#include "reverse_string.h"
#include <algorithm>

namespace reverse_string {

std::string reverse_string(std::string string_to_reverse) {
  std::reverse(string_to_reverse.begin(), string_to_reverse.end());

  return string_to_reverse;
}

} // namespace reverse_string
