#include "stack.h"
#include "helperFunc.c" 

    /*Function that sorts that sorts an array of points by comparing which of the coordinates have the lower angle relative to the anchor point.
    @param points - an array containing all of the points.
    @param low - lowest index of the sub-array.
    @param mid - middle index of the sub-array.
    @param high - highest index of the sub-array.*/

void merge(point coords[], point nAncPoint, int low, int mid, int high) {
    int i = 0, j = 0, k;
    // Variable i keeps track of the lower valued array's indices, while Variable j keeps track of the higher valued array's indices. Variable k keeps track of the sub-array's size.
    int nLowerMax = mid - low + 1;
    int nHigherMax = high - mid;
    point leftArr[nLowerMax], rightArr[nHigherMax];

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

void mergeSort(point points[], point nAncPoint, int low, int high) {
    if (low < high) {
        mergeSort(points, nAncPoint, low, low + (high - low) / 2); //divides the lower half of an array.
        mergeSort(points, nAncPoint, low + (high - low) / 2 + 1, high); //divides the higher half of an array.
        merge(points, nAncPoint, low, low + (high - low) / 2, high); //merges the two arrays together.
    }
}
