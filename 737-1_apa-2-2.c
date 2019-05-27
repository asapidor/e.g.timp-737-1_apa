#include <stdio.h>
#include "math.h"
int main(){
 int n,x,s1=0,s2=0,a;
 for(int i=1;i<=n;i++){
     scanf("%d",&x);
     if(x%2==0){
        s1=s1+pow(x,3);
     }
     if(x%2!=0){
        s2=s2+pow(x,3);
     }
 }
 a=s2-s1;
 printf("%d",&a);
 return 0;
}

