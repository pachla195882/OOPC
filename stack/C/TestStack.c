#include "stack.h"

int main(){
	Stack s1, *ptr;
	ptr = &s1;
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
	destroy(ptr);
	return 0;
}
