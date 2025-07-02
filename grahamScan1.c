#include <stdio.h>
#include <time.h>
#include "selectionSort.c"
#include "stack.c"
#define STEP  (1024)
#define LIMIT (32768)
void grahamScan(point points[], int size, Stack*s) {
	clock_t the_start; // start time 
  	clock_t the_end;   // end time
  	the_start = clock();  // record the start time
	int orig_size = size; 
	create(s);
	selectionSort(points, size);
	push(s, points[0]);
	push(s, points[1]);
	for(int i=2; i<size; i++) {
		if(isClockwise(points[i-2], points[i-1], points[i])==1) {
			i--;
			pop(s);
			moveToLeft(points, &size, i);
			i--;
		}
		else {
			push(s, points[i]);
		}
	}
	the_end = clock();  // record the end time

  // prints the input size n and the corresponding elapsed execution time in ms (millisecond)
  printf("Input Size: %d\nElapsed Execution Time (in ms): %lf\n", orig_size, (double)(the_end - the_start));  
}




