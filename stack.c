/***********************************************************************************
**********************
Developed by: 
Yuan Miguel A. Panlilio, 12413135
Nigel Henry S. So, 12413801
************************************************************************************
*********************/

#include <stdio.h>
#include "stack.h"

 /*Function that creates a new stack.
    @param *s - the stack created*/

void create(Stack *s) {
	s->top = -1;
}

 /*Function that checks if a stack is full.
    @param *s - a stack.
    @return 0 if not full and 1 if full*/

int isFull(Stack *s) {
	int flag = 0;
	if(s->top == (sizeof(s->points)/16) - 1)
		flag = 1;
	
	return flag;
}

 /*Function that checks if a stack has not elements.
    @param *s - a stack.
    @return 1 if empty, 0 if not.*/

int isEmpty(Stack *s) {
	int flag = 0;
	if(s->top == -1)
		flag = 1;

	return flag;
}

 /*Function that adds an elements to the top of the stack.
    @param *s - a stack.
    @param elem - the point to be added to the stack.*/

void push(Stack *s, point elem) {
	if(isFull(s) == 0) {
		s->top++;
		s->points[s->top] = elem;
	}
}

 /*Function that removes the top element from the stack.
    @param *s - a stack.
    @return the top element of the stack.*/

point pop(Stack *s) {
	point elem;
	if(isEmpty(s) == 0) { //checks if an element is not empty first.
		elem = s->points[s->top];
		s->top--;
	}
	return elem;
}

 /*Function that shows the the topmost element of the stack.
    @param *s - a stack.
    @return the top element of the stack.*/

point top(Stack *s) {
	point elem;
	if(isEmpty(s) == 0) {
		elem = s->points[s->top];
	}
	return elem;
}

 /*Function that shows the the second topmost element of the stack.
    @param *s - a stack.
    @return the element next to the top element of the stack.*/

point nextToTop(Stack *s) {
	point elem;
	if(s->top >= 1) {
		elem = s->points[s->top - 1];
	}		
	return elem;
}
