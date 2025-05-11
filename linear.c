#include<stdio.h>

int main(){
    int num,key;
    int arr[10];
    printf("Enter a number of elements\n");
    scanf("%d",&num);

    

    printf("Enter elements\n");
    for(int i=0;i<num;i++){
        scanf("%d",&arr[i]);
    }
    
    printf("Enter element for search\n");
    scanf("%d",&key);

    printf("searching ..\n");
    for(int i=0;i<num;i++){
        if(arr[i]==key){
            printf("%d found\n",arr[i]);
        }
    }
} 