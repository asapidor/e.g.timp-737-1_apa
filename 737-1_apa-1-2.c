#include <stdio.h>
int sum(int x,int y){
    return(x+y);
}
int main(){
    int a,b;
    scanf("%d",&a);
    scanf("%d",&b);
    printf("%d\n",sum(a,b));
    return 0;
}
