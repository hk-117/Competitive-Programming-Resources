#include<stdio.h>
int main(){
    int sz;
    scanf("%d",&sz);
    int arr[sz];
    for(int i=0;i<sz;i++){
        scanf("%d",&arr[i]);
    }
    int mini=arr[0];
    printf("The smallest is:");
    for(int i=0;i<sz;i++){
        mini=mini<arr[i]?mini:arr[i];
    }
    printf("%d\n",mini);
}
