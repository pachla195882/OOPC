#include "stack.h"

int main(){
	Stack A;
	A.push(1);
	A.push(2);
	A.push(3);
	A.push(4);
	A.push(5);
	A.isEmpty();
	A.pop();
	A.pop();
	A.pop();
	A.pop();
	A.pop();
	A.isEmpty();
	Stack B;
	B.push(1);
	B.push(2);
	B.push(3);
	B.push(4);
	B.push(5);
	B.isEmpty();
	B.pop();
	B.pop();
	B.pop();
	B.pop();
	B.pop();
	B.isEmpty();
}
