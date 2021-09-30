#pragma once

#include "vec3.hpp"

struct ray {
    vec3 origin, direction;
    ray();
    ray(const vec3& origin, const vec3& direction);

    vec3 at(double t) {
        return origin + t*direction;
    }
};