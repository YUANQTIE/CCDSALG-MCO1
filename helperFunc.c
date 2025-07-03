#include <math.h>
#include <stdlib.h>
#include "helperFunc.h"

 
 /*Function that determines the anchor point in an array of points.
    @param points - an array containing all of the points.
    @param arrSize- number of points.
    @return the anchor point*/

point findAnchorPoint(point points[], int size) {
	point min = points[0];
	for(int i=1; i< size; i++) {
		if(min.y > points[i].y)
			min = points[i];
		else if(min.y == points[i].y)
			if(min.x > points[i].x)
				min = points[i];
	}
	
	return min;
}

    /*Function that computes for the angle between the an anchor point and a relative point.
    @param relativePoint - a point on the points array that will get its angle with the anchor point.
    @param anchorPoint - the lowest x y values within the points array.
    @return the angle computed*/

double computeAngle(point relativePoint, point anchorPoint){
    return atan2(relativePoint.y - anchorPoint.y, relativePoint.x - anchorPoint.x);
}

    /*Function that determines if two progressing coordinates are clockwise or counter-clockwise
    @param coord1 - an anchor point
    @param coord2- a point added to the stack that could be an anchor point.
    @param coord3- a that connects to coord2.
    @return -1 if clockwise and 1 if counter-clockwise.*/

int isClockwise(point coord1, point coord2, point coord3) {
    int flag;
    double areaProduct = (coord2.x - coord1.x)*(coord3.y - coord1.y) - (coord2.y - coord1.y)*(coord3.x - coord1.x);
    if (areaProduct <= 0){ //A negative area means that it turns clockwise/right
        flag = 1;
    }
    else
    {
        flag = -1; //Positive area means that it is counter-clockwise/left.
    }
    return flag;               
}

void moveToLeft(point points[], int* size, int index) {
	for(int i=index; i<(*size); i++) {
		points[i] = points[i+1];
	}
	*size = *size-1;
}

int getIndex(point points[], int size, point key) {
	for(int i=0; i<size; i++) {
		if(points[i].x == key.x && points[i].y == key.y)
			return i;
	}
	return -1;
}

double getDistance(point point1, point point2) {
	double distance = sqrt(pow((point2.x-point1.x), 2) + pow((point2.y-point1.y), 2));
	return distance;
}
