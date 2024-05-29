#include<stdio.h>
#include<stdlib.h>

int binarySearch(int arr[],int n, int key){
    int l=1;
    int h=n;
    int mid=(l+h)/2;
    while(l<=h){
        if(key==arr[mid])
            return mid;
        if(key<arr[mid])
            h=mid-1;
        else
            l=mid+1;
    }
    return 0;
}
int main(){
    int n;
    printf("\nEnter the number of element : ");
    scanf("%d",&n);
    int arr[n];
    printf("\nEnter the element : ");
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
    }
    int key;
    printf("\nEnter the element which U want search : ");
    scanf("%d",&key);
    int res=binarySearch(arr, n, key);
    if(res==0)
        printf("\nElement not found");
    else
        printf("\nElement is at %d ",res);
}