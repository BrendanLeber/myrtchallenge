/**
 * @file src/intersections.cpp
 * @brief Definition of intersections and support functions.
 * @author Brendan Leber <brendan@brendanleber.com>
 * @copyright Copyright 2022 by Brendan Leber.  Some rights reserved, see LICENSE.
 */

#include <cmath>

#include "myrtchallenge/intersections.hpp"
#include "myrtchallenge/spheres.hpp"
#include "myrtchallenge/tuples.hpp"

#include "primitives.hpp"


Intersection intersection(double_t t, SpherePtr object)
{
    return Intersection{t, object};
}


Intersections intersections(std::initializer_list<Intersection> is)
{
    Intersections results;
    results.reserve(is.size());
    for (auto& i : is)
        results.push_back(i);
    return results;
}
