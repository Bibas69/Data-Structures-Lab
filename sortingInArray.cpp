//Sorting in array:
#include <stdio.h>
int main(){
	int arr[5] = {1,7,3,6,4};
	int temp;
	for(int i = 0; i<5; i++){
		for(int j = 0; j<4; j++){
			if(arr[j] > arr[j + 1]){
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
		
	}
	printf("Ascending order: \n");
	for(int i = 0; i<5; i++){
		printf("%d  ", arr[i]);
	}
}
