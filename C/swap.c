#include<stdio.h>
int main(){
    int a,b,tmp;
    printf("Enter a and b:");
    scanf("%d %d",&a,&b);
    printf("Before swapping:");
    printf("a=%d\t b=%d\n",a,b);
    tmp=a;
    a=b;
    b=tmp;
    printf("After swapping:");
    printf("a=%d\t b=%d\n",a,b);
    return 0;
}
