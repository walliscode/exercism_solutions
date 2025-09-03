#include "nucleotide_count.h"
#include <stdexcept>

namespace nucleotide_count {

std::map<char, int> count(const std::string &sequence) {

  // create map to add to
  std::map<char, int> counter{{'A', 0}, {'C', 0}, {'G', 0}, {'T', 0}};

  // return early if empty sequence
  if (sequence.empty())
    return counter;

  // cycle through and add to map
  for (const char &c : sequence) {
    auto it = counter.find(c);
    if (it == counter.end())
      throw std::invalid_argument("not a corrrect base pair");

    it->second++;
  }
  return counter;
}

} // namespace nucleotide_count
