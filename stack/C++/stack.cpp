#include "stack.h"
#include <stdlib.h>
#include <iostream>

Stack::Stack() {
	top = 0;
	size = 1;
	tab = (int*)malloc(size*sizeof(int));
	if(tab == NULL) {
		std::cout << "Allocating memory failed.";
		abort();
	}
}
Stack::~Stack() {
	free(tab);
}
void Stack::push(int value) {
	if(top > 0){
		tab = (int*)realloc(tab, (top + 2) * sizeof(int));
	}
	value = tab[top];
	top++;
}
int Stack::pop() {
	if(top == 0) {
		std::cout << "Stack is empty!";
		abort();
	}
	int value;
	value = tab[top-1];
	top--;
	return value;

}
bool Stack::isEmpty() {
	if (top == 0)
		return true;
	else return false;
}
