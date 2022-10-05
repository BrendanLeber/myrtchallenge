/**
 * @file tests/patterns_feature.cpp
 * @brief Tests for patterns and support functions.
 * @author Brendan Leber <brendan@brendanleber.com>
 * @copyright Copyright 2022 by Brendan Leber.  Some rights reserved, see LICENSE.
 */

#include <cmath>

#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>

#include <myrtchallenge/patterns.hpp>

#include "catch_helpers.hpp"


// Background:
static auto black = color(0, 0, 0);
static auto white = color(1, 1, 1);


SCENARIO("Creating a stripe pattern.", "[patterns]") {
    GIVEN("pattern <- stripe_pattern(white, black)") {
        auto pattern = stripe_pattern(white, black);
        THEN("pattern.a = white") {
            REQUIRE(pattern->a == white);
            AND_THEN("pattern.b = black") {
                REQUIRE(pattern->b == black);
            }
        }
    }
}


SCENARIO("A stripe pattern is constant in y.", "[patterns]") {
    GIVEN("pattern <- stripe_pattern(white, black)") {
        auto pattern = stripe_pattern(white, black);
        THEN("stripe_at(pattern, point(0, 0, 0)) = white") {
            REQUIRE(stripe_at(pattern, point(0, 0, 0)) == white);
            AND_THEN("stripe_at(pattern, point(0, 1, 0)) = white") {
                REQUIRE(stripe_at(pattern, point(0, 1, 0)) == white);
                AND_THEN("stripe_at(pattern, point(0, 2, 0)) = white") {
                    REQUIRE(stripe_at(pattern, point(0, 2, 0)) == white);
                }
            }
        }
    }
}


SCENARIO("A stripe pattern is constant in z.", "[patterns]") {
    GIVEN("pattern <- stripe_pattern(white, black)") {
        auto pattern = stripe_pattern(white, black);
        THEN("stripe_at(pattern, point(0, 0, 0)) = white") {
            REQUIRE(stripe_at(pattern, point(0, 0, 0)) == white);
            AND_THEN("stripe_at(pattern, point(0, 0, 1)) = white") {
                REQUIRE(stripe_at(pattern, point(0, 0, 1)) == white);
                AND_THEN("stripe_at(pattern, point(0, 0, 2)) = white") {
                    REQUIRE(stripe_at(pattern, point(0, 0, 2)) == white);
                }
            }
        }
    }
}


SCENARIO("A stripe pattern alternates in x.", "[patterns]") {
    GIVEN("pattern <- stripe_pattern(white, black)") {
        auto pattern = stripe_pattern(white, black);
        THEN("stripe_at(pattern, point(0, 0, 0)) = white") {
            REQUIRE(stripe_at(pattern, point(0, 0, 0)) == white);
            AND_THEN("stripe_at(pattern, point(0.9, 0, 0) = white") {
                REQUIRE(stripe_at(pattern, point(0.9, 0, 0)) == white);
                AND_THEN("stripe_at(pattern, point(1, 0, 0)) = black") {
                    REQUIRE(stripe_at(pattern, point(1, 0, 0)) == black);
                    AND_THEN("stripe_at(pattern, point(-0.1, 0, 0)) = black") {
                        REQUIRE(stripe_at(pattern, point(-0.1, 0, 0)) == black);
                        AND_THEN("stripe_at(pattern, point(-1, 0, 0)) = black") {
                            REQUIRE(stripe_at(pattern, point(-1, 0, 0)) == black);
                            AND_THEN("stripe_at(pattern, point(-1.1, 0, 0)) = white") {
                                REQUIRE(stripe_at(pattern, point(-1.1, 0, 0)) == white);
                            }
                        }
                    }
                }
            }
        }
    }
}
