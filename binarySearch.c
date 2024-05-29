#include<stdio.h>
#include<stdlib.h>

int binarySearch(int arr[],int b, int e, int key){
    int l=b;
    int h=e;
    int mid=(l+h)/2;
    if(key==arr[mid])
        return mid;
    if(key < arr[mid] )
        return binarySearch(arr,l,mid-1,key);
    else
        return binarySearch(arr,mid+1,h,key);
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
    int res=binarySearch(arr,1,n,key);
    if(res==0)
        printf("\nElement not found");
    else
        printf("\nElement is at %d ",res);
}