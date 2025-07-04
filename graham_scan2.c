/***********************************************************************************
**********************
Developed by: 
Yuan Miguel A. Panlilio, 12413135
Nigel Henry S. So, 12413801
************************************************************************************
*********************/

#include <stdio.h>
#include <time.h>
#include "sort.h"
#include "helperFunc.h"
#include "stack.h"

/*Function that finds the convex hull of a polygon using a merge sorting algorithm.
    @param points[] - the array of coordinates inputted.
    @param size - the number of coordinates inputted.
    @param s - the stack where the convex hull will be contained.*/

void grahamScan(point points[], int size, Stack*s) {
	clock_t start; // start time 
  	clock_t end;   // end time
  	start = clock();  // record the start time
	int orig_size = size; 
	point anchorPoint = findAnchorPoint(points, size); //finds the anchor point of the inputted points.
	point topElem;
	point nextToTopElem;
	create(s);
	int index = getIndex(points, size, anchorPoint);
	point temp = points[index];
	points[index] = points[0];
	points[0] = temp; //assigns the first point of the array as the anchor point.
	mergeSort(points, anchorPoint, 0, size - 1); //sorts the points according to their polar angle with the anchor point.
	//Ensures that the anchor point is the first element of the array
	push(s, points[0]);
	push(s, points[1]); //push the first two points to the stack.
	
	for(int i=2; i<size; i++) {
		topElem = top(s);
		nextToTopElem = nextToTop(s);
		if(isClockwise(nextToTopElem, topElem, points[i])==1 && i>=2) { //checks if three points make a clockwise turn or not
			i--;
			pop(s); //pops the top element if clockwise
			moveToLeft(points, &size, i); //deletes points[i] to move on to the next coordinate to be checked
			i--;
		}
		else {
			push(s, points[i]); //if counter-clockwise, pushes the coordinate to the stack.		
		}
	}
	
	end = clock();  // record the end time

  // prints the input size n and the corresponding elapsed execution time in ms (millisecond)
  printf("Input Size: %d\nElapsed Execution Time (in ms): %lf\n", orig_size, (double)(end - start));  
}
