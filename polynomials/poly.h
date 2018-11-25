#ifndef POLY_H
#define POLY_H
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Poly{
	
private:
	int i_power;
	vector<float> data;
	
public:
	Poly();
	Poly(int zero_power);
	Poly(const Poly & poly1);
	float & operator[] (int position);
	int getPower() const;
	float getPosition(int position) const;
	void swap (Poly & poly1);
	Poly & operator + (const Poly & poly1);
	Poly & operator - (const Poly & poly1);
	Poly operator - () const;
	Poly & operator = (const Poly & poly1);
	Poly & operator +=(const Poly & poly1);
	Poly & operator -=(const Poly & poly1);
	Poly & operator *=(const Poly & poly1);
	double operator() (double p) const;
	friend ostream & operator << (ostream& s, const Poly & poly1);

};


inline Poly operator+ (Poly & poly1, Poly & poly2){
    Poly n(poly1);
    n += poly2;
    return n;
}

inline Poly operator + (int i, Poly& poly1){
	Poly n(poly1);
	n += i;
	return n;
}
inline Poly operator - (int i, Poly& poly1){
	Poly n(poly1);
	n -= i;
	return n;
}
inline Poly operator * (int i, Poly& poly1){
	Poly n(poly1);
	n *= i;
	return n;
}


inline Poly operator* (Poly& poly1, Poly& poly2){
    Poly n(poly1);
    n *= poly2;
    return n;
}

#endif /*POLY_H*/
