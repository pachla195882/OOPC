#include <iostream>
#include "list.h"
using namespace std;

void PrintList(List toPrint, ostream & Out){

	int nextValue;
	Out << "Printing list contents: " << endl;
	toPrint.goToHead();
	if (!toPrint.moreData()){
		Out << "List is empty" << endl;
		return;
    }
	while (toPrint.moreData()){
		nextValue = toPrint.getCurrentData();
		Out << nextValue << " ";
		toPrint.advance();
	}
	Out << endl;
}

int main(){
	
	List l1, l2, l3, l4, l5, l6, l7, l8;
	cout << "When we have more nodes" << endl;
	for (int i = 0; i < 3; i++)
		l1.insert(i);
	PrintList(l1, cout);
	for (int i = 4; i < 10; i++)
		l2.insert(i);
	PrintList(l2, cout);
	cout << "Assigning l2 to l1" << endl;
	l2 = l1;
	PrintList(l2, cout);
	cout << endl;
	
	cout << "When we have equal no. of nodes" << endl;
	for (int i = 0; i < 5; i++)
		l3.insert(i);
	PrintList(l3, cout);
	for (int i = 5; i< 10; i++)
		l4.insert(i);
	PrintList(l4, cout);
	cout << "Assigning l4 to l3" << endl;
	l4 = l3;
	PrintList(l4, cout);
	cout << endl;
	
	cout << "When we have less nodes" << endl;
	for (int i = 1; i < 10; i++)
		l5.insert(i);
	PrintList(l5, cout);
	for (int i = 1; i < 20; i++)
		l6.insert(i);
	PrintList(l6, cout);
	cout << "Assigning l6 to l5" << endl;
	l6 = l5;
	PrintList(l6, cout);
	cout << endl;
	
	cout << "When list is empty" << endl;
	for (int i = 1; i < 10; i++)
		l7.insert(i);
	PrintList(l7, cout);
	PrintList(l8, cout);
	cout << "Assigning l7 to l8" << endl;
	l8 = l7;
	PrintList(l8, cout);
	cout << endl;
	
	
}
