#pragma once

namespace triangle {

enum class flavor { equilateral, isosceles, scalene };

flavor kind(const float a, const float b, const float c);
} // namespace triangle
