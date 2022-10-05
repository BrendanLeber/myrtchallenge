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


Pattern_Ptr stripe_pattern(const Color& first, const Color& second)
{
    auto ptr = std::make_shared<Stripe_Pattern>();
    ptr->a = first;
    ptr->b = second;
    ptr->transform = identity_matrix();
    return ptr;
}


Color Stripe_Pattern::pattern_at(const Tuple& point) const
{
    if (std::fmod(std::floor(point.x), 2) == 0)
        return a;
    return b;
}


Color pattern_at_shape(const Pattern_Ptr& pattern, const Shape_Ptr& object, const Tuple& world_point)
{
    auto object_point = inverse(object->transform) * world_point;
    auto pattern_point = inverse(pattern->transform) * object_point;
    return pattern->pattern_at(pattern_point);
}


void set_pattern_transform(Pattern_Ptr& pattern, const Matrix& m)
{
    pattern->transform = m;
}
