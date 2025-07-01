#ifndef STACK_H
#define STACK_H
#define MAX_SIZE 32768 // Maximum size of stack
typedef struct{
    double x;
    double y;
}coordinates;

typedef struct{
	coordinates cords[MAX_SIZE];
	int top; // Index of top element
}Stack;

void create(Stack *s);
int isFull(Stack *s);
int isEmpty(Stack *s);
void push(Stack *s, coordinates elem);
coordinates pop(Stack *s);
coordinates top(Stack *s);
coordinates nextToTop(Stack *s);

#endif
