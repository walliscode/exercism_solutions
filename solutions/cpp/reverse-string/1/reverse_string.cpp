#include "reverse_string.h"

namespace reverse_string {

std::string reverse_string(std::string string_to_reverse) {
  if (string_to_reverse.empty())
    return "";
  std::string reverse_string;

  for (int i = string_to_reverse.size(); i >= 0; i--) {
    reverse_string.push_back(string_to_reverse[i]);
  }

  return reverse_string;
}

} // namespace reverse_string
