#include"graham_scan1.h"
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
	if(input == NULL) {
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
		grahamScan(points, nPoints, &s);
		for(int i=0; isEmpty(&s) == 0; i++) {
			point popped = pop(&s);
			scannedPoints[i].x = popped.x;
			scannedPoints[i].y = popped.y;
			size++;
		}
		fprintf(output, "%d\n", size);
		for(int i=size-1; i>=0; i--) {
			fprintf(output, "%lf %lf\n", scannedPoints[i].x, scannedPoints[i].y);
		} 
		fclose(output);
	}	
	fclose(input);
}

