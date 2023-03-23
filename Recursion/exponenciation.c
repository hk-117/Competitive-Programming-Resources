#include<stdio.h>
int expo(int,int);
int main(){
    int num1,num2,res;
    printf("\n Enter the two numbers : ");
    scanf("%d %d",&num1,&num2);
    res=expo(num1,num2);
    printf("RESULT = %d",res);
    return 0;
}
int expo(int x,int y){
    if(y==0)
        return 1;
    else
        return x*expo(x,y-1);
}
