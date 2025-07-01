#include <math.h>
#include <stdlib.h>
#include "stack.h"
#ifndef MFUNC_H
#define MFUNC_H
#define PI 3.1415
coordinates findAnchorPoint(coordinates points[], int size);
double computeAngle(coordinates relativePoint, coordinates anchorPoint);
double* getArrayOfAngles(coordinates points[], int arrSize, coordinates anchorPoint);
int isClockwise(coordinates coord1, coordinates coord2, coordinates coord3);

#endif
