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
	//Complex operator+ (Complex co) const;
	Complex operator- ();
	Complex operator* (Complex co);
	Complex operator/ (Complex co);
	Complex & operator+= (Complex co);
	Complex & operator-= (Complex co);
	Complex & operator*= (Complex co);
	Complex & operator/= (Complex co);
	friend bool operator== (Complex s1, Complex s2);
	friend Complex operator+ (Complex s1, Complex s2);
	friend Complex operator- (Complex s1, Complex s2);
	friend Complex operator* (Complex s1, Complex s2);
	friend Complex operator/ (Complex s1, Complex s2);
	friend ostream & operator << (ostream & s, Complex co);
	double realPart();
	double imaginaryPart();
	double amplitude();
	double phase();
	Complex conjugate();
};

inline Complex operator+ (Complex s1, Complex s2){
  Complex n (s1);
  return n += s2;
}

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
inline bool operator== (Complex s1, Complex s2){
	Complex n (s1);
	return n.Real == s2.Real && n.Imag == s2.Imag;
}
#endif /* __Complex_H__ */
