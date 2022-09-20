#pragma once

/**
 * @file src/spheres.cpp
 * @brief Declaration of spheres and support functions.
 * @author Brendan Leber <brendan@brendanleber.com>
 * @copyright Copyright 2022 by Brendan Leber.  Some rights reserved, see LICENSE.
 */

#include <cmath>
#include <vector>

#include "myrtchallenge/rays.hpp"


struct Sphere
{
};


Sphere sphere();


std::vector<double_t> intersect(const Sphere& s, const Ray& ray);
