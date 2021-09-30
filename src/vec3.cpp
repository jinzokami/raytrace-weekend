#include "vec3.hpp"

vec3::vec3() {}

vec3::vec3(double s) {
    this->x = s;
    this->y = s;
    this->z = s;
}

vec3::vec3(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

double vec3::dot(const vec3& rhs) {
    return x*rhs.x + y*rhs.y + z*rhs.z;
}

vec3 vec3::cross(const vec3& rhs) {
    return vec3(y*rhs.z - z*rhs.y, z*rhs.x - x*rhs.z, x*rhs.y - y*rhs.x);
}

double vec3::length() {
    return sqrt(x*x + y*y + z*z);
}

double vec3::magnitude() {
    return length();
}

vec3 vec3::normalize() {
    double magnitude = length();
    return vec3(x/magnitude, y/magnitude, z/magnitude);
}