#include <iostream>
#include <cmath>

#include "mycomplex.h"

using namespace std;

Complex::Complex(double aRe, double aIm) {
  Re = aRe;
  Im = aIm;
}

Complex::Complex(const Complex& o) {
  Re = o.Re;
  Im = o.Im;
}

Complex::~Complex() {
  Re = 0.0;
  Im = 0.0;
}

void Complex::Set(double aRe, double aIm) {
  Re = aRe;
  Im = aIm;
}

Complex::operator double() { return abs(); }

double Complex::abs() { return sqrt(Re * Re + Im * Im); }

Complex Complex::operator+(const Complex& o) {
  Complex r;
  r.Re = Re + o.Re;
  r.Im = Im + o.Im;
  return r;
}

Complex Complex::operator-(const Complex& o) {
  Complex r;
  r.Re = Re - o.Re;
  r.Im = Im - o.Im;
  return r;
}

Complex Complex::operator+(const double& s) {
  Complex r;
  r.Re = Re + s;
  r.Im = Im;
  return r;
}

Complex Complex::operator-(const double& s) {
  Complex r(*this);
  r.Re = Re - s;
  return r;
}

Complex Complex::operator*(const Complex& o) {
  Complex r;
  r.Re = Re * o.Re - Im * o.Im;
  r.Im = Re * o.Im + Im * o.Re;
  return r;
}

Complex Complex::operator*(const double& s) {
  Complex r;
  r.Re = Re * s;
  r.Im = Im * s;
  return r;
}

Complex Complex::operator/(const double& s) {
  Complex r;
  r.Re = Re / s;
  r.Im = Im / s;
  return r;
}

Complex& Complex::operator+=(const Complex& o) {
  Re += o.Re;
  Im += o.Im;
  return *this;
}

Complex& Complex::operator-=(const Complex& o) {
  Re -= o.Re;
  Im -= o.Im;
  return *this;
}

Complex& Complex::operator*=(const Complex& o) {
  double tmpRe = Re;
  Re = Re * o.Re - Im * o.Im;
  Im = Im * o.Re + tmpRe * o.Im;
  return *this;
}

Complex& Complex::operator+=(const double& s) {
  Re += s;
  return *this;
}

Complex& Complex::operator-=(const double& s) {
  Re -= s;
  return *this;
}

Complex& Complex::operator*=(const double& s) {
  Re *= s;
  Im *= s;
  return *this;
}

Complex& Complex::operator/=(const double& s) {
  Re /= s;
  Im /= s;
  return *this;
}

Complex& Complex::operator=(const Complex& o) {
  Re = o.Re;
  Im = o.Im;
  return *this;
}

Complex& Complex::operator=(const double& s) {
  Re = s;
  Im = 0.0;
  return *this;
}

istream& operator>>(istream& stream, Complex& c) {
  char tmp[256];
  stream >> c.Re >> c.Im >> tmp;
  return stream;
}

ostream& operator<<(ostream& stream, Complex& c) {
  stream << c.Re;
  if (!(c.Im < 0)) stream << '+';
  stream << c.Im << 'i';
  return stream;
}

Complex operator+(const double& s, const Complex& c) {
  Complex r;
  r.Re = s + c.Re;
  r.Im = c.Im;
  return r;
}

Complex operator-(const double& s, const Complex& c) {
  Complex r;
  r.Re = s - c.Re;
  r.Im = -c.Im;
  return r;
}

Complex operator*(const double& s, const Complex& c) {
  Complex r;
  r.Re = s * c.Re;
  r.Im = s * c.Im;
  return r;
}