#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
int sorting_function(int *arr, int arr_len){
 int i,j,step;
 int tmp;
 for(step=arr_len/2;step>0;step/=2){
    for(i=step;i<arr_len;i++){
        tmp=arr[i];
        for(j=i;j>=step;j-=step){
            if(tmp<arr[j-step]){
               arr[j]=arr[j-step];
            }
            else{
               break; 
            }
        }     
        arr[j]=tmp;
    }
 }
return 0;
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
     if(i==n-1){
        printf("%d\n",arr[i]);
     }
     else{
        printf("%d ",arr[i]);
     }
 }
free(arr);   
return 0;
}
