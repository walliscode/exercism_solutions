/////////////////////////////////////////////////
/// Preprocessor Directives
/////////////////////////////////////////////////
#pragma once

/////////////////////////////////////////////////
/// Headers
/////////////////////////////////////////////////
#include <string>

namespace star_map {

enum class System {
  Sol,
  EpsilonEridani,
  BetaHydri,
  AlphaCentauri,
  DeltaEridani,
  Omicron2Eridani
};
}

namespace heaven {

class Vessel {

public:
  Vessel(std::string name, int);

  Vessel(std::string, int, star_map::System);

  std::string name;
  int generation;
  star_map::System current_system{star_map::System::Sol};
  int busters{0};
  Vessel replicate(std::string name);

  void make_buster();

  bool shoot_buster();
};

std::string get_older_bob(Vessel &vessel_one, Vessel &vessel_two);

bool in_the_same_system(Vessel &vessel_one, Vessel &vessel_two);
} // namespace heaven
