#include "stack.h"
#include <stdlib.h>

Stack::Stack(){
    top=0;
	size = 1;
	tab=(int*)malloc(size*sizeof(int));
}
Stack::~Stack(){
    free(tab);
}
void Stack::push(int value){
	if(top>0){
		tab=(int*)realloc(tab,(size+1)*sizeof(int));
	}
	value=tab[top];
	top++;
}
int Stack::pop(){
	return 0;

}
bool Stack::isEmpty(){
    if (top == 0)
	return true;
    else return false;
}