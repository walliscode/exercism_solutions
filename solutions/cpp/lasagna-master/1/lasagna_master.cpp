#include "lasagna_master.h"

namespace lasagna_master {

/////////////////////////////////////////////////
int preparationTime(std::vector<std::string> layers, int avg_time_per_layer) {

  int number_of_layers{static_cast<int>(layers.size())};

  return number_of_layers * avg_time_per_layer;
}

/////////////////////////////////////////////////
amount quantities(std::vector<std::string> layers) {

  amount amount{0, 0.0};

  for (const auto &layer : layers) {
    if (layer == "noodles")
      amount.noodles += 50;
    else if (layer == "sauce")
      amount.sauce += 0.2;
  }

  return amount;
}

/////////////////////////////////////////////////
void addSecretIngredient(std::vector<std::string> &my_ingredients,
                         std::vector<std::string> friends_ingredients) {
  my_ingredients.back() = friends_ingredients.back();
}
/////////////////////////////////////////////////
void addSecretIngredient(std::vector<std::string> &my_ingredients,
                         const std::string &secret_ingredient) {
  my_ingredients.back() = secret_ingredient;
}

/////////////////////////////////////////////////
std::vector<double> scaleRecipe(const std::vector<double> &original_amount,
                                int portions) {

  std::vector<double> scaled_amounts;

  for (auto &ingredient : original_amount) {
    scaled_amounts.push_back(ingredient * portions * 0.5);
  }

  return scaled_amounts;
};

} // namespace lasagna_master
