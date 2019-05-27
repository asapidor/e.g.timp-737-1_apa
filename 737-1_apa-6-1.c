#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
int sorting_function(int *arr, int arr_len){
 int tmp,k;
 int s = arr_len;
 int cnt = 0;
 while(s>=1){
    for(int i=0;i+s<arr_len;i++){
        if(arr[i]>arr[i+s]){
           tmp=arr[i];
           arr[i]=arr[i+s];
           arr[i+s]=tmp;
        }
    }
    s/=1.247;
 }
}
  

int main(){
 int n,i;
 scanf("%d",&n);
 int *arr;
 arr=(int*)malloc(n*sizeof(int));
 for(i=0;i<n;i++){
    scanf("%d",&arr[i]);
 }
 sorting_function(arr,n);
 for(i=0;i<n;i++){
    if(i == n-1){
       printf("%d\n",arr[i]);
    }
    else{
    printf("%d ",arr[i]);
    }
 }
 return 0;
}
