#include<stdio.h>
#include<stdlib.h>
int partition(int arr[],int low,int high){
	int pivot = arr[low];
	int k=high;
	for(int i=high;i>low;i--){
		if(arr[i]>pivot){
			int temp = arr[i];
			arr[i] = arr[k];
			arr[k] = temp;
			k--;
		}
	}
	int temp=arr[k];
	arr[k] = arr[low];
	arr[low] = temp;
	
	return k;	
}

void quickSort(int arr[],int low,int high){
    if(low<high){
		int res=partition(arr,low,high);
		quickSort(arr,low,res-1);
		quickSort(arr,res+1,high);
	}
}
int main(){
    int n;
    printf("\nEnter the number of element : ");
    scanf("%d",&n);
    int arr[n];
    printf("\nEnter the element : ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    quickSort(arr, 0, n-1);
    for(int i=0;i<n;i++){
        printf("%d  ",arr[i]);
    }
}