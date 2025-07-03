#ifndef SORT_H
#define SORT_H
#include "stack.h"
#include "helperFunc.h"
void selectionSort(point points[], int size);
void merge(point coords[], point nAncPoint, int low, int mid, int high);
void mergeSort(point points[], point nAncPoint, int low, int high);

#endif
