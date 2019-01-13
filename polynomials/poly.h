#ifndef POLY_H
#define POLY_H
#include <iostream>
#include <map>

using namespace std;

class Poly{
	
private:
	map <int, double, greater<int> > poly;
	void deleteZeroCoeffs();
	
public:
	Poly();
	Poly(double zero_power);
	double & operator[] (int position);
	friend Poly operator+ (const Poly& poly1, const Poly& poly2);
	friend Poly operator- (const Poly& poly1, const Poly& poly2);
	friend Poly operator* (const Poly& poly1, const Poly& poly2);
	Poly operator- () const;
	double operator() (double p) const;
	friend ostream & operator << (ostream& s, const Poly & poly1);

};

#endif /*POLY_H*/
