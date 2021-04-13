#include <iostream>
#include <cmath>
#include "mycomplex.h"
using namespace std;
   Complex::Complex(double aRe, double aIm)
{
       Re = aRe;
       Im = aIm;
}
   Complex::Complex(const Complex& aRval)
{
   Re =aRval.Re; Im=aRval.Im;
}
   Complex::~Complex()
{
   aRe=0.0;
   aIm=0.0;
}
void Complex::Set(double aRe, double aIm)
{
    Re = aRe; Im = aIm;
}
   Complex::operator double()
{
    return abs();
}

double Complex::abs()
{
return sqrt(Re*Re+Im*Im);
}
   Complex & Complex::operator + (const Complex & aRval)
{
   Complex Result;
   Result.Re = Re+ aRval. Re;
   Result.Im = Im + aRval.Im;
   return Result;
}
   Complex & Complex::operator - (const Complex & aRval)
{
   Complex Result;
   Result.Re = Re-aRval.Re;
   Result.Im = Im-aRval.Im;
   return Result;
}
   Complex & Complex::operator + (const double & aRval)
{
   Complex result;
   result.Re = Re +aval;
   result.Im = Im;
   return result;
}
   Complex & Complex::operator - (const  double & aRval)
{
   Complex Result(*this);
   Result.Re = Re - aRval;
   return Result;
}

   Complex & Complex::operator * (const Complex & aRval)
{
   Complex Result;
   Result.Re = Re * aRval.Re - Im * aRval.Im;
   Result.Im = Re * aRval.Im + Im * aRval.Re;
   return Result;
}

   Complex & Complex::operator * (const double & aRval)
{
   Complex Result;
   Result.Re =Re*aRval;
   Result.Im =Im*aRval;
   return Result;
}
   Complex & Complex::operator / (const double& aRval)
{
   Complex Result;
   Result.Re = Re / aRval;
   Result.Im = Im / aRval;
   return Result;
}

   Complex & Complex::operator += (const   Complex & aRval)
{
   Re += arval.Re;
   Im += arval.Im;
   return * this;
}
   Complex & Complex::operator -= (const Complex& aRval)
{
   Re -= aRval.Re;
   Im -= aRval.Im;
   return *this;
}

   Complex & Complex::operator *= (const Complex&aRval)
{
   double tmpRe = Re;
   Re = Re * aRval.Re - Im * aRval.Im;
   Im = Im * aRval.Re + tmpRe * aRval.Im;
   return *this;
}

   Complex & Complex::operator += (const double & aRval)
{
   Re+=aRval;
   return*this;
}

   Complex & Complex::operator -= (const double & aRval)                                      {
   Re -= aRval;
   return *this;
}
   Complex & Complex::operator *= (const double & aRval)
{
       Re *= aRval;
       Im *= aRval;
       return *this;
}
   Complex & Complex::operator /= (const double & aRval)
{
    Re/=aRval; Im /=aRval;
    return *this;
}
   Complex & Complex::operator = (const Complex & aRval)
{
    Re=aRval.Re;
    Im=aRval.Im;
    return *this;
}
   Complex & Complex::operator = (const double & aRval)
{
   Re = aRval;
   Im = 0.0;
   return *this;
}

   istream & operator >> (istream & istream, Complex & a)
{
   char tmp[256];
   stream >> a.Re >> a.Im >> tmp;
   return istream;
}
   istream & operator << (istream & istream, Complex & a)

{
   istream << a.Re;
   if(!(a.Im < 0)) istream << '+';
   istream << a.Im << 'i';
   return istream;
}

   Complex operator + (const double & aLval, const Complex & aRval)
{
   Complex Result;
   .Re= aLval + aRval.Re;
   Result. Im =  aRval.Im;
   return Result;
}
   Complex operator - (const double & aLval, const Complex & aRval)
{
   Complex Result;
   Result.Re = aLval - aRval.Re;
   Result.Im = -aRval.Im;
   return Result;
}

   Complex operator * (const double & aRval, const Complex & a)
{
   Complex r;
   r.Re = aRval * a.Re;
   r.Im = aRval * a.Im;
   return r;
}
