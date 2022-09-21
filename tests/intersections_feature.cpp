/**
 * @file tests/intersections_feature.cpp
 * @brief Tests for intersections and support functions.
 * @author Brendan Leber <brendan@brendanleber.com>
 * @copyright Copyright 2022 by Brendan Leber.  Some rights reserved, see LICENSE.
 */

#include <cmath>

#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>

#include <myrtchallenge/rays.hpp>
#include <myrtchallenge/spheres.hpp>

#include "catch_helpers.hpp"


TEST_CASE("An intersection encapsulates t and object.", "[intersections]")
{
    auto s = sphere();
    auto i = intersection(3.5, s);
    REQUIRE(i.t == 3.5);
    REQUIRE(i.object == s);
}


TEST_CASE("Aggregating intersections.", "[intersections]")
{
    auto s = sphere();
    auto i1 = intersection(1, s);
    auto i2 = intersection(2, s);
    auto xs = intersections({i1, i2});
    REQUIRE(xs.size() == 2);
    REQUIRE(xs[0].t == 1);
    REQUIRE(xs[1].t == 2);
}
