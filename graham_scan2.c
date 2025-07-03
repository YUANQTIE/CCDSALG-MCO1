#include <stdio.h>
#include <time.h>
#include "mergeSort.c"
#include "stack.c"
void grahamScan(point points[], int size, Stack*s) {
	clock_t start; // start time 
  	clock_t end;   // end time
  	start = clock();  // record the start time
	int orig_size = size; 
	point anchorPoint = findAnchorPoint(points, size);
	create(s);
	int index = getIndex(points, size, anchorPoint);
	point temp = points[index];
	points[index] = points[0];
	points[0] = temp;
	mergeSort(points, anchorPoint, 0, size - 1);
	//Ensures that the anchor point is the first element of the array
	push(s, points[0]);
	push(s, points[1]);
	
	for(int i=2; i<size; i++) {
		if(isClockwise(points[i-2], points[i-1], points[i])==1 && i>= 2) {
			i--;
			pop(s);
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
