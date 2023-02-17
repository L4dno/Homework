

#include "geometry_vectors.h"
#include <cmath>
#include <iostream>





Rdec2D operator+(const Rdec2D& lhs, const Rdec2D& rhs) {
    return Rdec2D{ lhs.x + rhs.x, lhs.y + rhs.y };
}

Rdec2D& operator+=(Rdec2D& lhs, const Rdec2D& rhs) {
    return lhs = lhs + rhs;
}

Rdec2D operator*(const Rdec2D& lhs, const double rhs) {
    return Rdec2D{ lhs.x * rhs, lhs.y * rhs };
}

Rdec2D operator*(const double lhs, const Rdec2D& rhs) {
    return rhs * lhs;
}

Rdec2D& operator*=(Rdec2D& lhs, const double rhs) {
    return lhs = lhs * rhs;
}

Rdec2D operator-(const Rdec2D& arg) {
    return arg * -1;
}

double Dot(const Rdec2D& lhs, const Rdec2D& rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y;
}

double Norm(const Rdec2D& v) {
    return std::sqrt(v.x * v.x + v.y * v.y);
}

Rdec2D operator-(const Rdec2D& lhs, const Rdec2D& rhs) {
    return lhs + (-rhs);
}

Rdec2D& operator-=(Rdec2D& lhs, const Rdec2D& rhs) {
    return lhs = lhs - rhs;
}

Rdec2D operator/(const Rdec2D& lhs, const double rhs) {
    return lhs * (1 / rhs);
}

Rdec2D& operator/=(Rdec2D& lhs, const double rhs) {
    return  lhs = lhs / rhs;
}

bool operator==(const Rdec2D& lhs, const Rdec2D& rhs) {
    return (std::abs(lhs.x - rhs.x) < eps && std::abs(lhs.y - rhs.y) < eps);
}

bool operator!=(const Rdec2D& lhs, const Rdec2D& rhs) {
    return !(lhs == rhs);
}

std::istream& operator>>(std::istream& in, Rdec2D& val) {
    return in >> val.x >> val.y;
}

std::ostream& operator<<(std::ostream& out, const Rdec2D val) {
    return out << '{' << val.x << ',' << val.y << '}';
}

Rdec2D GetOrt(const Rdec2D& vec) {
    return vec / Norm(vec);
}

Rdec2D ToDec(const Rpol2D& p) {
    return { p.r * std::cos(p.phi), p.r * std::sin(p.phi) };
}

Rpol2D ToPol(const Rdec2D& d) {
    return { sqrt(d.x * d.x + d.y * d.y), std::atan(d.y / d.x) };
}

Rpol2D operator+(const Rpol2D& lhs, const Rpol2D& rhs) {
    auto lhs_d = ToDec(lhs);
    auto rhs_d = ToDec(rhs);
    return ToPol(lhs_d + rhs_d);
}

Rpol2D& operator+=(Rpol2D& lhs, const Rpol2D& rhs) {
    return lhs = lhs + rhs;
}

Rpol2D operator*(const Rpol2D& lhs, const double rhs) {
    return ToPol(ToDec(lhs) * rhs);
}

Rpol2D operator*(const double lhs, const Rpol2D& rhs) {
    return rhs * lhs;
}

Rpol2D& operator*=(Rpol2D& lhs, const double rhs) {
    return lhs = lhs * rhs;
}

Rpol2D operator-(const Rpol2D& arg) {
    return arg * -1;
}

double Dot(const Rpol2D& lhs, const Rpol2D& rhs) {
    return Dot(ToDec(lhs), ToDec(rhs));
}

double Norm(const Rpol2D& hs) {
    return hs.r;
}

Rpol2D operator/(const Rpol2D& lhs, const double rhs) {
    return lhs * (1 / rhs);
}

Rpol2D& operator/=(Rpol2D& lhs, const double rhs) {
    return lhs = lhs / rhs;
}

Rpol2D operator-(const Rpol2D& lhs, const Rpol2D& rhs) {
    return lhs + (-rhs);
}

Rpol2D operator-=(Rpol2D& lhs, const Rpol2D& rhs) {
    return lhs = lhs - rhs;
}