#include <stdio.h>
#include "stack.h"
void create(Stack *s) {
	s->top = -1;
}

int isFull(Stack *s) {
	if(s->top == (sizeof(s->points)/16) - 1)
		return 1;
	else
		return 0;
	
}

int isEmpty(Stack *s) {
	if(s->top == -1)
		return 1;
	else
		return 0;
}

void push(Stack *s, point elem) {
	if(isFull(s) == 0) {
		s->top++;
		s->points[s->top] = elem;
	}
}

point pop(Stack *s) {
	point elem;
	if(isEmpty(s) == 0) {
		elem = s->points[s->top];
		s->top--;
	}
	return elem;
}

point top(Stack *s) {
	point elem;
	if(isEmpty(s) == 0) {
		elem = s->points[s->top];
	}
	return elem;
}

point nextToTop(Stack *s) {
	point elem;
	if(s->top >= 1) {
		elem = s->points[s->top - 1];
	}		
	return elem;
}
