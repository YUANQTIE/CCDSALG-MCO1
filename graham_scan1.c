#include <stdio.h>
#include <time.h>
#include "selectionSort.c"
#include "stack.c"
void grahamScan(point points[], int size, Stack*s) {
	clock_t start; // start time 
  	clock_t end;   // end time
  	start = clock();  // record the start time
	int orig_size = size; 
	point popped;
	create(s);
	selectionSort(points, size);
	for(int i=0; i<size; i++) {
		printf("X: %lf       Y: %lf\n", points[i].x, points[i].y);
	}
	printf("Anchor X: %lf       Y: %lf\n", points[0].x, points[0].y);
	push(s, points[0]);
	push(s, points[1]);
	for(int i=2; i<size; i++) {
		if(isClockwise(points[i-2], points[i-1], points[i])==1 && i>=2) {
			i--;
			popped = pop(s);
			moveToLeft(points, &size, i);
			i--;
		}
		else {
			push(s, points[i]);		
		}
	}
	end = clock();  // record the end time
  // prints the input size n and the corresponding elapsed execution time in ms (millisecond)
  printf("Input Size: %d\nElapsed Execution Time (in ms): %lf\n", orig_size, (double)(end - start));  
}




