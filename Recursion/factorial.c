#include<stdio.h>
int factorial(int);
int main(){
    int num,val;
    printf("\n Enter the number : ");
    scanf("%d",&num);
    val=factorial(num);
    printf("\n Factorial of %d = %d",num,val);
    return 0;
}
int factorial(int n){
    if(n==1)
        return 1;
    else
        return n*factorial(n-1);
}
