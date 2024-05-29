#include<stdio.h>
#include<stdlib.h>

int insertionSort(int arr[],int n){
    for(int i=0;i<n;i++){
		int key=arr[i];
		int j=i-1;
		while(j>=0 && arr[j]>key){
			arr[j+1]=arr[j];
			j=j-1;
		}
		arr[j+1]=key;
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
    insertionSort(arr, n);
    for(int i=0;i<n;i++){
        printf("%d  ",arr[i]);
    }
}