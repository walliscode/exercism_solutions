#include "two_fer.h"

namespace two_fer {

std::string two_fer(const std::string &name) {

  std::string name_to_insert;
  if (name == "") {
    name_to_insert = "you";
  } else {
    name_to_insert = name;
  }

  return "One for " + name_to_insert + ", one for me.";
}

} // namespace two_fer
