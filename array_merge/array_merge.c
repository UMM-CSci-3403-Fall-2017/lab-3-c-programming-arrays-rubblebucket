#include <stdio.h>
#include <stdlib.h>

#include "array_merge.h"
#include "mergesort.h"

bool checkInSet(int* set, int x){
	for(int i = 1; i <= set[0]; ++i){
		if(x == set[i]){
			return true;
		}
	}
	return false;
}


int* array_merge(int num_arrays, int* sizes, int** values){
	int newSize = 0;
	for(int i = 0; i < num_arrays; ++i){
		newSize = newSize + sizes[i];
	}

	int* set;
	set = (int*) calloc(newSize, sizeof(int));

	set[0] = 0;

	for(int j = 0; j < num_arrays; ++j){
		for (int k = 0; k < sizes[j]; ++k){
			if(!checkInSet(set, values[j][k])){
				set[set[0] + 1] = values[j][k];
				set[0] = set[0] + 1;
			}
		}
	}
	set = (int*) realloc(set, sizeof(int) * (set[0]+1));
	mergesort(set[0], &set[1]);
	return set;
}
