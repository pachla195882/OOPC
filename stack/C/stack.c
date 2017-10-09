#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define INTSIZE 1


//ERROR HANDLING AND EXTENDING STACK
typedef struct{
	int top;
	int *tab;
} Stack;

void init(Stack* s) {
	s->top = 0;
	s->tab = malloc(INTSIZE*sizeof(int));
}
void destroy(Stack* s) {
	free(s->tab);
}
void push(Stack* s, int i) {
	if(s->top > 0){
		s->tab = realloc(s->tab, (s->top+1)*sizeof(int));
	}
	i = s->tab[s->top];
	s->top++;
}
int pop(Stack* s) {
	if(s->top == 0){
		printf("Stack is empty!\n");
		return -1;
	}else {	
		int value;
		value = s->top;
		s->tab = realloc(s->tab, (s->top-1)*sizeof(int));
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
	isEmpty(ptr);
	//pop(ptr);
	//pop(ptr);
	destroy(ptr);
	return 0;
}
