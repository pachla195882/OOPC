#include "complex.h"

using namespace std;

int main() {
	Complex a(0.0,15),b(0,13),c;
	c = 10;
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	c = -a;
	cout << c <<endl;  
	c = a + b;
	c = c - Complex(10);
	cout << c <<endl;  
	c = 10 - a;
	(c -=b) -=10;
	cout << c <<endl;
	c + 10;
	5*c;
	cout <<  c << endl;
	return 0;
}
