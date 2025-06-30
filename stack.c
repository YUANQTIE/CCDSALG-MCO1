#include <stdio.h>
#define MAX_SIZE 3 // Maximum size of stack
typedef struct {
    double x;
    double y;
} coordinates;

typedef struct {
	coordinates cords[MAX_SIZE];
	int top; // Index of top element
} Stack;


void create(Stack *s) {
	s->top = -1;
}

int isFull(Stack *s) {
	if(s->top == (sizeof(s->cords)/16) - 1)
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

void push(Stack *s, coordinates elem) {
	if(isFull(s) == 0) {
		s->top++;
		s->cords[s->top] = elem;
	}
	else
		printf("Overflow error.");
}

coordinates pop(Stack *s) {
	coordinates elem;
	if(isEmpty(s) == 0) {
		elem = s->cords[s->top];
		s->top--;
	}
	else
		printf("Underflow error.");
		

	return elem;
}

coordinates top(Stack *s) {
	coordinates elem;
	if(isEmpty(s) == 0) {
		elem = s->cords[s->top];
	}
	else
		printf("Empty Stack.");
		
	
	return elem;
}

coordinates nextToTop(Stack *s) {
	coordinates elem;
	if(s->top >= 1) {
		elem = s->cords[s->top - 1];
	}
	else
		printf("Stack only contains one elem.");
		
	
	return elem;
}

int main() {
	Stack s;
	coordinates c;
	coordinates d;
	coordinates e;
	c.x = 100;
	c.y = 100;
	d.x = 200;
	d.y = 200;
	e.x = 300;
	e.y = 300;
	create(&s); 
	push(&s, c);
	push(&s, d);
	push(&s, e);
	coordinates elem = top(&s);
	coordinates elem1 = nextToTop(&s);
	for(int i=s.top; i>-1; i--){
		printf("x = %lf      y = %lf", s.cords[i].x, s.cords[i].y);
		printf("\n");
	}
	
	printf("Top X = %lf         Top Y = %lf", elem.x, elem.y);
	printf("\nNext to top X: %lf         Y: %lf", elem1.x, elem1.y);
	printf("\nIs Full: %d", isFull(&s));
	printf("\nIs Empty: %d", isEmpty(&s));
}
