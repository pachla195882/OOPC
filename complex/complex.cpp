#include "complex.h"
#include <iostream>

Complex::Complex() {
	Real = 0;
	Imag = 0;
}

Complex::Complex(double co){
	Real = co;
	Imag = 0;
}

Complex::Complex(double Real, double Imag) {
	this->Real = Real;
	this->Imag = Imag;
}

Complex& Complex::operator= (const Complex & co) {
	Real = co.Real;
	Imag = co.Imag;
	return *this;
}

Complex& Complex::operator= (double co) {
	Real = co;
	Imag = 0;
	return *this;
}

Complex Complex::operator+ (Complex co) const{
	Complex c;
	c.Real = this->Real + co.Real;
	c.Imag = this->Imag + co.Imag;
	return c;
}

Complex Complex::operator- () const{
	return Complex(-Real, -Imag);
}


Complex Complex::operator* (Complex co) const{
	Complex c;
	c.Real = Real * co.Real - Imag * co.Imag;
	c.Imag = Real * co.Imag + co.Real * Imag;
	return c; 
}

Complex Complex::operator/ (Complex co) const{
	Complex c;
	c.Real = (Real*co.Real+Imag*co.Imag)/(co.Imag*co.Imag+co.Real*co.Real);
	c.Imag = (Imag*co.Real-Real*co.Imag)/(co.Imag*co.Imag+co.Real*co.Real);
	return c;
}

Complex& Complex::operator-= (Complex co){
	Real -= co.Real;
	Imag -= co.Imag;
	return *this;
}

Complex& Complex::operator+= (Complex co){
	Real += co.Real;
	Imag += co.Imag;
	return *this;
}

Complex& Complex::operator*= (Complex co){
	Real *= co.Real;
	Imag *= co.Real;
	return *this;
}

Complex& Complex::operator/= (Complex co){
	Real /= co.Real;
	Imag /= co.Imag;
	return *this;
}

bool Complex::operator== (const Complex & co){
	return this->Real == co.Real && this->Imag == co.Imag;
}

ostream& operator<< (ostream & s, const Complex & co){
	s << "(" << co.Real << ", i" << co.Imag << ")";
    return s;
}

double Complex::realPart(){
	return Real;
}

double Complex::imaginaryPart(){
	return Imag;
}

double Complex::amplitude(){
	return sqrt(Real*Real+Imag*Imag);
}
double Complex::phase(){
	if(Real>0){
		return atan(Imag/Real);
	}
    else if(Real<0 && Imag>=0){
        return atan(Imag/Real)+M_PI;
    }
    else if(Real<0 && Imag<0){
        return atan(Imag/Real)-M_PI;
    }
    else if(Real==0 && Imag>0){
        return M_PI/2;
    }
    else if(Real==0 && Imag<0){
        return -M_PI/2;
    }
    else if(Real==0 && Imag==0){
        cout<<"Indeterminate"<<endl;
        return 0;
    }
    else return 0;
 }

Complex Complex::conjugate(){
	Complex c(Real,-Imag);
	return c;
}

