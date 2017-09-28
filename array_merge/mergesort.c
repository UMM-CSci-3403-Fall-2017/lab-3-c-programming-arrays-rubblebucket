#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "mergesort.h"
void mergeRanges(int values[], int start, int mid, int end){
        int size = end - start;
        int *destination;
        destination = (int*) calloc(size, sizeof(int));
        int first = start;
        int second = mid;
        int copy = 0;

        while(first < mid && second < end){
                if(values[first] < values[second]){
                        destination[copy] = values[first];
                        first = first + 1;
                } else {
                        destination[copy] = values[second];
                        second = second + 1;
                }
                copy = copy + 1;
        }

        while(first < mid){
                destination[copy] = values[first];
                copy = copy + 1;
                first = first + 1;
        }

        while(second < end){
                destination[copy] = values[second];
                copy = copy + 1;
                second = second + 1;
        }

        int i;
        for(i = 0; i < size; ++i){
                values[i + start] = destination[i];
        }

	free(destination);
}

void mergesortRange(int values[], int start, int end){
	int rangeSize = end - start;
	
	if(rangeSize > 1){
		int midPoint = (start + end) / 2;
		mergesortRange(values, start, midPoint);
		mergesortRange(values, midPoint, end);
		mergeRanges(values, start, midPoint, end);
	}
}

void mergesort(int size, int values[]){
	mergesortRange(values, 0, size);
}

