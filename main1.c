#include"graham_scan1.c"
#include<stdio.h>
int main() {
	int size = 0;
	int nPoints;
	int i;
	Stack s;
	char filename[20];
	point points[32768];
	point scannedPoints[32768];
	
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
			printf("Point #%d X: %lf\n", i+1, popped.x);
			printf("Point #%d Y: %lf\n", i+1, popped.y);
			size++;
		}
		for(int i=size-1; i>=0; i--) {
			fprintf(output, "%lf %lf\n", scannedPoints[i].x, scannedPoints[i].y);
		} 
		fclose(output);
	}	
	fclose(input);
}

