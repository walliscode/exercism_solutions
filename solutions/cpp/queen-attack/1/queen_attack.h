#pragma once

#include <utility>
namespace queen_attack {

class chess_board {

  std::pair<int, int> _white;
  std::pair<int, int> _black;

public:
  chess_board(const std::pair<int, int> white, const std::pair<int, int> black);

  std::pair<int, int> white() const;
  std::pair<int, int> black() const;

  bool can_attack() const;
};

} // namespace queen_attack
