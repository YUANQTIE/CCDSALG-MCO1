#include "mFunc.h"

 /*Function that determines the anchor point in an array of points.
    @param points - an array containing all of the points.
    @param arrSize- number of points.
    @return the anchor point*/

coordinates findAnchorPoint(coordinates points[], int size) {
	coordinates min = points[0];
	for(int i=1; i< size-1; i++) {
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

double computeAngle(coordinates relativePoint, coordinates anchorPoint){
    return atan2(relativePoint.y - anchorPoint.y, relativePoint.x - anchorPoint.x) * (180.0 / PI);
}

    /*Function that determines if two progressing coordinates are clockwise or counter-clockwise
    @param coord1 - an anchor point
    @param coord2- a point added to the stack that could be an anchor point.
    @param coord3- a that connects to coord2.
    @return -1 if clockwise and 1 if counter-clockwise.*/

int isClockwise(coordinates coord1, coordinates coord2, coordinates coord3) {
    int flag;
    double areaProduct = (coord2.x - coord1.x)*(coord3.y - coord1.y) - (coord2.y - coord1.y)*(coord3.x - coord1.x);
    if (areaProduct < 0){ //A negative area means that it turns clockwise/right
        flag = -1;
    }
    else
    {
        flag = 1; //Positive area means that it is counter-clockwise/left.
    }
    return flag;               
}

    /*Function that determines which of the two points are lower vertically on a Cartesian Graph.
    If both are the same y-value, compares the lower x-value instead.
    @param points - an array containing all of the points.
    @param low - lowest index of the sub-array.
    @param mid - middle index of the sub-array.
    @param high - highest index of the sub-array.*/

int isLowerCoordinate(coordinates point_1, coordinates point_2){
    int flag = 0;
    if (point_1.y < point_2.y) //checks vertically
    {
        flag = 1;
    }
    else if (point_1.y == point_2.y){
        if (point_1.x < point_2.x) //checks horizontally
        {
            flag = 1;
        }
    }
    return flag;
    
}
