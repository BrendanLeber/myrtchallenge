#pragma once

/**
 * @file include/myrtchallenge/intersections.cpp
 * @brief Declaration of intersections and support functions.
 * @author Brendan Leber <brendan@brendanleber.com>
 * @copyright Copyright 2022 by Brendan Leber.  Some rights reserved, see LICENSE.
 */

#include <cmath>
#include <initializer_list>
#include <memory>
#include <vector>

#include "myrtchallenge/rays.hpp"
//#include "myrtchallenge/spheres.hpp"


struct Sphere;
using SpherePtr = std::shared_ptr<Sphere>;


struct Intersection
{
    double_t t;
    SpherePtr object;
};


using Intersections = std::vector<Intersection>;


Intersection intersection(double_t t, SpherePtr object);
Intersections intersections(std::initializer_list<Intersection> is);
