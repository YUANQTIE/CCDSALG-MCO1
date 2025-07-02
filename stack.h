#ifndef STACK_H
#define STACK_H
#define MAX_SIZE 32768 // Maximum size of stack
typedef struct{
    double x;
    double y;
}point;

typedef struct{
	point points[MAX_SIZE];
	int top; // Index of top element
}Stack;

void create(Stack *s);
int isFull(Stack *s);
int isEmpty(Stack *s);
void push(Stack *s, point elem);
point pop(Stack *s);
point top(Stack *s);
point nextToTop(Stack *s);

#endif
