/**
 * @file tests/transformations_feature.cpp
 * @brief Tests for matrix transformations and support functions.
 * @author Brendan Leber <brendan@brendanleber.com>
 * @copyright Copyright 2022 by Brendan Leber.  Some rights reserved, see LICENSE.
 */

#include <algorithm>

#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>

#include <myrtchallenge/transformations.hpp>
#include <myrtchallenge/tuples.hpp>


TEST_CASE("Multiplying by a translation matrix.", "[transformations]")
{
    auto transform = translation(5, -3, 2);
    auto p = point(-3, 4, 5);
    REQUIRE(transform * p == point(2, 1, 7));
}


TEST_CASE("Multiplying by the inverse of a translation matrix.", "[transformations]")
{
    auto transform = translation(5, -3, 2);
    auto inv = inverse(transform);
    auto p = point(-3, 4, 5);
    REQUIRE(inv * p == point(-8, 7, 3));
}


TEST_CASE("Translation does not affect vectors.", "[transformations]")
{
    auto transform = translation(5, -3, 2);
    auto v = vector(-3, 4, 5);
    REQUIRE(transform * v == v);
}
