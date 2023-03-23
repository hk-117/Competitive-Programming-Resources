#include<stdio.h>
#include<string.h>
#define mx 5000000
#define LSOne(S) (S&(-S))
int ft[mx+1],n=11;

int rsqOne(int b){
    int sum=0;
    for(;b;b-=LSOne(b))
        sum+=ft[b];
    return sum;
}

int rsqTwo(int a,int b){
    return rsqOne(b)-(a==1 ? 0 : rsqOne(a-1));
}

void adjust(int k,int v){
    for(;k<=n;k+=LSOne(k))
        ft[k]+=v;
}

int main(){
    int f[]={2,4,5,5,6,6,6,7,7,8,9},i,j;
    for(i=1;i<=11;i++){
        adjust(i,f[i-1]);
    }
    printf("%d\n",rsqTwo(1,2));
    printf("%d\n",rsqTwo(1,4));
    f[2]=0;
    adjust(2,0-4);
    printf("%d\n",rsqTwo(1,2));
    printf("%d\n",rsqTwo(1,4));
}
