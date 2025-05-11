//merging two array:

#include <stdio.h>
int main(){
	int arr1[] = {1,2,3,4,5};
	int arr2[] = {6,7,8,9,10};
	
	int size1 = sizeof(arr1) / sizeof(arr1[0]);
	int size2 = sizeof(arr2) / sizeof(arr2[0]);
	
	int mergeSize = size1 + size2;
	int mergeArr[mergeSize];
	
	for(int i = 0; i<size1; i++){
		mergeArr[i] = arr1[i];
	}
	
	for(int i = 0; i<size2; i++){
		mergeArr[size1 + i] = arr2[i];
	}
	
	for(int i = 0; i<mergeSize; i++){
		printf("%d ", mergeArr[i]);
	}
	
}
