//Deletion in array:
#include <stdio.h>
int main(){
	int arr[5] = {1,2,3,4,5};
	int pos;
	printf("Enter the position you want to delete:\n");
	scanf("%d", &pos);
	
	for(int i = 0; i<5; i++){
		if(i == pos -1){
			for(int j = i; j<5; j++){
				arr[j] = arr[j+1];
			}
		}
	}
	for(int i = 0; i<4; i++){
		printf("%d  ", arr[i]);
	}
	
}
