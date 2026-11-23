#ifndef VEC2_H
#define VEC2_H
#include <cmath>

struct Vec2 {
    float x, y;
    Vec2() : x(0), y(0) {}
    Vec2(float x_, float y_) : x(x_), y(y_) {}

    Vec2 operator+(const Vec2& b) const { return Vec2(x + b.x, y + b.y); }
    Vec2 operator-(const Vec2& b) const { return Vec2(x - b.x, y - b.y); }
    Vec2 operator*(float s) const { return Vec2(x * s, y * s); }

    float dot(const Vec2& b) const { return x * b.x + y * b.y; }
    float len() const { return std::hypot(x, y); }

    Vec2 normalize() const {
        // TODO[A]: 向量归一化，注意长度接近 0 的保护，防止除零
        return *this;
    }
};
#endif
