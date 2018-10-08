#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

void init(Stack* s) {
	s->top = 0;
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
	if(s->top > 0){
		s->tab = realloc(s->tab, (s->top+2) * sizeof(int));
	}
	i = s->tab[s->top];
	s->top++;
}
int pop(Stack* s) {
	if(s->top == 0){
		printf("Stack is empty!");
		abort();
	}else {
		int value;
		value = s->top;
		s->top--;
		return value;
	}
}
int isEmpty(Stack* s) {
	if(s->top == 0){
		return true;
	}
	else{
		return false;
	}
}
