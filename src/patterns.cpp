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
#include "myrtchallenge/shapes.hpp"

#include "primitives.hpp"


void set_pattern_transform(Pattern_Ptr& pattern, const Matrix& m)
{
    pattern->transform = m;
}


Pattern_Ptr stripe_pattern(const Color& first, const Color& second)
{
    auto ptr = std::make_shared<Stripe_Pattern>();
    ptr->a = first;
    ptr->b = second;
    ptr->transform = identity_matrix();
    return ptr;
}


Color stripe_at(const Pattern_Ptr& pattern, const Tuple& point)
{
    if (std::fmod(std::floor(point.x), 2) == 0)
        return pattern->a;
    return pattern->b;
}


Color stripe_at_object(const Pattern_Ptr& pattern, const Shape_Ptr& object, const Tuple& world_point)
{
    auto object_point = inverse(object->transform) * world_point;
    auto pattern_point = inverse(pattern->transform) * object_point;
    return stripe_at(pattern, pattern_point);
}
