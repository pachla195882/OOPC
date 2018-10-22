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
	if(top == size){
		if(tab == NULL) {
			std::cout << "Allocating memory failed.";
			abort();
		}
		tab = (int*)realloc(tab, (top + 2) * sizeof(int));
		size += 2;
	}
	value = tab[top];
	top++;
	std::cout << "Pushed to the stack" << std::endl;
}
int Stack::pop() {
	if(top == 0) {
		std::cout << "Stack is empty!" << std::endl;
		abort();
	}
	int value;
	value = tab[top-1];
	top--;
	std::cout << "Popped from the stack" << std::endl;
	return value;

}
bool Stack::isEmpty() {
	if (top == 0){
		std::cout << "Stack is empty" << std::endl;
		return true;
	}
	else{
		std::cout << "Stack is not empty" << std::endl;
		return false;
	}
}
