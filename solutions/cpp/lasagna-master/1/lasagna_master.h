#pragma once

#include <string>
#include <vector>
namespace lasagna_master {

struct amount {
  int noodles;
  double sauce;
};

int preparationTime(std::vector<std::string> layers,
                    int avg_time_per_layer = 2);

amount quantities(std::vector<std::string> layers);

void addSecretIngredient(std::vector<std::string> &my_ingredients,
                         std::vector<std::string> friends_ingredients);

void addSecretIngredient(std::vector<std::string> &my_ingredients,
                         const std::string &secret_ingredient);
std::vector<double> scaleRecipe(const std::vector<double> &original_amount,
                                int portions);
} // namespace lasagna_master
