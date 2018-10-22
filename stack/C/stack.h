#include <stdbool.h>

typedef struct{
	int top;
	int size;
	int *tab;
} Stack;

void init(Stack* s);
void destroy(Stack* s);
void push(Stack* s, int i);
int pop(Stack* s);
bool isEmpty(Stack* s);
