#ifndef VEC3H
#define VEC3H

#include <math.h>
#include <stdio.h>
#include <iostream>

class vec3 {
    public:
        vec3() {}
        vec3(float e0, float e1, float e2) { e[0] = e0; e[1] = e1; e[2] = e2; }
        inline float x() const { return e[0]; }
        inline float y() const { return e[1]; }
        inline float z() const { return e[2]; }
        inline float r() const { return e[0]; }
        inline float g() const { return e[1]; }
        inline float b() const { return e[2]; }

        inline const vec3& operator+() const { return *this; }
        inline vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
        inline float operator[](int i) const { return e[i]; }
        inline float& operator[](int i) { return e[i]; }

        inline vec3& operator+=(const vec3 &v2) {
            e[0] += v2.e[0]; e[1] += v2.e[1]; e[2] += v2.e[2];
            return *this;
        }
        inline vec3& operator-=(const vec3 &v2);
        inline vec3& operator*=(const vec3 &v2);
        inline vec3& operator/=(const vec3 &v2);
        inline vec3& operator*=(const float t);
        inline vec3& operator/=(const float t) {
            e[0] /= t; e[1] /= t; e[2] /= t;
            return *this;
        }

        inline float length() const { return sqrt(e[0]*e[0] + e[1]*e[1] + e[2]*e[2]); }
        inline float squared_length() const { return e[0]*e[0] + e[1]*e[1] + e[2]*e[2]; }
        inline void make_unit_vector();

        float e[3];
};

inline vec3 operator+(const vec3 &v1, const vec3 &v2) {
    return vec3(v1.e[0] + v2.e[0], v1.e[1] + v2.e[1], v1.e[2] + v2.e[2]);
}


inline vec3 operator-(const vec3 &v1, const vec3 &v2) {
    return vec3(v1.e[0] - v2.e[0], v1.e[1] - v2.e[1], v1.e[2] - v2.e[2]);
}


inline vec3 operator*(const vec3 &v1, const vec3 &v2) {
    return vec3(v1.e[0] * v2.e[0], v1.e[1] * v2.e[1], v1.e[2] * v2.e[2]);
}

inline vec3 operator*(const float f, const vec3 &v2) {
    return vec3(f * v2.e[0], f * v2.e[1], f * v2.e[2]);
}

inline vec3 operator/(const vec3 &v1, const vec3 &v2) {
    return vec3(v1.e[0] / v2.e[0], v1.e[1] / v2.e[1], v1.e[2] / v2.e[2]);
}

inline vec3 operator/(const vec3 &v1, const float f) {
    return vec3(v1.e[0] / f, v1.e[1] / f, v1.e[2] / f);
}

inline float dot(const vec3 &v1, const vec3 &v2) {
    return v1.e[0] * v2.e[0] + v1.e[1] * v2.e[1] + v1.e[2] * v2.e[2];
}

inline vec3 cross(const vec3 &v1, const vec3 &v2) {
    return vec3(
        v1.e[1] * v2.e[2] - v1.e[2] * v2.e[1],
        -(v1.e[0] * v2.e[2] - v1.e[2] * v2.e[0]),
        v1.e[0] * v2.e[1] - v1.e[1] * v2.e[0]);
}

inline vec3 unit_vector(vec3 v) {
    return v / v.length();
}

std::ostream &operator<<(std::ostream &os, vec3 const &v) { 
    return os << v.e[0] << "," << v.e[1] << "," << v.e[2] << "\n";
}

#endif