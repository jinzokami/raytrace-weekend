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
    return this->x*rhs.x + this->y*rhs.y + this->z*rhs.z;
}

vec3 vec3::cross(const vec3& rhs) {
    return vec3(this->y*rhs.z - this->z*rhs.y, this->z*rhs.x - this->x*rhs.z, this->x*rhs.y - this->y*rhs.x);
}

double vec3::length() {
    return sqrt(this->x*this->x + this->y*this->y + this->z*this->z);
}

double vec3::magnitude() {
    return length();
}

vec3 vec3::normalize() {
    double magnitude = length();
    return vec3(this->x/magnitude, this->y/magnitude, this->z/magnitude);
}