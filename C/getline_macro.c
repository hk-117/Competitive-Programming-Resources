#include<stdio.h>
#include<string.h>
#define line(l,i) while((l[i++]=getchar())!='\n');l[i]='\0'
int main(){
    char l[100];
    int n=0;
    line(l,n);
    puts(l);
    return 0;
}
