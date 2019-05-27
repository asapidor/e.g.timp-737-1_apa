#include<stdio.h>
#include"math.h"
float sqr(float x,float y){
    return pow(x,y);
}
int main(){
    float a,b;
    scanf("%f",&a);
    scanf("%f",&b);
    printf("%f\n",sqr(a,b));
    return 0;
}
