#include<bits/stdc++.h>
using namespace std;

int main(){
    int s=42;
    int j;
    printf("Enter the position:");
    scanf("%d",&j);
    if((s & 1<<j) !=0){
        printf("%d bit is on\n",j);
    }
}
