#include<stdio.h>
#include<stdlib.h>

int selectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
		int min=i;
		for(int j=i+1;j<n;j++){
			if(arr[j]<arr[min])
				min=j;
			int temp=arr[i];
			arr[i]=arr[min];
			arr[min]=temp;
		}
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
    selectionSort(arr, n);
    for(int i=0;i<n;i++){
        printf("%d  ",arr[i]);
    }
}