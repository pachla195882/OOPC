#ifndef STACK_H
#define STACK_H

class Stack{
	private:
		int top;
		int * tab;
		int size;
	public:
		Stack();
		~Stack();
		void push(int value);
		int pop();
		bool isEmpty();
};


#endif
