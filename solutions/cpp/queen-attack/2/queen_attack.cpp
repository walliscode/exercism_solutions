#include "queen_attack.h"
#include <stdexcept>

namespace queen_attack {

chess_board::chess_board(const std::pair<int, int> white,
                         const std::pair<int, int> black) {

  if (white.first < 0 || white.second < 0 || black.second < 0 ||
      black.first < 0)
    throw std::domain_error("positions must be positive integers");

  if (white.first > 7 || white.second > 7 || black.second > 7 ||
      black.first > 7)
    throw std::domain_error("positions must be on the board");

  if (white == black)
    throw std::domain_error("positions must be distinct");

  _white = white;
  _black = black;
}

/////////////////////////////////////////////////
std::pair<int, int> chess_board::white() const { return _white; };

/////////////////////////////////////////////////
std::pair<int, int> chess_board::black() const { return _black; };

/////////////////////////////////////////////////
bool chess_board::can_attack() const {

  // can attack on same row
  if (_white.first == _black.first)
    return true;

  /// can attack on same column
  if (_white.second == _black.second)
    return true;

  int x_difference = _white.first - _black.first;
  int y_difference = _white.second - _black.second;

  if (std::abs(x_difference) == std::abs(y_difference))
    return true;
  return false;
}
} // namespace queen_attack
