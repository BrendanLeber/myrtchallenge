/**
 * @file tests/catch_helpers.cpp
 * @brief Helper functions for unit testing with Catch2.
 * @author Brendan Leber <brendan@brendanleber.com>
 * @copyright Copyright 2022 by Brendan Leber.  Some rights reserved, see LICENSE.
 */

#include <ostream>

#include <myrtchallenge/colors.hpp>
//#include <myrtchallenge/spheres.hpp>
#include <myrtchallenge/tuples.hpp>


inline std::ostream& operator<<(std::ostream& os, const Tuple& value)
{
    if (value.is_point())
        os << "point(";
    else
        os << "vector(";
    os << value.x << ", " << value.y << ", " << value.z << ')';
    return os;
}


inline std::ostream& operator<<(std::ostream& os, const Color& color)
{
    os << "color(" << color.red << ", " << color.green << ", " << color.blue << ')';
    return os;
}

#if 0
inline std::ostream& operator<<(std::ostream& os, const Material& material)
{
    return os
        << "material:\n"
        << "  color: " << material.color << '\n'
        << "  ambient: " << material.ambient << '\n'
        << "  diffuse: " << material.diffuse << '\n'
        << "  specular: " << material.specular << '\n'
        << "  shininess: " << material.shininess << '\n';
}


inline std::ostream& operator<<(std::ostream& os, const Sphere& sphere)
{
    return os
        << "sphere:\n"
        << "  matrix:  tbd\n"
        << sphere.material << '\n';
}
#endif
