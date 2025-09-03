/////////////////////////////////////////////////
/// Headers
/////////////////////////////////////////////////
#include "doctor_data.h"

namespace heaven {

/////////////////////////////////////////////////
Vessel::Vessel(std::string name, int generation)
    : name(name), generation(generation) {}

/////////////////////////////////////////////////
Vessel::Vessel(std::string name, int generation,
               star_map::System current_system)
    : name(name), generation(generation), current_system(current_system) {}

/////////////////////////////////////////////////
Vessel Vessel::replicate(std::string name) {

  return Vessel{name, generation + 1};
}

/////////////////////////////////////////////////
void Vessel::make_buster() { busters++; }

/////////////////////////////////////////////////
bool Vessel::shoot_buster() {

  if (busters > 0) {
    busters--;
    return true;

  } else {
    return false;
  }
}

/////////////////////////////////////////////////
std::string get_older_bob(Vessel &vessel_one, Vessel &vessel_two) {
  std::string older_name = vessel_one.generation < vessel_two.generation
                               ? vessel_one.name
                               : vessel_two.name;

  return older_name;
}

/////////////////////////////////////////////////
bool in_the_same_system(Vessel &vessel_one, Vessel &vessel_two) {
  return vessel_one.current_system == vessel_two.current_system ? true : false;
}
} // namespace heaven

