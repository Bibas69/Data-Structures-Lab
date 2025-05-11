#include<stdio.h>

int binarysearch(int arr[],int size, int target);
int sorting(int arr[],int n);

int main(){
    int arr[10];
    int target;
    int n;

    printf("Enter no of elements \n");
    scanf("%d",&n);

    printf("Enter all elements \n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    sorting(arr,n);
    printf("Sorted elements\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

    printf("Enter a target or search a element");
    scanf("%d",&target);

    int result = binarysearch(arr,n,target);

    if(result==-1){
        printf("Element not found\n");
    }else{
        printf("Element found at %d ",result);
    }

}

int binarysearch(int arr[],int size, int target){
int end = size-1;
int start = 0;
while(start<end){
    int mid = (start+end)/2;
    if(arr[mid]==target){
        return mid;
    }else if(arr[mid]>target){
        end = mid-1;
    }else if(arr[mid]<target){
        start = mid+1;
    }

}
return -1;

}

int sorting(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){                   //for sorting
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}