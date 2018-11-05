#pragma once
#ifndef __Complex_H__
#define __Complex_H__
#include <iostream>
#include <math.h>
using namespace std;

class Complex{
private:
	double Real, Imag;
public:
	Complex();
	Complex(double co);
	Complex(double Real, double Imag);
	Complex & operator= (const Complex & s);
	Complex & operator= (double co);
	Complex operator+ (Complex co) const;
	Complex operator- () const;
	Complex operator* (Complex co) const;
	Complex operator/ (Complex co) const;
	Complex & operator+= (Complex co);
	Complex & operator-= (Complex co);
	Complex & operator*= (Complex co);
	Complex & operator/= (Complex co);
	bool operator== (const Complex & co);
	friend Complex operator- (Complex, Complex);
	friend Complex operator* (Complex, Complex);
	friend Complex operator/ (Complex, Complex);
	friend ostream & operator << (ostream & s, const Complex & c);
	double realPart();
	double imaginaryPart();
	double amplitude();
	double phase();
	Complex conjugate();
};

inline Complex operator- (Complex s1, Complex s2){
  Complex n (s1);
  return n -= s2;
}

inline Complex operator* (Complex s1, Complex s2){
    Complex n (s1);
    return n *= s2;
}

inline Complex operator/ (Complex s1, Complex s2){
    Complex n (s1);
    return n /= s2;
}
#endif /* __Complex_H__ */
