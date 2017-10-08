#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define INTSIZE 1

struct Stack{
	int top;
	int *tab;
};

void init(struct Stack* s){
	s->top=0;
	s->tab=(int*)malloc(INTSIZE*sizeof(int));
}
void destroy(struct Stack* s){
	free(s->tab);
}
void push(struct Stack* s, int i){
	if(s->top>0){
		s->tab = realloc(s->tab, (s->top+1)*sizeof(int));
	}
	i=s->tab[s->top];
	s->top++;
}
int pop(struct Stack* s){
	if(s->top==0){
		printf("Stack is empty!");
		return -1;
	}else{	
		int value;
		value=s->top;
		s->tab=realloc(s->tab, (s->top-1)*sizeof(int));
		s->top--;
		return value;
	}
}
int isEmpty(struct Stack* s){
	if(s->top==0){
		return true;
	}
	else{
		return false;
	}
}

int main(){
	struct Stack s1, *ptr;
	ptr=&s1;
	init(ptr);
	push(ptr,1);
	push(ptr,12);
	pop(ptr);
	pop(ptr);
	destroy(ptr);
	return 0;
}
