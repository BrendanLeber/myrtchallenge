/**
 * @file src/spheres.cpp
 * @brief Definition of spheres and support functions.
 * @author Brendan Leber <brendan@brendanleber.com>
 * @copyright Copyright 2022 by Brendan Leber.  Some rights reserved, see LICENSE.
 */

#include <cmath>

#include "myrtchallenge/intersections.hpp"
#include "myrtchallenge/spheres.hpp"
#include "myrtchallenge/tuples.hpp"

#include "primitives.hpp"


SpherePtr sphere()
{
    return std::make_shared<Sphere>();
}


Intersections intersect(SpherePtr sphere, const Ray& ray)
{
    Intersections results;

    // the vector from the sphere's center to the ray origin
    // remember: the sphere is centered at the world origin
    auto sphere_to_ray = ray.origin - point(0, 0, 0);

    auto a = dot(ray.direction, ray.direction);
    auto b = 2 * dot(ray.direction, sphere_to_ray);
    auto c = dot(sphere_to_ray, sphere_to_ray) - 1;

    auto discriminant = std::pow(b, 2) - 4 * a * c;
    if (discriminant < 0)
        return results;

    results.resize(2);
    results[0] = Intersection{(-b - std::sqrt(discriminant)) / (2 * a), sphere};
    results[1] = Intersection{(-b + std::sqrt(discriminant)) / (2 * a), sphere};

    return results;
}
