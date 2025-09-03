#include "pangram.h"
#include <bitset>
#include <cctype>
#include <stdexcept>

namespace pangram {

bool is_pangram(const std::string &sentence) {
  if (sentence.size() < 26)
    return false;

  std::bitset<26> pangram_test;

  for (char c : sentence) {
    if (!std::isalpha(c))
      continue;

    size_t position = tolower(c) - 'a';

    if (position > 26)
      throw std::runtime_error("Position is larger that the alphabet");
    pangram_test.set(position);
  }

  return pangram_test.all();
}

} // namespace pangram
