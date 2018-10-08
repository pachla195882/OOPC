typedef struct{
	int top;
	int *tab;
} Stack;

void init(Stack* s);
void destroy(Stack* s);
void push(Stack* s, int i);
int pop(Stack* s);
int isEmpty(Stack* s);
