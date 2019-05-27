#include<stdlib.h>
#include<malloc.h>
#include<stdio.h>
int sorting_function(int *arr,int first,int last){
 if(first<last){
    int left=first, right=last,middle=arr[(left+right)/2];
    do{
       while(arr[left]<middle){left++;}
       while(arr[right]>middle){right--;}
       if(left<=right){
          int tmp=arr[left];
          arr[left]=arr[right];
          arr[right]=tmp;
          left++;
          right--;
       }
     }while(left<=right);
 sorting_function(arr,first,right);
 sorting_function(arr,left,last);
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
 sorting_function(arr,0,n-1);
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
