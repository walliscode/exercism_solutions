#pragma once

#include <map>
#include <string>
#include <vector>
namespace grade_school {

class school {

private:
  std::map<int, std::vector<std::string>> school_roster;

public:
  school() = default;

  const std::map<int, std::vector<std::string>> &roster() const;

  void add(const std::string &name, const int grade);

  std::vector<std::string> grade(const int grade) const;
};

} // namespace grade_school
