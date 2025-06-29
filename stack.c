#include <stdio.h>
#define MAX_SIZE 32768 // Maximum size of stack

typedef struct {
	double arr[MAX_SIZE];
	int top; // Index of top element
} Stack;

void create(Stack *s) {
	s->top = -1;
}

void push(Stack *s, double elem) {
	if(s->top < MAX_SIZE-1) {
		s->top++;
		s->arr[s->top] = elem;
	}
	else
		printf("Overflow error.");
}

double pop(Stack *s) {
	double elem;
	if(s->top >= 0) {
		elem = s->arr[s->top];
		s->top--;
	}
	else
		elem = -999;
		

	return elem;
}

double top(Stack *s) {
	double elem;
	if(s->top >= 0) {
		elem = s->arr[s->top];
	}
	else
		elem = -999;
		
	
	return elem;
}

int isFull(Stack *s) {
	if(s->top == (sizeof(s->arr)/8) - 1)
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

double nextToTop(Stack *s) {
	double elem;
	if(s->top >= 1) {
		elem = s->arr[s->top - 1];
	}
	else
		elem = -999;
		
	
	return elem;
}

int main() {
	Stack s;
	create(&s); 
	push(&s, 100);
	push(&s, 500);
	push(&s, 600);
	double elem = top(&s);
	double elem1 = nextToTop(&s);
	for(int i=s.top; i>-1; i--){
		printf("%lf", s.arr[i]);
		printf("\n");
	}
	
	printf("Elem: %lf", elem);
	printf("\nNext to top: %f", elem1);
	printf("\nIs Full: %d", isFull(&s));
	printf("\nIs Empty: %d", isEmpty(&s));
}
