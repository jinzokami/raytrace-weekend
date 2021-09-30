#pragma once

#include <cmath>

struct vec3 {
    double x = 0, y = 0, z = 0;
    vec3();
    vec3(double s);
    vec3(double x, double y, double z);

    double dot(const vec3& rhs);
    vec3 cross(const vec3& rhs);
    double length();
    double magnitude();
    vec3 normalize();
};

inline vec3 operator+(const vec3& lhs, const vec3& rhs) {
    return vec3(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
}

inline vec3 operator-(const vec3& lhs, const vec3& rhs) {
    return vec3(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
}

inline vec3 operator/(double lhs, const vec3& rhs) {
    return vec3(lhs / rhs.x, lhs / rhs.y, lhs / rhs.z);
}

inline vec3 operator/(const vec3& lhs, double rhs) {
    return vec3(lhs.x / rhs, lhs.y / rhs, lhs.z / rhs);
}

inline vec3 operator*(double lhs, const vec3& rhs) {
    return vec3(lhs * rhs.x, lhs * rhs.y, lhs * rhs.z);
}

inline vec3 operator*(const vec3& lhs, double rhs) {
    return vec3(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs);
}

using p3 = vec3;