#include "grade_school.h"
#include <algorithm>
#include <vector>

namespace grade_school {

/////////////////////////////////////////////////
const std::map<int, std::vector<std::string>> &school::roster() const {
  return school_roster;
}

/////////////////////////////////////////////////
void school::add(const std::string &name, const size_t grade) {
  school_roster[grade].push_back(name);
}

/////////////////////////////////////////////////
std::vector<std::string> school::grade(const size_t grade) const {

  auto result = school_roster.find(grade);
  if (result == school_roster.end()) {
    std::vector<std::string> empty_vec;
    return empty_vec;
  }
  auto vec_to_sort = result->second;
  std::sort(vec_to_sort.begin(), vec_to_sort.end());
  return vec_to_sort;
}
} // namespace grade_school
