#include "stack.h"

Stack::Stack(){
    top=0;
	sizes=2;
    stack = new int [sizes];

}
Stack::~Stack(){
    delete [] stack;
}
void Stack::push(int value){
    int * stack_temp;
    if (top == sizes){
	sizes = 2*sizes;
	stack_temp = new int [sizes];
	for(int i=0; i<top; i++){
	    stack_temp[i] = stack[i];
	}
    }
    else{
	stack_temp= new int [1];
    }
    stack_temp[top] = value;
    top++;
    if(stack)
	delete [] stack;
    stack = stack_temp;
}
int Stack::pop(void){
    int value;
    value = stack[top-1];
    top--;
    return value;
}
bool Stack::empty(void){
    if (top == 0)
	return true;
    else
	return false;
}
int Stack::size(void){
    return top;
}
int Stack::top_element(void){
    return stack[top-1];
}
