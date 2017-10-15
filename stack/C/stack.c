#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
	int top;
	int *tab;
} Stack;

void init(Stack* s) {
	s->top = 0;
	s->tab = malloc(sizeof(int));
	if(s->tab == NULL) {
		printf("Allocating memory failed.");
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
		printf("Stack is empty!\n");
		return 0;
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

int main() {
	Stack s1, *ptr;
	ptr=&s1;
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
