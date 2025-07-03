#include <stdio.h>
#include "selectionSort.h"

void selectionSort(point points[], int size) {
	point anchorPoint = findAnchorPoint(points, size);
	//Ensures that the anchor point is the first element of the array
	int index = getIndex(points, size, anchorPoint);
	point temp = points[index];
	points[index] = points[0];
	points[0] = temp;
	for(int i=1; i< size-1; i++) {
		int min = i;
		for(int j=i+1; j<size; j++) {
			if(computeAngle(points[min], anchorPoint) > computeAngle(points[j], anchorPoint)) {
				min = j;
			}
			else if(computeAngle(points[min], anchorPoint) == computeAngle(points[j], anchorPoint)) {
				if(getDistance(anchorPoint, points[min]) > getDistance(anchorPoint, points[j]))
					min = j;
			}
		}
		point temp = points[i];
		points[i] = points[min];
		points[min] = temp;
	}
	
}
