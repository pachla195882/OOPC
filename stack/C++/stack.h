#ifndef STACK_H
#define STACK_H

class Stack{
	private:
		int top;
		int * tab;
	public:
		Stack();
		~Stack();
		void push(int value);
		int pop();
		bool isEmpty();
};


#endif
