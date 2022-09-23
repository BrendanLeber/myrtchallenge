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


SCENARIO("An intersection encapsulates t and object.", "[intersections]")
{
    GIVEN("s <- sphere()") {
        auto s = sphere();
        WHEN("i <- intersection(3.5, s)") {
            auto i = intersection(3.5, s);
            THEN("i.t = 3.5") {
                REQUIRE(i.t == 3.5);
                AND_THEN("i.object = s") {
                    REQUIRE(i.object == s);
                }
            }
        }
    }
}


SCENARIO("Aggregating intersections.", "[intersections]")
{
    GIVEN("s <- sphere()") {
        auto s = sphere();
        AND_GIVEN("i1 <- intersection(1, s)") {
            auto i1 = intersection(1, s);
            AND_GIVEN("i2 <- intersection(2, s)") {
                auto i2 = intersection(2, s);
                WHEN("xs <- intersections(i1, i2)") {
                    auto xs = intersections({i1, i2});
                    THEN("xs.count = 2") {
                        REQUIRE(xs.size() == 2);
                        AND_THEN("xs[0].t = 1") {
                            REQUIRE(xs[0].t == 1);
                            AND_THEN("xs[1].t = 2") {
                                REQUIRE(xs[1].t == 2);
                            }
                        }
                    }
                }
            }
        }
    }
}


SCENARIO("The hit, when all intersections have positive t.", "[intersections]")
{
    GIVEN("s <- sphere()") {
        auto s = sphere();
        AND_GIVEN("i1 <- intersection(1, s)") {
            auto i1 = intersection(1, s);
            AND_GIVEN("i2 <- intersection(2, s)") {
                auto i2 = intersection(2, s);
                AND_GIVEN("xs <- intersections(i1, i2)") {
                    auto xs = intersections({i1, i2});
                    WHEN("i <- hit(xs)") {
                        auto i = hit(xs);
                        THEN("i = i1") {
                            REQUIRE(i == i1);
                        }
                    }
                }
            }
        }
    }
}


SCENARIO("The hit, when some intersections have negative t.", "[intersections]")
{
    GIVEN("s <- sphere()") {
        auto s = sphere();
        AND_GIVEN("i1 <- intersection(-1, s)") {
            auto i1 = intersection(-1, s);
            AND_GIVEN("i2 <- intersection(1, s)") {
                auto i2 = intersection(1, s);
                AND_GIVEN("xs <- intersections(i1, i2)") {
                    auto xs = intersections({i1, i2});
                    WHEN("i <- hit(xs)") {
                        auto i = hit(xs);
                        THEN("i = i2") {
                            REQUIRE(i == i2);
                        }
                    }
                }
            }
        }
    }
}


SCENARIO("The hit, when all intersections have negative t.", "[intersections]")
{
    GIVEN("s <- sphere()") {
        auto s = sphere();
        AND_GIVEN("i1 <- intersection(-2, s)") {
            auto i1 = intersection(-2, s);
            AND_GIVEN("i2 <- intersection(-1, s)") {
                auto i2 = intersection(-1, s);
                AND_GIVEN("xs <- intersections(i1, i2)") {
                    auto xs = intersections({i1, i2});
                    WHEN("i <- hit(xs)") {
                        auto i = hit(xs);
                        THEN("i is nothing") {
                            REQUIRE_FALSE(i.hit());
                        }
                    }
                }
            }
        }
    }
}


SCENARIO("The hit is always the lowest non-negative intersection.", "[intersections]")
{
    GIVEN("s <- sphere()") {
        auto s = sphere();
        AND_GIVEN("i1 <- intersection(5, s)") {
            auto i1 = intersection(5, s);
            AND_GIVEN("i2 <- intersection(7, s)") {
                auto i2 = intersection(7, s);
                AND_GIVEN("i3 <- intersection(-3, s)") {
                    auto i3 = intersection(-3, s);
                    AND_GIVEN("i4 <- intersection(2, s)") {
                        auto i4 = intersection(2, s);
                        AND_GIVEN("xs <-intersections(i1, i2, i3, i4)") {
                            auto xs = intersections({i1, i2, i3, i4});
                            WHEN("i <- hit(xs)") {
                                auto i = hit(xs);
                                THEN("i = i4") {
                                    REQUIRE(i == i4);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
