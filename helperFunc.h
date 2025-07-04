/***********************************************************************************
**********************
Developed by: 
Yuan Miguel A. Panlilio, 12413135
Nigel Henry S. So, 12413801
************************************************************************************
*********************/

#ifndef HELPERFUNC_H
#define HELPERFUNC_H
#include "stack.h"
#define PI 3.1415
point findAnchorPoint(point points[], int size);
double computeAngle(point relativePoint, point anchorPoint);
int isClockwise(point coord1, point coord2, point coord3);
void moveToLeft(point points[], int *size, int index);
int getIndex(point points[], int size, point key);
double getDistance(point point1, point point2);

#endif
