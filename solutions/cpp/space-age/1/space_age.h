#pragma once

#include <cstddef>
namespace space_age {

class space_age {

public:
  /////////////////////////////////////////////////
  /// @brief Constructor for space_age taking in age in seconds
  ///
  /// @param age_in_seconds size_t representing age in seconds
  /////////////////////////////////////////////////
  space_age(const size_t age_in_seconds);

  /////////////////////////////////////////////////
  /// @brief Member variable representing age in seconds
  /////////////////////////////////////////////////
  const size_t age_in_seconds;

  /////////////////////////////////////////////////
  /// @brief returns age in seconds member
  ///
  /// @return age in seconds as size_t
  /////////////////////////////////////////////////
  size_t seconds() const;

  /////////////////////////////////////////////////
  /// @brief Calculates age as earth years using age_in_seconds
  ///
  /// @return age in earth years as float
  /////////////////////////////////////////////////
  float on_earth() const;

  /////////////////////////////////////////////////
  /// @brief Calculates age as mercury yearts
  ///
  /// @return age in mercury years as a float
  /////////////////////////////////////////////////
  float on_mercury() const;

  /////////////////////////////////////////////////
  /// @brief Calculates ages as venus years
  ///
  /// @return age in venus years as a float
  /////////////////////////////////////////////////
  float on_venus() const;

  float on_mars() const;

  float on_jupiter() const;

  float on_saturn() const;

  float on_uranus() const;

  float on_neptune() const;
};

} // namespace space_age
