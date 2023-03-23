#include<stdio.h>
int main(){
    int sz;
    scanf("%d",&sz);
    int arr[sz];
    for(int i=0;i<sz;i++){
        scanf("%d",&arr[i]);
    }
    printf("The array is:");
    for(int i=0;i<sz;i++){
        printf("\t%d",arr[i]);
    }
}
