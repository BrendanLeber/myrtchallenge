/**
 * @file src/patterns.cpp
 * @brief Definition of patterns and support functions.
 * @author Brendan Leber <brendan@brendanleber.com>
 * @copyright Copyright 2022 by Brendan Leber.  Some rights reserved, see LICENSE.
 */


#include <cassert>
#include <cmath>
#include <optional>

#include "myrtchallenge/patterns.hpp"

#include "primitives.hpp"


Pattern_Ptr stripe_pattern(const Color& first, const Color& second)
{
    auto ptr = std::make_shared<Stripe_Pattern>();
    ptr->a = first;
    ptr->b = second;
    return ptr;
}


Color stripe_at(const Pattern_Ptr& pattern, const Tuple& point)
{
    if (std::fmod(std::floor(point.x), 2) == 0)
        return pattern->a;
    return pattern->b;
}
