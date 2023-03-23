#include<bits/stdc++.h>
using namespace std;

int main(){
    int s=10;
    printf("Enter bit number to turn for(\"1010\"):");
    int bit;
    scanf("%d",&bit);
    s &= ~(1<<bit);
    printf("After Resetting %d\n",s);  
}
