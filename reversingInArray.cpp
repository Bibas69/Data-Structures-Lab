//Reversring in array:
#include <stdio.h>
int main(){
	int arr[] = {1,2,3,4,5};
	int size = sizeof(arr) / sizeof(arr[0]);
	int reverse[size];
	for(int i = 0; i<size; i++){
		for(int j = size - 1; j>=0; j--){
			reverse[i] = arr[j - i];
			break;
		}
	}
	for(int i = 0; i<5;i++){
		printf("%d ", reverse[i]);
	}
	
}
