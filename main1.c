/***********************************************************************************
**********************
Developed by: 
Yuan Miguel A. Panlilio, 12413135
Nigel Henry S. So, 12413801
************************************************************************************
*********************/

#include "graham_scan1.c"
#include "stack.h"
#include "sort.h"
#include "helperFunc.h"
#include<stdio.h>

int main() {
	int size = 0;
	int nPoints;
	int i;
	Stack s;
	char filename[20];
	point points[MAX_SIZE];
	point scannedPoints[MAX_SIZE];
	
	printf("Input the name of the input file: ");
	scanf("%s", filename);
	
	FILE *input = fopen(filename, "r");
	if(input == NULL) { //checks if the file exists
		printf("No file found. \n");
	}
	else {
		i=0;
		fscanf(input, "%d", &nPoints);
		while(fscanf(input, "%lf %lf", &points[i].x, &points[i].y) == 2 && i<nPoints) {
			i++;
		}
		
		printf("Input the name of the output file: ");
		scanf("%s", filename);
	
		FILE *output = fopen(filename, "w");
		grahamScan(points, nPoints, &s); //implements the graham scan algorithm.
		for(int i=0; isEmpty(&s) == 0; i++) {
			point popped = pop(&s);
			scannedPoints[i].x = popped.x;
			scannedPoints[i].y = popped.y; //stores the points of the stack in another array.
			size++;
		}
		fprintf(output, "%d\n", size);
		for(int i=size-1; i>=0; i--) {
			fprintf(output, "%lf %lf\n", scannedPoints[i].x, scannedPoints[i].y); //prints out the scanned points in order starting with the anchor point.
		} 
		fclose(output);
	}	
	fclose(input);
}

