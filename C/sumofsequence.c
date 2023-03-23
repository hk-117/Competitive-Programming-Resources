#include<stdio.h>
int main(){
    int upto;
    printf("Enter the number :");
    scanf("%d",&upto);
    int sum=0;
    for(int i=1;i<=upto;i++){
        sum+=i;
    }
    printf("Total is=%d\n",sum);
}
