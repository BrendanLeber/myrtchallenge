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


TEST_CASE("A scaling matrix applied to a point.", "[transformations]")
{
    auto transform = scaling(2, 3, 4);
    auto p = point(-4, 6, 8);
    REQUIRE(transform * p == point(-8, 18, 32));
}


TEST_CASE("A scaling matrix applied to a vector.", "[transformations]")
{
    auto transform = scaling(2, 3, 4);
    auto v = vector(-4, 6, 8);
    REQUIRE(transform * v == vector(-8, 18, 32));
}


TEST_CASE("Multiplying by the inverse of a scaling matrix.", "[transformations]")
{
    auto transform = scaling(2, 3, 4);
    auto inv = inverse(transform);
    auto v = vector(-4, 6, 8);
    REQUIRE(inv * v == vector(-2, 2, 2));
}


TEST_CASE("Reflection is scaling by a negative value.", "[transformations]")
{
    auto transform = scaling(-1, 1, 1);
    auto p = point(2, 3, 4);
    REQUIRE(transform * p == point(-2, 3, 4));
}


TEST_CASE("Rotating a point around the x axis.", "[transformations]")
{
    auto p = point(0, 1, 0);
    auto half_quarter = rotation_x(M_PI_4);
    auto full_quarter = rotation_x(M_PI_2);
    REQUIRE(half_quarter * p == point(0, M_SQRT2 / 2, M_SQRT2 / 2));
    REQUIRE(full_quarter * p == point(0, 0, 1));
}


TEST_CASE("The inverse of an x-rotation rotates in the opposite direction.", "[transformations]")
{
    auto p = point(0, 1, 0);
    auto half_quarter = rotation_x(M_PI_4);
    auto inv = inverse(half_quarter);
    REQUIRE(inv * p == point(0, M_SQRT2 / 2, -M_SQRT2 / 2));
}


TEST_CASE("Rotating a point around the y axis.", "[transformations]")
{
    auto p = point(0, 0, 1);
    auto half_quarter = rotation_y(M_PI_4);
    auto full_quarter = rotation_y(M_PI_2);
    REQUIRE(half_quarter * p == point(M_SQRT2 / 2, 0, M_SQRT2 / 2));
    REQUIRE(full_quarter * p == point(1, 0, 0));
}


TEST_CASE("Rotation a point around the z axis.", "[transformations]")
{
    auto p = point(0, 1, 0);
    auto half_quarter = rotation_z(M_PI_4);
    auto full_quarter = rotation_z(M_PI_2);
    REQUIRE(half_quarter * p == point(-M_SQRT2 / 2, M_SQRT2 / 2, 0));
    REQUIRE(full_quarter * p == point(-1, 0, 0));
}
