#include "grade_school.h"
#include <algorithm>
#include <vector>

namespace grade_school {

/////////////////////////////////////////////////
const std::map<int, std::vector<std::string>> &school::roster() const {
  return school_roster;
}

/////////////////////////////////////////////////
void school::add(const std::string &name, const int grade) {
  school_roster[grade].push_back(name);
}

/////////////////////////////////////////////////
std::vector<std::string> school::grade(const int grade) const {
  auto it = school_roster.find(grade);
  if (it == school_roster.end()) {
    return {};
  }
  auto result = it->second;
  std::sort(result.begin(), result.end());
  return result;
}
} // namespace grade_school
