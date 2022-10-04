/**
 * @file src/shapes.cpp
 * @brief Definition of shape base class and support functions.
 * @author Brendan Leber <brendan@brendanleber.com>
 * @copyright Copyright 2022 by Brendan Leber.  Some rights reserved, see LICENSE.
 */

#include <cmath>

#include "myrtchallenge/shapes.hpp"

#include "primitives.hpp"


bool Shape::operator==(const Shape& rhs) const
{
    if (transform != rhs.transform) {
        return false;
    }
    if (*material != *rhs.material) {
        return false;
    }
    return true;
}


Intersections intersect(Shape_Ptr shape, const Ray& ray)
{
    Intersections results;

    auto local_ray = transform(ray, inverse(shape->transform));
    return shape->local_intersect(local_ray);
}


Tuple normal_at(Shape_Ptr shape, const Tuple& point)
{
    auto local_point = inverse(shape->transform) * point;
    auto local_normal = shape->local_normal_at(local_point);
    auto world_normal = transpose(inverse(shape->transform)) * local_normal;
    world_normal.w = 0;
    return normalize(world_normal);
}


void set_transform(Shape_Ptr shape, const Matrix& m)
{
    shape->transform = m;
}


/**
 * Sphere and support functions.
 */

Shape_Ptr sphere()
{
    auto ptr = std::make_shared<Sphere>();
    ptr->transform = identity_matrix();
    ptr->material = material();
    return ptr;
}


Intersections Sphere::local_intersect(const Ray& ray)
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

    results.reserve(2);
    results.emplace_back(intersection((-b - std::sqrt(discriminant)) / (2 * a), shared_from_this()));
    results.emplace_back(intersection((-b + std::sqrt(discriminant)) / (2 * a), shared_from_this()));

    return results;
}


Tuple Sphere::local_normal_at(const Tuple& pt) const
{
    return pt - point(0, 0, 0);
}
