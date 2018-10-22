#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void init(Stack* s) {
	s->top = 0;
	s->size = 1;
	s->tab = malloc(sizeof(int));
	if(s->tab == NULL) {
		printf("Allocating memory failed.");
		abort();
	}
}
void destroy(Stack* s) {
	free(s->tab);
}
void push(Stack* s, int i) {
	if(s->top == s->size){
		if(s->tab == NULL) {
			printf("Allocating memory failed.");
			abort();
		}
		s->tab = realloc(s->tab, (s->top+2) * sizeof(int));
		s->size += 2;
	}
	i = s->tab[s->top];
	s->top++;
	printf("Pushed to the stack\n");
}
int pop(Stack* s) {
	if(s->top == 0){
		printf("Stack is empty!");
		abort();
	}else {
		int value;
		value = s->top;
		s->top--;
		printf("Popped from the stack\n");
		return value;
	}
}
bool isEmpty(Stack* s) {
	if(s->top == 0){
		printf("Stack is empty\n");
		return true;
	}
	else{
		printf("Stack is not empty\n");
		return false;
	}
}
