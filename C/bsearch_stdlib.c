#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int ar[100];
int comp(const void *n,const void *nums);
int main(){
    int n,i,nm;
    int *in;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&ar[i]);
    }
    printf("Enter the num to search: ");
    scanf("%d",&nm);
    in = (int*) bsearch(&nm,ar,n,sizeof(nm),comp);
    if(in){
        printf("%d is in array\n",*in);
    }
    else{
        printf("%d is not in array\n",nm);
    }
    return 0;
}
int comp(const void *n,const void *nums){
    return *(int *) n - *(int *) nums;
}
