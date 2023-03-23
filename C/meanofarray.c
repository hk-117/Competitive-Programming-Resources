#include<stdio.h>
int main(){
    int sz;
    scanf("%d",&sz);
    int arr[sz],sum=0;
    for(int i=0;i<sz;i++){
        scanf("%d",&arr[i]);
        sum+=arr[i];
    }
    printf("The array is:");
    for(int i=0;i<sz;i++){
        printf("\t%d",arr[i]);
    }
    printf("\nSum is:%d\n",sum);
    printf("Mean is:%f\n",(float)sum/(float)sz);
}
