#include "stack.h"

int main(){
	Stack s1, *ptr;
	ptr = &s1;
	Stack s2, *ptr2;
	ptr2 = &s2;
	init(ptr);
	push(ptr,1);
	push(ptr,12);
	push(ptr,18);
	push(ptr,15);
	isEmpty(ptr);
	pop(ptr);
	pop(ptr);
	pop(ptr);
	pop(ptr);
	isEmpty(ptr);
	destroy(ptr);
	init(ptr2);
	push(ptr2,11);
	push(ptr2,122);
	push(ptr2,1);
	isEmpty(ptr2);
	pop(ptr2);
	pop(ptr2);
	pop(ptr2);
	isEmpty(ptr2);
	destroy(ptr2);
	return 0;
}
