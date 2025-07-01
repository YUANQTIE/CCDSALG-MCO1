#include "stack.c"
#include "mFunc.c"

    /*Function that sorts that sorts an array of points by comparing which of the coordinates have the lower y value or the lower x value.
    @param points - an array containing all of the points.
    @param low - lowest index of the sub-array.
    @param mid - middle index of the sub-array.
    @param high - highest index of the sub-array.*/

void mergePoints(coordinates coords[], int low, int mid, int high) {
    int i = 0, j = 0, k;
    // Variable i keeps track of the lower valued array's indices, while Variable j keeps track of the higher valued array's indices. Variable k keeps track of the sub-array's size.
    int nLowerMax = mid - low + 1;
    int nHigherMax = high - mid;
    coordinates leftArr[nLowerMax], rightArr[nHigherMax];

    while (i < nLowerMax)
    {
        leftArr[i] = coords[low + i]; //copies the values of the lower half of the array.
        i++;
    }

    while (j < nHigherMax)
    {
        rightArr[j] = coords[mid + 1 + j]; //copies the values of the higher half of the array.
        j++;
    }

    for (i = 0, j = 0, k = low; i < nLowerMax && j < nHigherMax; k++)
    {
        if (isLowerCoordinate(leftArr[i], rightArr[j])) { //compares which of the coordinates have the lower y value. If y is equal, compares the x value instead.
            coords[k] = leftArr[i]; //the original sub-array gets the value of the lower valued coordinate first.
            i++;
        }
        else {
            coords[k] = rightArr[j];
            j++;
        }
    }

    while (i < nLowerMax) //fills out the rest of the coordinates if the higher array has been filled. 
    {
        coords[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < nHigherMax) //fills out the rest of the coordinates if the lower array has been filled. 
    {
        coords[k] = rightArr[j]; 
        j++;
        k++;
    }
}

    /*Function that sorts the points of a sub-array according to their positions on a Cartesian graph.
    @param points - an array containing all of the points.
    @param low - lowest index of the sub-array.
    @param mid - middle index of the sub-array.
    @param high - highest index of the sub-array.*/

void mergeSortPoints(coordinates coords[], int low, int high) {
    if (low < high) {
        mergeSortPoints(coords, low, low + (high - low) / 2); //divides the lower half of an array.
        mergeSortPoints(coords, low + (high - low) / 2 + 1, high); //divides the higher half of an array.
        mergePoints(coords, low, low + (high - low) / 2, high); //merges the two arrays together.
    }
}

    /*Function that sorts that sorts an array of points by comparing which of the coordinates have the lower angle relative to the anchor point.
    @param points - an array containing all of the points.
    @param low - lowest index of the sub-array.
    @param mid - middle index of the sub-array.
    @param high - highest index of the sub-array.*/

void mergeAngles(coordinates coords[], coordinates nAncPoint, int low, int mid, int high) {
    int i = 0, j = 0, k;
    // Variable i keeps track of the lower valued array's indices, while Variable j keeps track of the higher valued array's indices. Variable k keeps track of the sub-array's size.
    int nLowerMax = mid - low + 1;
    int nHigherMax = high - mid;
    coordinates leftArr[nLowerMax], rightArr[nHigherMax];

    while (i < nLowerMax)
    {
        leftArr[i] = coords[low + i]; //copies the values of the lower half of the array.
        i++;
    }

    while (j < nHigherMax)
    {
        rightArr[j] = coords[mid + 1 + j]; //copies the values of the higher half of the array.
        j++;
    }

    for (i = 0, j = 0, k = low; i < nLowerMax && j < nHigherMax; k++)
    {
        if (computeAngle(leftArr[i], nAncPoint) <= computeAngle(rightArr[j], nAncPoint)) { //compares which of the coordinates have the lower polar angle relative to the anchor point.
            coords[k] = leftArr[i]; //the original sub-array gets the value of the lower valued coordinate first.
            i++;
        }
        else {
            coords[k] = rightArr[j];
            j++;
        }
    }

    while (i < nLowerMax) //fills out the rest of the coordinates if the higher array has been filled. 
    {
        coords[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < nHigherMax) //fills out the rest of the coordinates if the lower array has been filled. 
    {
        coords[k] = rightArr[j]; 
        j++;
        k++;
    }
}

    /*Function that sorts the points of a sub-array according to their polar angles relative to the anchor point.
    @param points - an array containing all of the points.
    @param low - lowest index of the sub-array.
    @param mid - middle index of the sub-array.
    @param high - highest index of the sub-array.*/

void mergeSortAngles(coordinates coords[], coordinates nAncPoint, int low, int high) {
    if (low < high) {
        mergeSortAngles(coords, nAncPoint, low, low + (high - low) / 2); //divides the lower half of an array.
        mergeSortAngles(coords, nAncPoint, low + (high - low) / 2 + 1, high); //divides the higher half of an array.
        mergeAngles(coords, nAncPoint, low, low + (high - low) / 2, high); //merges the two arrays together.
    }
}
