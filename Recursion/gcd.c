#include<stdio.h>
int gcd(int,int);
int main(){
    int num1,num2,res;
    printf("\n Enter the two numbers: ");
    scanf("%d %d",&num1,&num2);
    if(num1<num2)
        res=gcd(num2,num1);
    else
        res=gcd(num1,num2);
    printf("\n GCD of %d and %d = %d",num1,num2,res);
    return 0;
}
int gcd(int x,int y){
    return (y == 0 ? x : gcd(y,x%y));
}
