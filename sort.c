/***********************************************************************************
**********************
Developed by: 
Yuan Miguel A. Panlilio, 12413135
Nigel Henry S. So, 12413801
************************************************************************************
*********************/

#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/* A selection sorting algorithm that sorts an array of points by comparing which of the coordinates have the lower angle relative to the anchor point.
    @param points - an array containing all of the points.
    @param size - the number of points inputted.*/

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
			if(computeAngle(points[min], anchorPoint) > computeAngle(points[j], anchorPoint)) { //checks if the angle of the minimum value is greater than the angle of a coordinate to its right.
				min = j;
			}
			else if(computeAngle(points[min], anchorPoint) == computeAngle(points[j], anchorPoint)) {
				if(getDistance(anchorPoint, points[min]) > getDistance(anchorPoint, points[j])) //if the angles are equal, checks which one is farther from the anchor point.
				min = j;
			}
		}
		point temp = points[i]; //a swap would be noticeable if minimum value is not equal to i.
		points[i] = points[min];
		points[min] = temp;
	}
	
}

/*Function that sorts that sorts an array of points by comparing which of the coordinates have the lower angle relative to the anchor point.
    @param points - an array containing all of the points.
    @param nAncPoint - the lowest x y coordinate in the array.
    @param low - lowest index of the sub-array.
    @param mid - middle index of the sub-array.
    @param high - highest index of the sub-array.*/

void merge(point coords[], point nAncPoint, int low, int mid, int high) {
    int nLowerMax = mid - low + 1;
    int nHigherMax = high - mid;
    int i, j, k;

    point* leftArr = malloc(nLowerMax * sizeof(point)); //allocates the needed space for the lower sub-array
    point* rightArr = malloc(nHigherMax * sizeof(point)); //allocates the needed space for the greater sub-array

    for (i = 0; i < nLowerMax; i++) {
        leftArr[i] = coords[low + i]; //gets all of the value from the unsorted lower half of the array of coordinates.
    }

    for (j = 0; j < nHigherMax; j++) {
        rightArr[j] = coords[mid + 1 + j]; //gets all of the value from the unsorted top half of the array of coordinates.
    }

    for (i = 0, j = 0, k = low; i < nLowerMax && j < nHigherMax; k++) {
        if (computeAngle(leftArr[i], nAncPoint) < computeAngle(rightArr[j], nAncPoint)) {
            	coords[k] = leftArr[i]; //the main coordinates array gets a point from the lower array if its angle is less than the top half of the array.
            	i++;
        }    
        else if(computeAngle(leftArr[i], nAncPoint) == computeAngle(rightArr[j], nAncPoint)) {
				if(getDistance(nAncPoint, leftArr[i]) <= getDistance(nAncPoint, rightArr[j])) { //if the angles are equals, compares the distance from the anchor point instead.
					coords[k] = leftArr[i];
            		i++;
				} else {
					coords[k] = rightArr[j];
            		j++;
				}
					
        } else {
            coords[k] = rightArr[j]; //the main coordinates array gets a point from the greater array if its angle is less than the lower half of the array
            j++;
        }
    }

    while (i < nLowerMax) {
        coords[k++] = leftArr[i++]; //gets the remaining leftover coordinates from the lower array if there is any
    }

    while (j < nHigherMax) {
        coords[k++] = rightArr[j++]; //gets the remaining leftover coordinates from the top array if there is any
    }

    free(leftArr);
    free(rightArr); //frees the unused memory spaces
}


    /*Function that sorts the points of a sub-array according to their polar angles relative to the anchor point.
    @param points - an array containing all of the points.
    @param nAncPoint - the lowest x y coordinate in the array.
    @param low - lowest index of the sub-array.
    @param mid - middle index of the sub-array.
    @param high - highest index of the sub-array.*/

void mergeSort(point points[], point nAncPoint, int low, int high) {
    if (low < high) {
        mergeSort(points, nAncPoint, low, low + (high - low) / 2); //divides the lower half of an array.
        mergeSort(points, nAncPoint, low + (high - low) / 2 + 1, high); //divides the higher half of an array.
        merge(points, nAncPoint, low, low + (high - low) / 2, high); //merges the two arrays together.
    }
}
