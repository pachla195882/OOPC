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
	
	List l;
	l.insert(1);
	l.insert(2);
	l.insert(3);
	PrintList(l, cout);
	List l2;
	l2=l;
	PrintList(l2,cout);
}
