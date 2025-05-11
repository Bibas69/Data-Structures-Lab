//Matrix multiplication
#include <stdio.h>
int main(){
	int matrix1[3][3];
	int matrix2[3][3];
	int result[3][3];
	printf("Enter the elements of matrix1: \n");
	for(int i = 0; i<3; i++){
		for(int j = 0; j<3; j++){
			scanf("%d", &matrix1[i][j]);
		}
	}
		printf("Enter the elements of matrix2: \n");
	for(int i = 0; i<3; i++){
		for(int j = 0; j<3; j++){
			scanf("%d", &matrix2[i][j]);
		}
	}
	
	for(int i = 0; i<3; i++){
		for(int j = 0; j<3; j++){
			result[i][j] = 0;
			
			for(int k = 0; k<3; k++){
				result[i][j] = result[i][j] + (matrix1[i][k] * matrix2[k][j]);
			}
		}
	}
	for(int i = 0; i<3; i++){
		for(int j = 0; j<3; j++){
			printf("%d ", result[i][j]);
			if(j == 2){
				printf("\n");
			}
		}
		
	}
}
