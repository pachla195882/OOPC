#include <iostream>
#include "list.h"
using namespace std;

List::List(){
	head = NULL;
	current = NULL;
}

List::~List(){
	while (head){
		node *t = head->next;
		delete head;
		head = t;
    };
}

void List::insert(int a){
	node *t = new node;
	t->next = head;
	head = t;
	head->val = a;
}

void List::goToHead()
{
	current = head;
}

int List::getCurrentData(){
	return current->val;
}

void List::advance(){
	current = current->next;
}

bool List::moreData(){
	if (current)
		return true;
	else
		return false;
}

List::List(const List & l){
	current = NULL;
	node *src, **dst;
	head = NULL;
	src = l.head;
	dst = &head;
	while (src){
		*dst = new node;
		(*dst)->val = src->val;
		(*dst)->next = NULL;
		if(src == l.current)
		current =* dst;
		src = src->next;
		dst = &((*dst)->next);
	}
}
// DO NOT DELETE UNNECESSARILY NODES at while(head)
/*
List & List::operator=(const List & l){
	if (&l == this)
		return *this;
	current=NULL;
	while (head){
		node *t =	head->next;
		delete head;
		head = t;
	};
	node *src, **dst; // default constructor step#1 and #2
	head = NULL;
	src = l.head; // source pointer set to the first node of the list
	dst = &head;
	while (src){ // terminates after last node is copied
		*dst = new node;
		(*dst)->val = src->val; // copying the value from the source node
		(*dst)->next = NULL;
		if(src==l.current)
			current=*dst; // setting current so that it points to the same node
		src = src->next; // src pointer incrementation
		dst = &((*dst)->next); // dst pointer incrementation
    }
	return *this;
}
* */

List & List::operator =(const List & l){
	if (&l == this)
		return *this;

	current = nullptr;
	node *src, **dst;
	src = l.head;
	dst = &head;

	while (src) {
		if (!(*dst)) {
			*dst = new node;
			(*dst)->next = nullptr;
		}
		(*dst)->val = src->val;
		if(src == l.current)
			current = *dst;
		src = src->next;
		dst = &((*dst)->next);
	}
	while (*dst) {
		node *rem = (*dst)->next;
		delete *dst;
		*dst = rem;
	}

	return *this;
}
