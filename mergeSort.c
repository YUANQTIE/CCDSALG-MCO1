#include "stack.h"
#include "helperFunc.c" 
#include<stdio.h>

    /*Function that sorts that sorts an array of points by comparing which of the coordinates have the lower angle relative to the anchor point.
    @param points - an array containing all of the points.
    @param low - lowest index of the sub-array.
    @param mid - middle index of the sub-array.
    @param high - highest index of the sub-array.*/

void merge(point coords[], point nAncPoint, int low, int mid, int high) {
    int nLowerMax = mid - low + 1;
    int nHigherMax = high - mid;
    int i, j, k;

    point* leftArr = malloc(nLowerMax * sizeof(point));
    point* rightArr = malloc(nHigherMax * sizeof(point));

    for (i = 0; i < nLowerMax; i++) {
        leftArr[i] = coords[low + i];
    }

    for (j = 0; j < nHigherMax; j++) {
        rightArr[j] = coords[mid + 1 + j];
    }

    for (i = 0, j = 0, k = low; i < nLowerMax && j < nHigherMax; k++) {
        if (computeAngle(leftArr[i], nAncPoint) <= computeAngle(rightArr[j], nAncPoint)) {
            coords[k] = leftArr[i];
            i++;
        } else {
            coords[k] = rightArr[j];
            j++;
        }
    }

    while (i < nLowerMax) {
        coords[k++] = leftArr[i++];
    }

    while (j < nHigherMax) {
        coords[k++] = rightArr[j++];
    }

    free(leftArr);
    free(rightArr);
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
