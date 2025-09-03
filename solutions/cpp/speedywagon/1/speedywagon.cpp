#include "speedywagon.h"

namespace speedywagon {

// Enter your code below:

// Please don't change the interface of the uv_light_heuristic function
int uv_light_heuristic(std::vector<int> *data_array) {
  double avg{};
  for (auto element : *data_array) {
    avg += element;
  }
  avg /= data_array->size();
  int uv_index{};
  for (auto element : *data_array) {
    if (element > avg)
      ++uv_index;
  }
  return uv_index;
}

bool connection_check(pillar_men_sensor *sensor) {
  return sensor ? true : false;
}

int activity_counter(pillar_men_sensor *sensor, int sensor_capacity) {

  int total_activity{0};

  for (int i{0}; i < sensor_capacity; i++) {
    total_activity += sensor[i].activity;
  }
  return total_activity;
}

bool alarm_control(pillar_men_sensor *sensor) {
  if (!sensor)
    return false;

  else if (sensor->activity > 0)
    return true;

  else
    return false;
}

bool uv_alarm(pillar_men_sensor *sensor) {
  if (!sensor)
    return false;

  int uv_level = uv_light_heuristic(&sensor->data);

  if (uv_level > sensor->activity)
    return true;
  else
    return false;
  ;
}
} // namespace speedywagon
