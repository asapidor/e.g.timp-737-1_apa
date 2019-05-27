#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
int siftdown(int *arr, int root, int bottom){
 int max;
 int done=0;
 while((root*2<=bottom)&&(!done)){
     if(root*2==bottom)
       max=root*2;
     else if(arr[root*2]>arr[root*2+1])
       max=root*2;
     else
       max=root*2+1;
     if(arr[root]<arr[max]){
        int temp=arr[root];
        arr[root]=arr[max];
        arr[max]=temp;
        root=max;
     }
     else
       done=1;
 }
}
int sorting_function(int *arr,int arr_len){
 for(int i=(arr_len/2)-1;i>=0;i--){
     siftdown(arr,i,arr_len-1);
 }    
 for(int i=arr_len-1;i>=1;i--){
         int temp=arr[0];
         arr[0]=arr[i];
         arr[i]=temp;
         siftdown(arr,0,i-1);
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
   if(i==n-1){
     printf("%d\n",arr[i]);
   }else{
     printf("%d ",arr[i]);
   }
 }  
 free(arr);
 return 0;
}
