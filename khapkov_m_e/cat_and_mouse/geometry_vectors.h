#pragma once
#include <limits>
#include <iosfwd>

const double eps = std::numeric_limits<double>::epsilon() * 2;

struct Rdec2D {
    double x = 0.0;
    double y = 0.0;
};

Rdec2D operator+(const Rdec2D& lhs, const Rdec2D& rhs);
Rdec2D& operator+=(Rdec2D& lhs, const Rdec2D& rhs);

Rdec2D operator*(const Rdec2D& lhs, const double rhs);
Rdec2D operator*(const double lhs, const Rdec2D& rhs);
Rdec2D& operator*=(Rdec2D& lhs, const double rhs);

Rdec2D operator-(const Rdec2D& arg);
Rdec2D operator-(const Rdec2D& lhs, const Rdec2D& rhs);
Rdec2D& operator-=(Rdec2D& lhs, const Rdec2D& rhs);

Rdec2D operator/(const Rdec2D& lhs, const double rhs);
Rdec2D& operator/=(Rdec2D& lhs, const double rhs);

bool operator==(const Rdec2D& lhs, const Rdec2D& rhs);
bool operator!=(const Rdec2D& lhs, const Rdec2D& rhs);

double Dot(const Rdec2D& lhs, const Rdec2D& rhs);
double Norm(const Rdec2D& v);

std::istream& operator>>(std::istream& in, Rdec2D& val);
std::ostream& operator<<(std::ostream& out, const Rdec2D val);

Rdec2D GetOrt(const Rdec2D& vec) {
    return vec / Norm(vec);
}


struct Rpol2D {
    double r = 0.0;
    double phi = 0.0;
};

Rdec2D ToDec(const Rpol2D& p);
Rpol2D ToPol(const Rdec2D& d);

Rpol2D operator+(const Rpol2D& lhs, const Rpol2D& rhs);
Rpol2D& operator+=(Rpol2D& lhs, const Rpol2D& rhs);

Rpol2D operator*(const Rpol2D& lhs, const double rhs);
Rpol2D operator*(const double lhs, const Rpol2D& rhs);
Rpol2D& operator*=(Rpol2D& lhs, const double rhs);

Rpol2D operator-(const Rpol2D& arg);
Rpol2D operator-(const Rpol2D& lhs, const Rpol2D& rhs);
Rpol2D operator-=(Rpol2D& lhs, const Rpol2D& rhs);

Rpol2D operator/(const Rpol2D& lhs, const double rhs);
Rpol2D& operator/=(Rpol2D& lhs, const double rhs);

double Dot(const Rpol2D& lhs, const Rpol2D& rhs);
double Norm(const Rpol2D& hs);
