#include<stdio.h>

int main(){
    int ar[10]={2,3,5,6,7,8};
    printf("Before insertion:");
    for(int i=0;i<10;i++)
        printf("%d\t",ar[i]);
    printf("\nEnter the number to be inserted:");
    int num;
    scanf("%d",&num);
    int pos;
    printf("Enter the pos (Less than 7) :");
    scanf("%d",&pos);
    int st=8;
    while(st>= pos){
        ar[st+1]=ar[st];
        st--;
    }
    ar[pos]= num;
    printf("After insertion:");
    for(int i=0;i<10;i++)
        printf("%d\t",ar[i]);
    printf("\n");
    return 0;
}
