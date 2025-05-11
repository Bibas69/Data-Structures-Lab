//Updation in array:
#include <stdio.h>
int main(){
	int arr[] = {1,3,3,4,5};
	
	int pos;
	printf("Enter the position which you want to update: \n");
	scanf("%d", &pos);
	int value;
	printf("\n Enter the updated value:");
	scanf("%d", &value);

     		if(pos>=0 || pos<5){
		    arr[pos - 1] = value;
	        }  
     	
	for(int i = 0; i<5; i++){
		printf("%d  ", arr[i]);
	}
}
