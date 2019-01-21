#include "matrix.h"
#include "errors.h"

#include <iostream>

using namespace std;

int main() {
	try{
		Matrix m1, m2, m3, m4;
		cin >> m2;
		m1 = m2;
		m3 = m2;
		
		cout << "m2 matrix: " << m2 << endl;
		

		try{
			cout << "m2(2,3): " << m2(2,3) << endl << endl;
		} catch (NoSuchElement& e) {
			cerr << e.what() << endl << endl;
		}
		
		m2(2,1) = 3;
		
		m4 = m2;
		m4 += m1;
		
		cout << "The sum of m1 and m2 equals: " << m1 + m2 << endl;
		
		cout << "The same value has m4: " << m4 << endl;
		
		m4 *= m1;
		
		cout <<" m4 multiplied by m1: " << m4 << endl;
		
	} catch(exception& e) {
		cerr << e.what() << endl;
		abort();
	} 
	return 0;
}
