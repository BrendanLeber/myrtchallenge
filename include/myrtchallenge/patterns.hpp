#pragma once

/**
 * @file include/myrtchallenge/patterns.hpp
 * @brief Declaration of patterns and support functions.
 * @author Brendan Leber <brendan@brendanleber.com>
 * @copyright Copyright 2022 by Brendan Leber.  Some rights reserved, see LICENSE.
 */

#include <cmath>
#include <memory>

#include "myrtchallenge/colors.hpp"
#include "myrtchallenge/matrices.hpp"
#include "myrtchallenge/tuples.hpp"


struct Shape;


struct Pattern : std::enable_shared_from_this<Pattern>
{
    Color a;
    Color b;
    Matrix transform;
};


struct Stripe_Pattern : public Pattern
{
};


using Pattern_Ptr = std::shared_ptr<Pattern>;

Pattern_Ptr stripe_pattern(const Color& first, const Color& second);


void set_pattern_transform(Pattern_Ptr& pattern, const Matrix& m);


Color stripe_at(const Pattern_Ptr& pattern, const Tuple& point);
Color stripe_at_object(const Pattern_Ptr& pattern, const std::shared_ptr<Shape>& object, const Tuple& world_point);
