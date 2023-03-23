#include<bits/stdc++.h>
using namespace std;

int main(){
    int s=40;
    printf("Enter the bit number to flip:");
    int bit;
    scanf("%d",&bit);
    s^=(1<<bit);
    printf("After flipping :%d\n",s);
}
