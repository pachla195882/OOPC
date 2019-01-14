#include "poly.h"
#include <math.h>
#include <iostream>

Poly::Poly(){
}

Poly::Poly(double zeroPower){
	poly[0] = zeroPower;
}

double & Poly:: operator[] (int position){
	return poly[position];
}


Poly operator + (const Poly & poly1, const Poly & poly2){
	Poly addition;
	for(map<int, double >::const_iterator iterator = poly1.poly.begin(); iterator != poly1.poly.end(); iterator++){
		addition.poly[iterator->first] = iterator->second;
	}

	for(map<int, double >::const_iterator iterator = poly2.poly.begin(); iterator != poly2.poly.end(); iterator++){
		addition.poly[iterator->first] += iterator->second;
	}

	addition.deleteZeroCoeffs();	
	return addition;
}

Poly operator - (const Poly & poly1, const Poly & poly2){
	Poly subtraction;
	for(map<int, double >::const_iterator iterator = poly1.poly.begin(); iterator != poly1.poly.end(); iterator++){
		subtraction.poly[iterator->first] = iterator->second;
	}

	for(map<int, double >::const_iterator iterator = poly2.poly.begin(); iterator != poly2.poly.end(); iterator++){
		subtraction.poly[iterator->first] -= iterator->second;
	}

	subtraction.deleteZeroCoeffs();	
	return subtraction;
}

Poly operator * (const Poly & poly1, const Poly & poly2){
	Poly multiplication;

	for(map<int, double >::const_iterator iterator = poly1.poly.begin(); iterator != poly1.poly.end(); iterator++){
		for(map<int, double >::const_iterator iterator2 = poly2.poly.begin(); iterator2 != poly2.poly.end(); iterator2++){
			multiplication.poly[iterator->first + iterator2->first] += iterator->second * iterator2->second;
		}
	}
	
	multiplication.deleteZeroCoeffs();
	
	return multiplication;
}

Poly Poly::operator - () const{
	return *this*(-1);
}

double Poly::operator() (double p) const{
		double val = 0;
		for(map<int, double >::const_iterator iterator = poly.begin(); iterator != poly.end(); iterator++){
		val += pow(p, iterator->first) * iterator->second;
		}
	    return val;
}

ostream & operator << (ostream & s, const Poly & poly1){
	for(map<int, double >::const_iterator iterator = poly1.poly.begin(); iterator != poly1.poly.end();){
		if (iterator == poly1.poly.begin() && iterator->second < 0){
			cout << "- ";
		}
		if(iterator->second != 0){
			if ((iterator->second == 1 || iterator->second == -1) && iterator->first == 0){
				s << abs(iterator->second);
			}
			if (iterator->second != 1 && iterator->second != -1){
				s << abs(iterator->second);
			}
			if (iterator->first == 1){
				s << "x";
			}
			else if (iterator->first > 1){
				s << "x^" << iterator->first;
			}
		}
		if (++iterator != poly1.poly.end()){
			if (iterator->second > 0){
				s << " + ";
			}
			else if (iterator->second < 0){
				s << " - ";
			}
		}
	}
	return s;
}

void Poly::deleteZeroCoeffs(){
	for(map<int, double >::iterator iterator = poly.begin(); iterator != poly.end();){
		if(iterator->second == 0){
			iterator = poly.erase(iterator);
		}
		else {
			iterator++;
		}
	}
}
